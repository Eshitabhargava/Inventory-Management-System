#ifndef __ItemCodeComparator_cpp
#define __ItemCodeComparator_cpp

#include<bl\I_Item.h>
#include<bl\ItemCodeComparator.h>

using namespace std;
using namespace inventory_bl;

bool ItemCodeComparator::operator()(I_Item *left,I_Item *right)
{
if(left->getCode()<right->getCode()) return true;
return false;
}

#endif