#ifndef __ItemNameAsKeyComparator_cpp
#define __ItemNameAsKeyComparator_cpp

#include<bl\I_Item.h>
#include<bl\ItemNameAsKeyComparator.h>
#include<Utility.h>

using namespace std;
using namespace inventory_bl;
using namespace tools;

bool ItemNameAsKeyComparator::operator()(const char *left,const char *right) const
{
if(Utility::compareStrings(left,right)<0) return true;
return false;
}

#endif