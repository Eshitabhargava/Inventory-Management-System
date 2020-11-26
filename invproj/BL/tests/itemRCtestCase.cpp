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
if(cnt!=2)
{
cout<<"Usage [itemRCtestCase CategoryToRemove[COSUMABLE/FINISHED_GOOD/RAW_MATERIAL]]"<<endl;
return 0;
}
ItemManager im;
try
{
cout<<"("<<str[1][0]<<")"<<endl;
cout<<"BEFORE REMOVING: ";
if(str[1][0]=='C') cout<<im.getCountByCategory(CONSUMABLE)<<endl;
else if(str[1][0]=='F') cout<<im.getCountByCategory(FINISHED_GOOD)<<endl;
else if(str[1][0]=='R') cout<<im.getCountByCategory(RAW_MATERIAL)<<endl;
if(str[1][0]=='C') im.removeCategory(CONSUMABLE);
else if(str[1][0]=='F') im.removeCategory(FINISHED_GOOD);
else if(str[1][0]=='R') im.removeCategory(RAW_MATERIAL);
cout<<"CATEGORY REMOVED!"<<endl;
cout<<"AFTER REMOVING: ";
if(str[1][0]=='C') cout<<im.getCountByCategory(CONSUMABLE)<<endl;
else if(str[1][0]=='F') cout<<im.getCountByCategory(FINISHED_GOOD)<<endl;
else if(str[1][0]=='R') cout<<im.getCountByCategory(RAW_MATERIAL)<<endl;
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