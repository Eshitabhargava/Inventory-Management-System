#ifndef __bl_h
#define __bl_h

namespace inventory_bl
{
enum __$__BL_ENUMERATION{
ITEM_NAME,ITEM_CODE,ITEM_CATEGORY,
CONSUMABLE,FINISHED_GOOD,RAW_MATERIAL,
GENERIC_EXCEPTION
};

class EnumComparator
{
public:
bool operator()(__$__BL_ENUMERATION left,__$__BL_ENUMERATION right)
{
return left<right;
}
};
}

#endif
