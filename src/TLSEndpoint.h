#ifndef TLS_ENDPOINT_H_
#define TLS_ENDPOINT_H_
#include <libcpp/libcpp.h>
#include <libstream/libstream.h>
#include <libioevent/libioevent.h>

#include <tls.h>

EXTERN_C_BEGIN
namespaceBegin(foxintango)

class foxintangoAPI TLSEndpoint :public IOEndpoint
{
public:
    TLSEndpoint();
    virtual ~TLSEndpoint();
public:
    tls* context;
public:
    virtual IOEndpointStatus boot();
    virtual IOEndpointStatus stop();
    virtual IOEndpointStatus status();
    virtual int getSocket() const;
public:
    virtual int listen();
    virtual int accept();
    virtual int connect();/********************/
    virtual int send(char* buffer, const unsigned int& length);
    virtual int read(char* buffer, const unsigned int& length);
    virtual unsigned int readable();
};
namespaceEnd
EXTERN_C_END
#endif
