#include "engine.h"
#include "TLSEndpoint.h"
#include "TLSStream.h"
using namespace foxintango;
#include <iostream>
#include <tls.h>

namespaceBegin(foxintango)
class io_event_tls_engine_implement {
public:
    io_event_tls_engine_implement(){}
    ~io_event_tls_engine_implement(){}
public: 
    char* ca_strore_path;
    char* cert_file_path;
    char* key_file_path;
};
namespaceEnd
io_event_tls_engine::io_event_tls_engine() {
    this->implement = new io_event_tls_engine_implement();
}

io_event_tls_engine::~io_event_tls_engine() {

}

struct tls_versions {
    char* client;
    char* server;
};

static struct tls_versions tls_versions_instance[] = {
    {"tlsv1.3", "all"},
    {"tlsv1.2", "all"},
    {"tlsv1.1", "all"},
    {"tlsv1.0", "all"},
    {"all", "tlsv1.3"},
    {"all", "tlsv1.2"},
    {"all", "tlsv1.1"},
    {"all", "tlsv1.0"},
    {"tlsv1.3", "tlsv1.3"},
    {"tlsv1.2", "tlsv1.2"},
    {"tlsv1.1", "tlsv1.1"},
    {"tlsv1.0", "tlsv1.0"},
};

TLSEndpoint* io_event_tls_engine::createEndpoint(const IOEndpoint& endpoint){
    int socket = endpoint.getSocket();
    TLSEndpoint* tls_endpoint = new TLSEndpoint();
    char* ciphers = "default";//tls_config.c tls_config_set_ciphers
    struct tls_config* client_cfg, * server_cfg;
    struct tls* client;
    int failure = 0;
    uint32_t protocols;
    if ((tls_endpoint->context = tls_server()) == NULL)
        std::cout << "server create filed." << std::endl;

    if ((server_cfg = tls_config_new()) == NULL)
        std::cout << "failed to create tls server config" << std::endl;
    if (tls_config_parse_protocols(&protocols, tls_versions_instance[4].server) == -1)
        std::cout << "failed to parse protocols: %s" << tls_config_error(server_cfg) << std::endl;
    if (tls_config_set_protocols(server_cfg, protocols) == -1)
        std::cout << "failed to set protocols: %s" << tls_config_error(server_cfg) << std::endl;
    if (tls_config_set_ciphers(server_cfg, ciphers) == -1)
        std::cout << "failed to set ciphers: %s" << tls_config_error(server_cfg) << std::endl;
    if (tls_config_set_keypair_file(server_cfg, this->implement->cert_file_path, this->implement->key_file_path) == -1)
        std::cout << "failed to set keypair: %s" << tls_config_error(server_cfg) << std::endl;
    if (tls_config_set_ca_path(server_cfg,this->implement->ca_strore_path)){
        std::cout << "failed to set ca path: %s" << tls_config_error(server_cfg) << std::endl;
    }
    /*
    if (tls_config_set_ca_file(server_cfg, cafile) == -1)
        std::cout << "failed to set ca: %s" << tls_config_error(client_cfg) << std::endl;
    */
    if (tls_configure(tls_endpoint->context, server_cfg) == -1)
        std::cout << "failed to configure server: %s" << tls_error(tls_endpoint->context) << std::endl;
    tls_config_free(server_cfg);
    tls_accept_socket(tls_endpoint->context, &client, socket);
    return tls_endpoint;
}