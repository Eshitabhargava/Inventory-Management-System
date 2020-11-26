#include <dl\ItemDL.h>
#include <dl\Item.h>
#include <dl\I_Item.h>
#include <dl\DLException.h>
#include <stdlib.h>
using namespace std;
using namespace inventory_dl;
int main(int cnt,char *str[])
{
if(cnt!=4)
{
cout<<"Usage [TestItemU CodeOfItem NameOfItem CategoryOfItem[C/R/F]]"<<endl;
return 0;
}
I_Item *item=new Item;
item->setCode(atoi(str[1]));
item->setName(str[2]);
item->setCategory(str[3][0]);
ItemDL itemDL;
try
{
itemDL.update(item);
cout<<"Item Updated!"<<endl;
}catch(DLException dlException)
{
cout<<"Exception generated : "<<dlException.getMessage()<<endl;
}
delete item;
return 0;
}