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
cout<<"Number of items: "<<itemDL.getCount()<<endl;
return 0;
}