#ifndef __IndexOutOfBoundsException_cpp
#define __IndexOutOfBoundsException_cpp

#include<IndexOutOfBoundsException>

using namespace exceptions;

IndexOutOfBoundsException::IndexOutOfBoundsException()
{
//
}

IndexOutOfBoundsException::IndexOutOfBoundsException(string message)
{
this->message=message;
}

IndexOutOfBoundsException::IndexOutOfBoundsException(const IndexOutOfBoundsException &other)
{
this->message=other.message;
}

IndexOutOfBoundsException::~IndexOutOfBoundsException() throw()
{
//do nothing
}

IndexOutOfBoundsException& IndexOutOfBoundsException::operator=(const IndexOutOfBoundsException &other)
{
this->message=other.message;
}

void IndexOutOfBoundsException::setMessage(string message)
{
this->message=message;
}

string IndexOutOfBoundsException::getMessage()
{
return this->message;
}

const char* IndexOutOfBoundsException::what() const throw() 
{
return this->message.c_str();
}

#endif