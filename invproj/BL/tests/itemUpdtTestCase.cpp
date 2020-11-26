#include<iostream>
#include<bl\ItemManager.h>
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<List>
#include<bl\BLException.h>
#include<map>
#include<bl\bl.h>
using namespace collections;
using namespace std;
using namespace inventory_bl;
int main(int cnt,char *str[])
{
if(cnt!=4)
{
cout<<"Usage [itemUpdtTestCase CodeOfItem NameOfItem CategoryOfItem[COSUMABLE/FINISHED_GOOD/RAW_MATERIAL]]"<<endl;
return 0;
}
I_Item *item=new Item;
item->setCode(atoi(str[1]));
item->setName(str[2]);
if(str[3][0]=='C' || str[3][0]=='c') item->setCategory(CONSUMABLE);
else if(str[3][0]=='F' || str[3][0]=='f') item->setCategory(FINISHED_GOOD);
else if(str[3][0]=='R' || str[3][0]=='r') item->setCategory(RAW_MATERIAL);
ItemManager im;
try
{
im.update(item);
cout<<"Item Updated!"<<endl;
}catch(BLException blexception)
{
cout<<"--"<<blexception.size()<<"--"<<endl;
map<__$__BL_ENUMERATION,string> exc=blexception.getExceptions();
map<__$__BL_ENUMERATION,string>::iterator ii=exc.begin();
while(ii!=exc.end())
{
cout<<"\""<<(*ii).second<<"\""<<endl;
++ii;
}
}
return 0;
}