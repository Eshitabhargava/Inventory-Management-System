#ifndef __ItemManager_cpp
#define __ItemManager_cpp

#include<iostream>
#include<map>
#include<set>
#include<utility>

#include<dl\I_Item.h>
#include<dl\Item.h>
#include<dl\I_ItemDL.h>
#include<dl\ItemDL.h>
#include<dl\DLException.h>

#include<bl\I_Item.h>
#include<bl\Item.h>
#include<bl\ItemCodeComparator.h>
#include<bl\ItemNameComparator.h>
#include<bl\ItemNameAsKeyComparator.h>
#include<bl\ItemCategoryAndCodeComparator.h>
#include<bl\ItemCategoryAndNameComparator.h>
#include<bl\BLException.h>
#include<bl\ItemManager.h>
#include<bl\I_ItemManager.h>
#include<bl\CategoryWiseList>
#include<bl\bl.h>

#include<ListImplementation>
#include<List>
#include<IndexOutOfBoundsException>
#include<Utility.h>

using namespace std;
using namespace collections;
using namespace inventory_bl;
using namespace tools;

ItemManager::ItemManager()
{
this->numberOfConsumables=0;
this->numberOfFinishedGoods=0;
this->numberOfRawMaterials=0;
populateDataStructures();
}

ItemManager::~ItemManager()
{
set<I_Item *>::iterator iter;
iter=codeWiseSet.begin();
I_Item *item;
while(iter!=codeWiseSet.end())
{
item=*iter;
delete item;
++iter;
}
this->numberOfConsumables=0;
this->numberOfFinishedGoods=0;
this->numberOfRawMaterials=0;
}

ItemManager::ItemManager(const ItemManager &other)
{
//do nothing
}

ItemManager & ItemManager::operator=(const ItemManager &other)
{
return *this;
}

void ItemManager::populateDataStructures()
{
inventory_dl::ItemDL itemDL;
forward_list<inventory_dl::I_Item *> *items;
items=itemDL.getAll();
__$__BL_ENUMERATION category;
forward_list<inventory_dl::I_Item *>::iterator fi=items->begin();
inventory_dl::I_Item *dlitem;
I_Item *blitem;
while(fi!=items->end())
{
dlitem=*fi;
if(dlitem->getCategory()=='c' || dlitem->getCategory()=='C') 
{
this->numberOfConsumables++;
category=CONSUMABLE;
}
else if(dlitem->getCategory()=='f' || dlitem->getCategory()=='F') 
{
this->numberOfFinishedGoods++;
category=FINISHED_GOOD;
}
else if(dlitem->getCategory()=='r' || dlitem->getCategory()=='R') 
{
this->numberOfRawMaterials++;
category=RAW_MATERIAL;
}
blitem =new Item(dlitem->getCode(),dlitem->getName(),category);
this->itemCodeMap.insert(pair<int,I_Item *>(blitem->getCode(),blitem));
this->itemNameMap.insert(pair<const char *,I_Item *>(blitem->get_name(),blitem));
this->codeWiseSet.insert(blitem);
this->nameWiseSet.insert(blitem);
this->categoryCodeWiseMultiset.insert(blitem);
this->categoryNameWiseMultiset.insert(blitem);
fi++;
}
}

