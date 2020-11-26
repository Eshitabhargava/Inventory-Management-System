#ifndef __Item_cpp
#define __Item_cpp 1

#include<bl\I_Item.h>
#include<bl\Item.h>
#include<bl\bl.h>
#include<string.h>

using namespace inventory_bl;

const char* Item::get_name()
{
return name.c_str();
}

Item::Item() 
{
this->code=0;
this->name=""; 
this->category="";
}

Item::Item(int code,string name,__$__BL_ENUMERATION category)
{
this->code=code;
this->name=name; 
if(category==CONSUMABLE) this->category="Consumable";
else if(category==FINISHED_GOOD) this->category="Finished Good";
else if(category==RAW_MATERIAL) this->category="Raw Material";
}

Item::Item(const Item &other) 
{
this->code=other.code;
this->name=other.name; 
this->category=other.category;
}

Item::~Item() 
{
// do nothing 
}

Item & Item::operator=(const Item &other) 
{
this->code=other.code;
this->name=other.name;
this->category=other.category;
return *this; 
}

void Item::setCode(int code) 
{
this->code=code; 
}

int Item::getCode() 
{
return this->code; 
}

void Item::setName(string name) 
{
this->name=name; 
}

string& Item::getName() 
{
return this->name; 
}

void Item::setCategory(__$__BL_ENUMERATION category)
{
if(category==CONSUMABLE) this->category="Consumable";
else if(category==FINISHED_GOOD) this->category="Finished Good";
else if(category==RAW_MATERIAL) this->category="Raw Material";
}

string Item::getCategory()
{
return this->category; 
}

#endif