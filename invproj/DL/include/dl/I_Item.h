#ifndef __I_Item_h_inventory_dl
#define __I_Item_h_inventory_dl 1

#include<iostream>
#include <Serializable.h>

using namespace std;
using namespace ObjectIO;

namespace inventory_dl
{
class I_Item:public Serializable
{
public:
virtual void setCode(int code)=0;
virtual int getCode()=0;
virtual void setName(string name)=0;
virtual string getName()=0;
virtual void setCategory(char category)=0;
virtual char getCategory()=0;
};
}

#endif