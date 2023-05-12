#include "module.h"
#include "engine.h"
using namespace foxintango;
#include <string.h>

io_event_tls_engine_Interface::io_event_tls_engine_Interface(){
}

io_event_tls_engine_Interface::~io_event_tls_engine_Interface(){
}

bool io_event_tls_engine_Interface::containClass(const char* name) {
    if(0 == strcmp(name,"IOEngineLWS")) return true;
    return false;
}

void* io_event_tls_engine_Interface::createObject(const char* name,const Model& model){
    return 0;
}

bool io_event_tls_engine_Interface::containFunction(const char* name) {
    return false;
}

void* io_event_tls_engine_Interface::exportFunction(const char* name) {
    return 0;
}

bool io_event_tls_engine_Interface::containVariable(const char* name){
    return false;
}

void* io_event_tls_engine_Interface::exportVariable(const char* name) {
    return 0;
}

io_event_tls_engine_Interface foxintangoAPI MODULE_INTERFACE_INSTANCE;

