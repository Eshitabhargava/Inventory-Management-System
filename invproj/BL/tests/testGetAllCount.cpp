#include<iostream>
#include<bl\ItemManager.h>
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<List>
using namespace collections;
using namespace std;
using namespace inventory_bl;
int main()
{
ItemManager im;
cout<<"Count is: "<<im.getCount();
return 0;
}