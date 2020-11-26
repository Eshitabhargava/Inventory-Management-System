#ifndef __Item_h_inventory_dl
#define __Item_h_inventory_dl 1

#include <DL\I_Item.h>
#include<iostream>

using namespace std;

namespace inventory_dl 
{
class Item:public I_Item 
{
private:
int code;
string name;
char category;

public:

Item();
Item(int code,string name,char category);
Item(const Item &other);

virtual ~Item();

Item & operator=(const Item &other);

void setCode(int code);
int getCode();
void setName(string name);
string getName();
void setCategory(char category);
char getCategory();

SerializedStream* serialize();
void deserialize(SerializedStream *stream);
void dispose(SerializedStream *stream);
}; 
}
#endif