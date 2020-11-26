#ifndef __ItemNameAsKeyComparator_h_inventory_bl
#define __ItemNameAsKeyComparator_h_inventory_bl

#include<bl\I_Item.h>

using namespace inventory_bl;
using namespace std;

class ItemNameAsKeyComparator
{
public:
bool operator()(const char *left,const char *right) const;
};

#endif