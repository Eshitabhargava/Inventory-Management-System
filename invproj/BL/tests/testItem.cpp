#include<iostream>
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<Item.cpp>
using namespace std;
using namespace inventory_bl;
int main()
{
Item i;
i.setCode(19);
i.setName("Gochi");
i.setCategory(CONSUMBALE);
cout<<"Item code: "<<i.getCode()<<" "<<i.getName()<<" "<<i.getCategory()<<endl;
return 0;
}