#ifndef __ItemCategoryAndNameComparator_h_inventory_bl
#define __ItemCategoryAndNameComparator_h_inventory_bl

#include<bl\I_Item.h>

using namespace std;
using namespace inventory_bl;

class ItemCategoryAndNameComparator
{
public:
bool operator()(I_Item *left,I_Item *right);
};

#endif