void ItemManager::add(I_Item *item)
{
BLException blException;
if(item==NULL)
{
blException.addException(GENERIC_EXCEPTION,"Item Required");
throw blException;
}
string vName=item->getName();
if(item->getCode()!=0) blException.addException(ITEM_CODE,"Item code should be 0,it will be auto generated");
if(vName.length()==0) blException.addException(ITEM_NAME,"Item name required");
if(vName.length()>75) blException.addException(ITEM_NAME,"Item name cannot exceed 75 characters");
if(item->getCategory().length()==0) blException.addException(ITEM_CATEGORY,"Item Category required");
if(blException.size()>0) throw blException;
map<const char*,I_Item*,ItemNameAsKeyComparator>::iterator fii;
if(itemNameMap.find(item->get_name())!=itemNameMap.end())//item already exists
{
char msg[100];
sprintf(msg,"%s already exists",item->get_name());
blException.addException(ITEM_NAME,string(msg));
throw blException;
}
inventory_dl::ItemDL itemDL;
string category=item->getCategory();
inventory_dl::Item dlitem;
dlitem.setCode(0);
dlitem.setName(item->getName());
dlitem.setCategory(category[0]);
try
{
itemDL.add(&dlitem);
int generatedCode=dlitem.getCode();
item->setCode(generatedCode);
I_Item *blItem=new Item; 
blItem->setCode(generatedCode);
blItem->setName(item->getName());
if(category[0]=='C'  ) 
{
numberOfConsumables++;
blItem->setCategory(CONSUMABLE);
}
else if(category[0]=='F') 
{
numberOfFinishedGoods++;
blItem->setCategory(FINISHED_GOOD);
}
else if(category[0]=='R') 
{
numberOfRawMaterials++;
blItem->setCategory(RAW_MATERIAL);
}
itemCodeMap.insert(pair<int,I_Item *>(blItem->getCode(),blItem));
itemNameMap.insert(pair<const char *,I_Item *>(blItem->get_name(),blItem));
nameWiseSet.insert(blItem);
codeWiseSet.insert(blItem);
categoryNameWiseMultiset.insert(blItem);
categoryCodeWiseMultiset.insert(blItem);
}catch(inventory_dl::DLException dlException)
{
blException.setGenericException(dlException.getMessage());
throw blException;
}
}//add ends

void ItemManager::update(I_Item *item)
{
BLException blException;
if(item==NULL)
{
blException.addException(GENERIC_EXCEPTION,"Item Required");
throw blException;
}
string vName;
int vCode;
string vCategory;
vName=item->getName();
vCode=item->getCode();
vCategory=item->getCategory();
if(vCode<=0) 
{
char message[100];
sprintf(message,"Invalid item code: %d",vCode);
blException.addException(ITEM_CODE,string(message));
}
if(vName.length()==0) blException.addException(ITEM_NAME,"Item Name required");
if(vCategory.length()==0) blException.addException(ITEM_CATEGORY,"Item Category required");
if(vName.length()>75) blException.addException(ITEM_NAME,"Item Name cannot exceed 75 characters");
if(vCategory.length()==0) blException.addException(ITEM_CATEGORY,"Item Category required");
map<int,I_Item *>::iterator iter;
if(iter==itemCodeMap.end())
{
char msg[100];
sprintf(msg,"Invalid Item Code: %d",vCode);
blException.addException(ITEM_CODE,string(msg));
}
if(blException.size()>0) throw blException;
I_Item *dsItem=(*iter).second;
map<const char*,I_Item *,ItemNameAsKeyComparator>::iterator iter2;
iter2=itemNameMap.find(item->get_name());
if(iter2!=itemNameMap.end())
{
if(vCode!=((*iter2).second)->getCode())
{
char msg[100];
sprintf(msg,"%s Already Exists!",vName);
blException.addException(ITEM_NAME,string(msg));
throw blException;
}
}
inventory_dl::ItemDL itemDL;
inventory_dl::Item dlItem;
dlItem.setCode(vCode);
dlItem.setName(vName);
dlItem.setCategory(vCategory[0]);
try
{
itemDL.update(&dlItem);
itemNameMap.erase(dsItem->get_name());
nameWiseSet.erase(dsItem);
categoryNameWiseMultiset.erase(dsItem);
categoryCodeWiseMultiset.erase(dsItem);
dsItem->setName(vName);
string oldCategory;
oldCategory=dsItem->getCategory();
if(oldCategory[0]=='C') numberOfConsumables--;
else if(oldCategory[0]=='F') numberOfFinishedGoods--;
else if(oldCategory[0]=='R') numberOfRawMaterials--;
if(vCategory[0]=='C') 
{
numberOfConsumables++;
dsItem->setCategory(CONSUMABLE);
}
else if(vCategory[0]=='F') 
{
numberOfFinishedGoods++;
dsItem->setCategory(FINISHED_GOOD);
}
else if(vCategory[0]=='R') 
{
numberOfRawMaterials++;
dsItem->setCategory(RAW_MATERIAL);
}
itemNameMap.insert(pair<const char *,I_Item *>(vName.c_str(),dsItem));
nameWiseSet.insert(dsItem);
categoryNameWiseMultiset.insert(dsItem);
categoryCodeWiseMultiset.insert(dsItem);
}catch(inventory_dl::DLException dlException)
{
blException.setGenericException(dlException.getMessage());
throw blException;
}
}//update ends

