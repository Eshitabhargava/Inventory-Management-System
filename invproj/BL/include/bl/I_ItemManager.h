#ifndef __I_ItemManager_h_inventory_bl 
#define __I_ItemManager_h_inventory_bl

#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<bl\I_Item.h>
#include<bl\Item.h>
#include<bl\ItemcodeComparator.h>
#include<bl\ItemNameComparator.h>
#include<bl\ItemCategoryAndCodeComparator.h>
#include<bl\ItemCategoryAndNameComparator.h>
#include<bl\bl.h>
#include<List>

using namespace collections;

namespace inventory_bl
{
class I_ItemManager
{
public:
virtual void add(I_Item *item)=0;
virtual void update(I_Item *item)=0;
virtual int getCount()=0;
virtual int getCountByCategory(__$__BL_ENUMERATION category)=0;
virtual Item getByCode(int code)=0;
virtual Item getByName(string name)=0;
virtual List<Item> getAll(__$__BL_ENUMERATION orderBy=ITEM_NAME)=0;
virtual List<Item> getByCategory(__$__BL_ENUMERATION category,__$__BL_ENUMERATION orderBy=ITEM_NAME)=0;
virtual void remove(int code)=0;
virtual void removeAll()=0;
virtual void removeCategory(__$__BL_ENUMERATION category)=0;
virtual void removeByName(string name)=0;
};
}
#endif
//****Initially we were returning the address of a list class object
//from getAll and getByCategory,the elements this list contains
//were all addresses of objects of item class.It was risky to
//give access to the address of each and every item as this can
//lead to manipulations with our data,and even deletion of the same
//for this we created a class whose object will wrap this address of
//the list class object and this class will not contain any
//methods to facilitate changes with these items,nor will their 
//destruction be possible now.but we decided on replacing this list
//class object with a set class object bcz the items are to be
//kept in  a sorted fashion.just as a set works we will now need
//to specify our custom comparator during set declarartion
//to sort these items as per our requirements.
//due to this at the receiving end the eprson placing call to these
//getters will have to specify a lot of irrelevant info(comparator and base class name)
//instead he should be only specifying 1 argument i.e. "Item"
//bcz he is asking for a list of items.
//to achieve this we created an intermediate class by the
//name ListImplementation,that will accept 3 args and will be 
//written by BL programmer.this will have an abstract base class
//called AbstractList,that will accept only one argument the name 
//of our class which is Item,and finally a class named List
//which accepts only 1 arg and will serve as the return type
//of these methods.
//the class listimplementation is an excellent example of
//call forwarding.It appears like the methods of class List
//are being executed while actually the methods of listimplentation
//are being executed.
//pointer of AbstractList is in List,this pointer will be 
//capable of holding the address of object of listimplemnation
//since base class ptr is able to store address of object of
//its derived class.This pointer will hence be storing the 
//adddress of object which is wrapping the actual list class
//object.
//ListImplementation will contain a pointer to set type object
//this ptr will point to the address of the actual set class obj
//containing all our items
//AbstractList and List=1 type args
//ListImplementation=3 type args(written by bl programmer)