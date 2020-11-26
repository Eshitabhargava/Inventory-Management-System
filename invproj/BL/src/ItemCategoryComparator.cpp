#ifndef __ItemCategoryComparator_cpp
#define __ItemCategoryComparator_cpp

#include<bl\I_Item.h>
#include<bl\ItemCategoryComparator.h>

using namespace std;
using namespace inventory_bl;

bool ItemCategoryComparator::operator()(I_Item *left,I_Item *right)
{
if(left->getCategory()==right->getCategory()) return true;
if(left->getCategory()<right->getCategory()) return true;
else return false;
}

#endif