#ifndef __BLException_h_inventory_bl
#define __BLException_h_inventory_bl 1

#include<iostream>
#include<map>
#include<utility>
#include<bl\bl.h>

using namespace std;

namespace inventory_bl
{
class BLException:public exception
{
private:
map<__$__BL_ENUMERATION,string> exceptions;

public:

BLException();
BLException(const BLException &other);

virtual ~BLException() throw();

BLException& operator=(const BLException &other);

virtual const char* what() const throw(); 

void addException(__$__BL_ENUMERATION property,string msg);
string getException(__$__BL_ENUMERATION property);
bool hasException(__$__BL_ENUMERATION Property);
bool hasExceptions();
int size();
map<__$__BL_ENUMERATION,string> getExceptions();
string getGenericException();
void setGenericException(string msg);
};
}

#endif