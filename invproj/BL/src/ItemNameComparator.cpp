#ifndef __ItemNameComparator_cpp
#define __ItemNameComparator_cpp

#include<bl\I_Item.h>
#include<bl\ItemNameComparator.h>
#include<Utility.h>

using namespace std;
using namespace inventory_bl;
using namespace tools;

bool ItemNameComparator::operator()(I_Item *left,I_Item *right)
{
if(Utility::compareStrings(left->getName().c_str(),right->getName().c_str())<0) return true;
return false;
}

#endif