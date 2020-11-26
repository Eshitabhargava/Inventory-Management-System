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
List<Item> itemsMultiset=im.getAll(ITEM_CODE);
cout<<"("<<itemsMultiset.getSize()<<")"<<endl;
for(int i=0;i<itemsMultiset.getSize();i++)
{
Item item=itemsMultiset.get(i);
cout<<item.getCode()<<" "<<item.getName()<<" "<<item.getCategory()<<endl;
}
return 0;
}