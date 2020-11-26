#ifndef __Item_h_inventory_bl
#define __Item_h_inventory_bl 1

#include <bl\I_Item.h>
#include<bl\bl.h>
#include<iostream>

using namespace std;

namespace inventory_bl 
{
class Item:public I_Item 
{
private:
int code;
string name;
string category;
const char* get_name();

public:
Item();
Item(int code,string name,__$__BL_ENUMERATION category);
Item(const Item &other);

virtual ~Item();

Item & operator=(const Item &other);

void setCode(int code);
int getCode();

void setName(string name);
string& getName();

void setCategory(__$__BL_ENUMERATION category);
string getCategory();

friend class ItemManager;
}; 
}

#endif