int ItemManager::getCount()
{
return itemNameMap.size();
//or-> return ccount+fcount+rcount;
}

int ItemManager::getCountByCategory(__$__BL_ENUMERATION category)
{
if(category==CONSUMABLE) return this->numberOfConsumables;
if(category==FINISHED_GOOD) return this->numberOfFinishedGoods;
if(category==RAW_MATERIAL) return this->numberOfRawMaterials;
}

Item ItemManager::getByCode(int code)
{
map<int,I_Item*>::iterator fii;
fii=itemCodeMap.find(code);
if(fii==itemCodeMap.end()) 
{
char msg[51];
sprintf(msg,"%d is an invalid code",code);
BLException blException;
blException.addException(ITEM_CODE,string(msg));
throw blException;
}
__$__BL_ENUMERATION c;
if((*fii).second->getCategory()=="Consumable") c=CONSUMABLE;
else if((*fii).second->getCategory()=="Finished Good") c=FINISHED_GOOD;
else if((*fii).second->getCategory()=="Raw Material") c=RAW_MATERIAL;
return Item((*fii).second->getCode(),(*fii).second->getName(),c);
}

Item ItemManager::getByName(string name)
{
map<const char *,I_Item*,ItemNameAsKeyComparator>::iterator fii;
fii=itemNameMap.find(name.c_str());
if(fii==itemNameMap.end()) 
{
char msg[100];
sprintf(msg,"%s not found",name.c_str());
BLException blException;
blException.addException(ITEM_NAME,string(msg));
throw blException;
}
__$__BL_ENUMERATION c;
if((*fii).second->getCategory()=="Consumable") c=CONSUMABLE;
else if((*fii).second->getCategory()=="Finished Good") c=FINISHED_GOOD;
else if((*fii).second->getCategory()=="Raw Material") c=RAW_MATERIAL;
return Item((*fii).second->getCode(),(*fii).second->getName(),c);
}

List<Item> ItemManager::getAll(__$__BL_ENUMERATION orderBy=ITEM_NAME)
{
if(orderBy==ITEM_CODE)
{ 
ListImplementation<I_Item,Item,ItemCodeComparator> *itemSet;
itemSet=new ListImplementation<I_Item,Item,ItemCodeComparator>(&codeWiseSet);
return List<Item>(itemSet);
}
if(orderBy==ITEM_NAME)
{
ListImplementation<I_Item,Item,ItemNameComparator> *itemSet;
itemSet=new ListImplementation<I_Item,Item,ItemNameComparator>(&nameWiseSet);
return List<Item>(itemSet);
}
}

