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
try{
item=im.getByName("MACHINE Oil");
cout<<item.getCode()<<" "<<item.getName()<<" "<<item.getCategory()<<endl;
}catch(BLException blexception)
{
cout<<"("<<blexception.getException(ITEM_NAME)<<")"<<endl;
}
return 0;
}