#include<iostream>
#include<bl\ItemManager.h>
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<List>
#include<bl\BLException.h>
using namespace collections;
using namespace std;
using namespace inventory_bl;
int main()
{
ItemManager im;
try
{
List<Item> itemsMultiset=im.getByCategory(RAW_MATERIAL,ITEM_NAME);
cout<<"("<<itemsMultiset.getSize()<<")"<<endl;
for(int i=0;i<itemsMultiset.getSize();i++)
{
Item item=itemsMultiset.get(i);
cout<<item.getCode()<<" "<<item.getName()<<" "<<item.getCategory()<<endl;
}
}catch(BLException blException)
{
cout<<blException.getGenericException()<<endl;
}
return 0;
}