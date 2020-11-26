#ifndef __DLException_cpp
#define __DLException_cpp 1

#include <dl\DLException.h>
#include<iostream>

using namespace std;
using namespace inventory_dl;

DLException::DLException()
{
message="";
}

DLException::DLException(string message)
{
this->message=message;
}

DLException::DLException(const DLException &other)
{
this->message=other.message;
}

DLException::~DLException() throw()
{
//do nothing
}

DLException& DLException::operator=(const DLException &other)
{
this->message=other.message;
return *this;
}

const char* DLException::what() const throw()
{
return this->message.c_str();
}

void DLException::setMessage(string message)
{
this->message=message;
}

string DLException::getMessage()
{
return this->message;
}

#endif