List<Item> ItemManager::getByCategory(__$__BL_ENUMERATION category,__$__BL_ENUMERATION orderBy=ITEM_NAME)
{
if(category==CONSUMABLE)
{
if(orderBy==ITEM_NAME)
{
CategoryWiseList<ItemCategoryAndNameComparator> *items;
items=new CategoryWiseList<ItemCategoryAndNameComparator>(&categoryNameWiseMultiset,CONSUMABLE,this->numberOfConsumables,0);
return List<Item>(items);
}
if(orderBy==ITEM_CODE)
{
CategoryWiseList<ItemCategoryAndCodeComparator> *items;
items=new CategoryWiseList<ItemCategoryAndCodeComparator>(&categoryCodeWiseMultiset,CONSUMABLE,this->numberOfConsumables,0);
return List<Item>(items);
}
}
if(category==FINISHED_GOOD)
{
if(orderBy==ITEM_NAME)
{
CategoryWiseList<ItemCategoryAndNameComparator> *items;
items=new CategoryWiseList<ItemCategoryAndNameComparator>(&categoryNameWiseMultiset,FINISHED_GOOD,this->numberOfFinishedGoods,this->numberOfConsumables);
return List<Item>(items);
}
if(orderBy==ITEM_CODE)
{
CategoryWiseList<ItemCategoryAndCodeComparator> *items;
items=new CategoryWiseList<ItemCategoryAndCodeComparator>(&categoryCodeWiseMultiset,FINISHED_GOOD,this->numberOfFinishedGoods,this->numberOfConsumables);
return List<Item>(items);
}
}
if(category==RAW_MATERIAL)
{
if(orderBy==ITEM_NAME)
{
CategoryWiseList<ItemCategoryAndNameComparator> *items;
items=new CategoryWiseList<ItemCategoryAndNameComparator>(&categoryNameWiseMultiset,CONSUMABLE,this->numberOfRawMaterials,this->numberOfFinishedGoods+this->numberOfConsumables);
return List<Item>(items);
}
if(orderBy==ITEM_CODE)
{
CategoryWiseList<ItemCategoryAndCodeComparator> *items;
items=new CategoryWiseList<ItemCategoryAndCodeComparator>(&categoryCodeWiseMultiset,CONSUMABLE,this->numberOfRawMaterials,this->numberOfFinishedGoods+this->numberOfConsumables);
return List<Item>(items);
}
}
}//getByCategory ends

void ItemManager::remove(int code)
{
BLException blException;
if(code<=0)
{
char msg[100];
sprintf(msg,"Invalid item code: %d",code);
blException.addException(ITEM_CODE,string(msg));
}
map<int,I_Item *>::iterator iter=this->itemCodeMap.find(code);
if(iter==this->itemCodeMap.end())
{
char msg[100];
sprintf(msg,"Invalid item code: %d",code);
blException.addException(ITEM_CODE,string(msg));
}
if(blException.size()>0) throw blException;
I_Item *dsItem=(*iter).second;
inventory_dl::ItemDL itemDL;
try
{
itemDL.remove(code);
string category;
category=dsItem->getCategory();
if(category[0]=='C'|| category[0]=='c') this->numberOfConsumables--;
else if(category[0]=='F'|| category[0]=='f') this->numberOfFinishedGoods--;
else if(category[0]=='R'|| category[0]=='r') this->numberOfRawMaterials--;
itemNameMap.erase(dsItem->get_name());
itemCodeMap.erase(code);
nameWiseSet.erase(dsItem);
codeWiseSet.erase(dsItem);
categoryNameWiseMultiset.erase(dsItem);
categoryCodeWiseMultiset.erase(dsItem);
delete dsItem;
}catch(inventory_dl::DLException dlException)
{
blException.setGenericException(dlException.getMessage());
throw blException;
}
}//remove ends

void ItemManager::removeAll()
{
try
{
inventory_dl::ItemDL itemDL;
itemDL.removeAll();
set<I_Item *>::iterator iter;
iter=codeWiseSet.begin();
I_Item *item;
while(iter!=codeWiseSet.end())
{
item=*iter;
delete item;
++iter;
}
itemNameMap.clear();
itemCodeMap.clear();
nameWiseSet.clear();
codeWiseSet.clear();
categoryNameWiseMultiset.clear();
categoryCodeWiseMultiset.clear();
this->numberOfConsumables=this->numberOfFinishedGoods=this->numberOfRawMaterials=0;
}catch(inventory_dl::DLException dlException)
{
BLException blException;
blException.setGenericException(dlException.getMessage());
throw blException;
}
}

