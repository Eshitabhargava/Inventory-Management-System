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
int main()
{
ItemManager im;
Item item(1009,"",FINISHED_GOOD);
/*Item item;
item.setCode(0);
item.setName("CALENDAR");
item.setCategory(FINISHED_GOOD);*/
cout<<"item name is: "<<item.getName()<<endl;
try
{
im.add(&item);
}catch(BLException blexception)
{
map<__$__BL_ENUMERATION,string> exc=blexception.getExceptions();
map<__$__BL_ENUMERATION,string>::iterator ii=exc.begin();
while(ii!=exc.end())
{
cout<<"\""<<(*ii).second<<"\""<<endl;
++ii;
}
}
cout<<"executed";
return 0;
}