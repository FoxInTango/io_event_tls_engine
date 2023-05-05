#include <libioevent/libioevent.h>
#include <libmodule/libmodule.h>
#include <libcpp/libcpp.h>

EXTERN_C_BEGIN
namespaceBegin(foxintango)
class TLSStream;
class io_event_tls_engine_implement;
class foxintangoAPI io_event_tls_engine {
private:
    io_event_tls_engine_implement* implement;
public:
    io_event_tls_engine();
    ~io_event_tls_engine();
public:
    virtual TLSStream* createStream(int socket);
};
namespaceEnd
EXTERN_C_END
