#ifndef __ItemCodeComparator_h_inventory_bl
#define __ItemCodeComparator_h_inventory_bl

#include<bl\I_Item.h>

using namespace std;
using namespace inventory_bl;

class ItemCodeComparator
{
public:
bool operator()(I_Item *left,I_Item *right);
};

#endif