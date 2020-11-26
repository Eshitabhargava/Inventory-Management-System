#ifndef __DLException_h
#define __DLException_h 1

#include<iostream>

using namespace std;

namespace inventory_dl
{
class DLException:public exception
{
private:
string message;

public:
DLException();
DLException(string message);
DLException(const DLException &other);
virtual ~DLException() throw();
DLException& operator=(const DLException &other);
virtual const char* what() const throw(); 
void setMessage(string message);
string getMessage();
};
}

#endif