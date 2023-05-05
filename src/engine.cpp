#include "engine.h"
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
};
namespaceEnd
io_event_tls_engine::io_event_tls_engine() {
    this->implement = new io_event_tls_engine_implement();
}

io_event_tls_engine::~io_event_tls_engine() {

}

TLSStream* io_event_tls_engine::createStream(int socket){

}