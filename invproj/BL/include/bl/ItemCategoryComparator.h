#ifndef __ItemCategoryComparator_h_inventory_bl
#define __ItemCategoryComparator_h_inventory_bl

#include<bl\I_Item.h>

using namespace std;
using namespace inventory_bl;

class ItemCategoryComparator
{
public:
bool operator()(I_Item *left,I_Item *right);
};

#endif