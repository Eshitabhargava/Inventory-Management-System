#include "ItemDL.h"
#include "ItemDL.cpp"
#include "Item.h"
#include "Item.cpp"
#include "I_Item.h"
#include "DLException.h"
#include "DLException.cpp"
int main(int cnt,char *str[])
{
if(cnt!=2)
{
cout<<"Usage [TestItemGetByName NameOfItem] "<<endl;
return 0;
}
I_Item *item=new Item;
ItemDL itemDL;
try
{
item=itemDL.getByName(str[1]);
cout<<"Item Code: "<<item->getCode()<<" Item Name: "<<item->getName()<<" Item category: "<<item->getCategory()<<endl;
}catch(DLException dlException)
{
cout<<"Exception generated : "<<dlException.getMessage()<<endl;
}
delete item;
return 0;
}