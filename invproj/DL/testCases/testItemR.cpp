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
cout<<"Usage [TestItemR CodeOfItem]"<<endl;
return 0;
}
ItemDL itemDL;
try
{
itemDL.remove(atoi(str[1]));
cout<<"Item Removed!"<<endl;
}catch(DLException dlException)
{
cout<<"Exception generated : "<<dlException.getMessage()<<endl;
}
return 0;
}