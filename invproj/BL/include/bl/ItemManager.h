#ifndef __ItemManager_h_inventory_bl 
#define __ItemManager_h_inventory_bl

#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<bl\ItemcodeComparator.h>
#include<bl\ItemNameComparator.h>
#include<bl\ItemNameAsKeyComparator.h>
#include<bl\ItemCategoryAndCodeComparator.h>
#include<bl\ItemCategoryAndNameComparator.h>
#include<bl\I_ItemManager.h>
#include<bl\bl.h>
#include<bl\NameComparator.h>
#include<List>
#include<bl\CategoryWiseList>

using namespace collections;

namespace inventory_bl
{
class ItemManager:public I_ItemManager
{
private:
map<int,I_Item*> itemCodeMap;
map<const char*,I_Item*,ItemNameAsKeyComparator> itemNameMap;

set<I_Item *,ItemCodeComparator> codeWiseSet;
set<I_Item *,ItemNameComparator> nameWiseSet;

multiset<I_Item *,ItemCategoryAndCodeComparator> categoryCodeWiseMultiset;
multiset<I_Item *,ItemCategoryAndNameComparator> categoryNameWiseMultiset;

void populateDataStructures();

int numberOfConsumables;
int numberOfFinishedGoods;
int numberOfRawMaterials;

public:

ItemManager();
ItemManager(const ItemManager &other);

ItemManager & operator=(const ItemManager &other);

virtual ~ItemManager();

void add(I_Item *item);
void update(I_Item *item);
int getCount();
int getCountByCategory(__$__BL_ENUMERATION category);
Item getByCode(int code);
Item getByName(string name);
List<Item> getAll(__$__BL_ENUMERATION);
List<Item> getByCategory(__$__BL_ENUMERATION category,__$__BL_ENUMERATION);
void remove(int code);
void removeAll();
void removeCategory(__$__BL_ENUMERATION category);
void removeByName(string name);
};
}
#endif
