#include "TLSStream.h"
using namespace foxintango;

TLSStream::TLSStream(){}
TLSStream::~TLSStream(){}

bool TLSStream::readable(){

    return false;
}

int TLSStream::read(const char* buffer, const unsigned int& size) { return 0; }
int TLSStream::write(const char* buffer, const unsigned int& size) { return 0; }