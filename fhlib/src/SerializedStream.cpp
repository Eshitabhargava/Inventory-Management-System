#ifndef __SERIALIZED_STREAM_CPP
#define __SERIALIZED_STREAM_CPP 1

#include <SerializedStream.h>

using namespace ObjectIO;

SerializedStream& SerializedStream::operator=(const SerializedStream &other)
{
this->size=other.size;
this->base=other.base;
return *this;
}

SerializedStream::~SerializedStream()
{
//
}

SerializedStream::SerializedStream(const char* base,unsigned int size)
{
this->base=base;
this->size=size;
}

SerializedStream::SerializedStream(const SerializedStream &other)
{
this->size=other.size;
this->base=other.base;
}

unsigned int SerializedStream::getSize()
{
return this->size;
}

const char* SerializedStream::getBase()
{
return this->base;
}

#endif