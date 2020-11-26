#include <dl\ItemDL.h>
#include <dl\Item.h>
#include <dl\I_Item.h>
#include <dl\DLException.h>
using namespace std;
using namespace inventory_dl;
int main(int cnt,char *str[])
{
if(cnt!=3)
{
cout<<"Usage [TestItemAdd NameOfItem CtaegoryOfItem[C/R/F]]"<<endl;
return 0;
}
I_Item *item=new Item;
item->setName(str[1]);
item->setCategory(str[2][0]);
ItemDL itemDL;
try
{
itemDL.add(item);
cout<<"Item added with code as : "<<item->getCode()<<endl;
}catch(DLException dlException)
{
cout<<"Exception generated : "<<dlException.getMessage()<<endl;
}
delete item;
return 0;
}