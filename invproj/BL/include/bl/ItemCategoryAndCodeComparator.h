#ifndef __ItemCategoryAndCodeComparator_h_inventory_bl
#define __ItemCategoryAndCodeComparator_h_inventory_bl

#include<bl\I_Item.h>

using namespace std;
using namespace inventory_bl;

class ItemCategoryAndCodeComparator
{
public:
bool operator()(I_Item *left,I_Item *right);
};

#endif