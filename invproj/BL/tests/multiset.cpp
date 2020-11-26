#include<iostream>
#include<set>
#include<list>
#include<IndexOutOfBoundsException>
#include<dl\I_Item.h>
#include<dl\Item.h>
#include<dl\ItemDL.h>
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<string.h>
#include<AbstractList>
#include<List>
#include<ListImplementationMultiset>
#include<utility>
using namespace inventory_bl;
using namespace std;
using namespace collections;
class ItemCategoryAndNameComparator
{
public:
bool operator()(pair<const char *,I_Item *> *left,pair<const char *,I_Item *> *right)
{
//if(stricmp(left->first,right->first)==0)
if(left->second->getCategory()==right->second->getCategory())
{
if(stricmp((left->second->getName()).c_str(),(right->second->getName()).c_str())<0) return true;
else return false;
}
else if(left->second->getCategory()<right->second->getCategory()) return true;
else return false;
}
};
multiset<pair<const char *,I_Item *> *,ItemCategoryAndNameComparator> nameSet;
List<Item> getItems()
{
inventory_dl::ItemDL itemDL;
forward_list<inventory_dl::I_Item *> *items;
items=itemDL.getAll();
multiset<int,I_Item *> codeSet;
__$__ITEM_CATEGORY category;
forward_list<inventory_dl::I_Item *>::iterator fi=items->begin();
I_Item *blitem;
inventory_dl::I_Item *dlitem;
while(fi!=items->end())
{
dlitem=*fi;
if(dlitem->getCategory()=='c' || dlitem->getCategory()=='C') category=CONSUMABLE;
else if(dlitem->getCategory()=='f' || dlitem->getCategory()=='F') category=FINISHED_GOOD;
else if(dlitem->getCategory()=='r' || dlitem->getCategory()=='R') category=RAW_MATERIAL;
blitem=new Item(dlitem->getCode(),dlitem->getName(),category);
pair<const char *,I_Item *> *p=new pair<const char *,I_Item *>((blitem->getCategory()).c_str(),blitem);
nameSet.insert(p);
fi++;
}
ListImplementationMultiset<pair<const char *,I_Item *>,Item,ItemCategoryAndNameComparator> *itemMultiset;
itemMultiset=new ListImplementationMultiset<pair<const char *,I_Item *>,Item,ItemCategoryAndNameComparator>(&nameSet);
return List<Item>(itemMultiset);
}
int main()
{
List<Item> itemsMultiset=getItems();
for(int i=0;i<itemsMultiset.getSize();i++)
{
Item item=itemsMultiset.get(i);
cout<<item.getCode()<<" "<<item.getName()<<" "<<item.getCategory()<<endl;
}
return 0;
}