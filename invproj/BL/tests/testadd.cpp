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
Item item;
item.setName("lotion");
item.setCategory(CONSUMABLE);
try
{
im.add(&item);
}catch(BLException blexception)
{
cout<<blexception.getMessage()<<endl;
}
cout<<"executed";
return 0;
}