void ItemManager::removeCategory(__$__BL_ENUMERATION category)
{
string toRemove;
try
{
if(category==CONSUMABLE) toRemove="Consumable";
else if(category==FINISHED_GOOD) toRemove="Finished Good";
else if(category==RAW_MATERIAL) toRemove="Raw Material";
set<I_Item *,ItemCodeComparator>::iterator i3;
inventory_dl::ItemDL itemDL;
I_Item *dsItem;
for(i3=codeWiseSet.begin();i3!=codeWiseSet.end();)
{
dsItem=*i3;
if(dsItem->getCategory()==toRemove)
{
itemDL.remove(dsItem->getCode());
i3=codeWiseSet.erase(i3);
}
else i3++;
}
set<I_Item *,ItemNameComparator>::iterator i5;
for(i5=nameWiseSet.begin();i5!=nameWiseSet.end();)
{
dsItem=*i5;
if(dsItem->getCategory()==toRemove) i5=nameWiseSet.erase(i5);
else i5++;
}
multiset<I_Item *,ItemCategoryAndCodeComparator>::iterator i4start,i4end;
for(i4start=categoryCodeWiseMultiset.begin();i4start!=categoryCodeWiseMultiset.end();)
{
dsItem=*i4start;
if(dsItem->getCategory()==toRemove) i4start=categoryCodeWiseMultiset.erase(i4start);
else i4start++;
}
multiset<I_Item *,ItemCategoryAndNameComparator>::iterator i5start,i5end;
for(i5start=categoryCodeWiseMultiset.begin();i5start!=categoryCodeWiseMultiset.end();)
{
dsItem=*i5start;
if(dsItem->getCategory()==toRemove) i5start=categoryCodeWiseMultiset.erase(i5start);
else i5start++;
}
map<const char *,I_Item *,ItemNameAsKeyComparator>::iterator i1;
for(i1=itemNameMap.begin();i1!=itemNameMap.end();)
{
dsItem=(*i1).second;
if(dsItem->getCategory()==toRemove) i1=itemNameMap.erase(i1);
else i1++;
}
map<int,I_Item *>::iterator i2;
for(i2=itemCodeMap.begin();i2!=itemCodeMap.end();)
{
dsItem=(*i2).second;
if(dsItem->getCategory()==toRemove) 
{
i2=itemCodeMap.erase(i2);
delete dsItem;
}
else i2++;
}
if(category==CONSUMABLE) this->numberOfConsumables=0;
else if(category==FINISHED_GOOD) this->numberOfFinishedGoods=0;
else if(category==RAW_MATERIAL) this->numberOfRawMaterials=0;
}catch(inventory_dl::DLException dlException)
{
BLException blException;
blException.setGenericException(dlException.getMessage());
}
}//removeCategory ends

void ItemManager::removeByName(string name)
{
BLException blException;
string vCategory;
map<const char*,I_Item *>::iterator ii;
ii=itemNameMap.find(name.c_str());
if(ii==itemNameMap.end()) 
{
char msg[100];
sprintf(msg,"Invalid item %s.",name);
blException.addException(ITEM_NAME,string(msg));
throw blException;
}
try
{
inventory_dl::ItemDL itemDL;
I_Item *dsItem=(*ii).second;
itemDL.remove(dsItem->getCode());
itemCodeMap.erase(dsItem->getCode());
itemNameMap.erase(dsItem->get_name());
codeWiseSet.erase(dsItem);
nameWiseSet.erase(dsItem);
categoryCodeWiseMultiset.erase(dsItem);
categoryNameWiseMultiset.erase(dsItem);
vCategory=dsItem->getCategory();
if(vCategory[0]=='C') numberOfConsumables--;
else if(vCategory[0]=='F') numberOfFinishedGoods--;
else if(vCategory[0]=='R') numberOfRawMaterials--;
free(dsItem);
}catch(inventory_dl::DLException dlException)
{
blException.setGenericException(dlException.getMessage());
throw blException;
}
}//removeByName

#endif