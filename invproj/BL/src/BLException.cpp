#ifndef __BLException_cpp
#define __BLException_cpp 1

#include <bl\BLException.h>
#include<bl\bl.h>
#include<iostream>

using namespace std;
using namespace inventory_bl;

BLException::BLException()
{
//do nothing
}

BLException::BLException(const BLException &other)
{
this->exceptions=other.exceptions;
}

BLException::~BLException() throw()
{
//do nothing
}

BLException& BLException::operator=(const BLException &other)
{
this->exceptions=other.exceptions;
return *this;
}

const char* BLException::what() const throw()
{
return NULL;
}

void BLException::addException(__$__BL_ENUMERATION property,string msg)
{
this->exceptions.insert(pair<__$__BL_ENUMERATION,string>(property,msg));
}

string BLException::getException(__$__BL_ENUMERATION property)
{
map<__$__BL_ENUMERATION,string>::iterator iter=this->exceptions.find(property);
if(iter!=this->exceptions.end()) return (*iter).second;
return string("");
}

bool BLException::hasException(__$__BL_ENUMERATION property)
{
map<__$__BL_ENUMERATION,string>::iterator iter=this->exceptions.find(property);
if(iter!=this->exceptions.end()) return true;
return false;
}

bool BLException::hasExceptions()
{
if(this->exceptions.size()>0) return true;
return false;
}

int BLException::size()
{
return this->exceptions.size();
}

map<__$__BL_ENUMERATION,string> BLException::getExceptions()
{
return this->exceptions;
}

string BLException::getGenericException()
{
return this->getException(GENERIC_EXCEPTION);
}

void BLException::setGenericException(string msg)
{
this->addException(GENERIC_EXCEPTION,msg);
}

#endif