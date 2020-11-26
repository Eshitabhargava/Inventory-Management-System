#ifndef __I_Item_h_inventory_bl
#define __I_Item_h_inventory_bl 1

#include<iostream>
#include<bl\bl.h>

using namespace std;
using namespace inventory_bl;

namespace inventory_bl
{
class I_Item
{
private:
virtual const char* get_name()=0;

public:
virtual void setCode(int code)=0;
virtual int getCode()=0;
virtual void setName(string name)=0;
virtual string& getName()=0;
virtual void setCategory(__$__BL_ENUMERATION category)=0;
virtual string getCategory()=0;
friend class ItemManager;
};
}
#endif