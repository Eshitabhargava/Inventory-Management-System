#include<iostream>
#include<set>
#include<IndexOutOfBoundsException>
#include<dl\I_Item.h>
#include<dl\Item.h>
#include<dl\ItemDL.h>
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<forward_list>
/*#include<Abstract_list.cpp>
#include<List_implemntation.cpp>
#include<List.cpp>*/
using namespace inventory_bl;
using namespace inventory_dl;
using namespace std;
int main()
{
inventory_dl::ItemDL itemDL;
forward_list<inventory_dl::I_Item *> *items;
items=itemDL.getAll();
forward_list<inventory_dl::I_Item *>::iterator iter;
iter=items->begin();
while(iter!=items->end())
{
inventory_dl::I_Item *item;
item=*iter;
cout<<"Item Code: "<<item->getCode()<<" Item Name: "<<item->getName()<<" Item category: "<<item->getCategory()<<endl;
iter++;
}
return 0;
}



/*int main()
{
inventory_dl::ItemDL dl;
forward_list<inventory_dl::I_Item *> *flist;
flist=dl.getAll();
forward_list<inventory_dl::I_Item *>::iterator i,j;
i=flist->begin();
cout<<"ok"<<endl;
cout<<&(*i)<<endl;
j=flist->end();
cout<<&(*j)<<endl;
while(i!=flist->end())
{
inventory_dl::I_Item *item;
item=*i;
cout<<"ok"<<endl;
cout<<item->getCode()<<endl;
++i;
}
cout<<"DONE!!"<<endl;
//delete item;
return 0;
}*/