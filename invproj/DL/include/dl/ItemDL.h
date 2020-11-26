#ifndef __ItemDL_h_
#define __ItemDL_h_ 1

#include <DL\I_ItemDL.h>
#include <DL\I_Item.h>
#include <DL\Item.h>
#include<iostream>
#include<forward_list>

using namespace std;

namespace inventory_dl
{
class ItemDL:public I_ItemDL
{
private:
static string DATA_FILE;

public:
void add(I_Item* item);
void update(I_Item* item);
void remove(int code);
I_Item* getByName(string Name);
I_Item* getByCode(int code);
forward_list<I_Item*>* getAll();
void removeAll();
int getCount();
};
}

#endif