#ifndef __ItemNameComparator_h_inventory_bl
#define __ItemNameComparator_h_inventory_bl

#include<bl\I_Item.h>

using namespace inventory_bl;
using namespace std;

class ItemNameComparator
{
public:
bool operator()(I_Item *left,I_Item *right);
};

#endif