#include<iostream>
#include<bl\ItemManager.h>
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<List>
using namespace collections;
using namespace std;
using namespace inventory_bl;
int main()
{
ItemManager im;
Item item;
item=im.getByCode(1019);
cout<<item.getCode()<<" "<<item.getName()<<""<<item.getCategory()<<endl;
cout<<"executed";
return 0;
}