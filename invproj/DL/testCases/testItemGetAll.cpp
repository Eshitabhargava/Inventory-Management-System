#include <dl\ItemDL.h>
#include <dl\Item.h>
#include <dl\I_Item.h>
#include <dl\DLException.h>
#include<stdlib.h>
#include<iostream>
#include<forward_list>
using namespace std;
using namespace inventory_dl;
int main(int cnt,char *str[])
{
ItemDL itemDL;
forward_list<I_Item *> *items;
items=itemDL.getAll();
forward_list<I_Item *>::iterator iter;
iter=items->begin();
while(iter!=items->end())
{
I_Item *item;
item=*iter;
cout<<"Item Code: "<<item->getCode()<<" Item Name: "<<item->getName()<<" Item category: "<<item->getCategory()<<endl;
iter++;
}
//delete item;
return 0;
}