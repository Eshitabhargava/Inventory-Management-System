#include "ItemDL.h"
#include "ItemDL.cpp"
#include "Item.h"
#include "Item.cpp"
#include "I_Item.h"
#include "DLException.h"
#include "DLException.cpp"
int main(int cnt,char *str[])
{
ItemDL itemDL;
cout<<"Before removing: "<<itemDL.getCount()<<endl;
cout<<"Removing all items"<<endl;
itemDL.removeAll();
cout<<"After removing: "<<itemDL.getCount()<<endl;
return 0;
}