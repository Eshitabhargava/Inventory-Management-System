#ifndef __ItemDL_cpp
#define __ItemDL_cpp 1

#include <dl\I_Item.h>
#include <dl\Item.h>
#include <dl\ItemDL.h>
#include <FileHandler.h>
#include <dl\ItemHeader.h>
#include <dl\DLException.h>
#include<iostream>
#include<forward_list>
#include<string.h>
#include<cstdio>

using namespace std;
using namespace inventory_dl;

string ItemDL::DATA_FILE="item.data";

void ItemDL::add(I_Item* item)
{
FileHandler fileHandler;
ItemHeader itemHeader;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
itemHeader.setLastGeneratedItemCode(1000);
itemHeader.setNumberOfRecords(0);
fileHandler.write(&itemHeader);
fileHandler.seek(0);
}
fileHandler.read(&itemHeader);
I_Item *vItem=new Item;
while(true)
{
fileHandler.read(vItem);
if(fileHandler.failed()) break;
if(stricmp(vItem->getName().c_str(),item->getName().c_str())==0)
{
delete vItem;
fileHandler.close();
string message;
message="Item ";
message+=item->getName();
message+="already exists!";
throw DLException(message);
}
}
delete vItem;
int newCode=itemHeader.getLastGeneratedItemCode()+1;
itemHeader.setLastGeneratedItemCode(newCode);
itemHeader.setNumberOfRecords(itemHeader.getNumberOfRecords()+1);
item->setCode(newCode);
fileHandler.write(item);
fileHandler.seek(0);
fileHandler.write(&itemHeader);
fileHandler.close();
}

void ItemDL::update(I_Item *item)
{
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
string message="Item code ";
message+=to_string(item->getCode());
message+="  does not exist!";
throw DLException(message);
}
ItemHeader itemHeader;
fileHandler.read(&itemHeader);
if(itemHeader.getNumberOfRecords()==0)
{
string message="Item code ";
message+=to_string(item->getCode());
message+="  does not exist!";
throw DLException(message);
}
I_Item *vItem=new Item;
bool found=true;
while(true)
{
fileHandler.read(vItem);
if(fileHandler.failed()) break;
if(item->getCode()==vItem->getCode())
{
found=true;
break;
}
}
if(!found)
{
string message="Item code ";
message+=to_string(item->getCode());
message+="  does not exist!";
throw DLException(message);
}
fileHandler.seek(0);
fileHandler.read(&itemHeader);

while(true)
{
fileHandler.read(vItem);
if(fileHandler.failed()) break;
if(stricmp(vItem->getName().c_str(),item->getName().c_str())==0)
{
string message="Item ";
message+=item->getName();
message+=" exists!";
throw DLException(message);
}
}
FileHandler tmpfh;
char *tmpName=tmpnam(NULL);
tmpfh.open(string(tmpName+1));
fileHandler.seek(0);
fileHandler.read(&itemHeader);
tmpfh.write(&itemHeader);
while(true)
{
fileHandler.read(vItem);
if(fileHandler.failed()) break;
if(vItem->getCode()==item->getCode())
{
tmpfh.write(item);
}
else
{
tmpfh.write(vItem);
}
}
tmpfh.close();
fileHandler.close();
::remove(DATA_FILE.c_str());
rename(tmpName+1,DATA_FILE.c_str());
}

void ItemDL::remove(int code)
{
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
fileHandler.close();
string message="Item Code ";
message+=to_string(code);
message+=" does not exist!";
throw DLException(message);
}
ItemHeader itemHeader;
fileHandler.read(&itemHeader);
if(itemHeader.getNumberOfRecords()==0)
{
fileHandler.close();
string message="Item Code ";
message+=to_string(code);
message+=" does not exist!";
throw DLException(message);
}
I_Item *item=new Item;
bool found=false;
while(true)
{
fileHandler.read(item);
if(fileHandler.failed()) break;
if(item->getCode()==code)
{
found=true;
break;
}
}
if(!found)
{
fileHandler.close();
string message="Item Code ";
message+=to_string(code);
message+=" does not exist!";
throw DLException(message);
}
FileHandler tmpfh;
char *tmpName=tmpnam(NULL);
tmpfh.open(string(tmpName+1));
fileHandler.seek(0);
fileHandler.read(&itemHeader);
itemHeader.setNumberOfRecords(itemHeader.getNumberOfRecords()-1);
tmpfh.write(&itemHeader);
while(true)
{
fileHandler.read(item);
if(fileHandler.failed()) break;
if(item->getCode()!=code)
{
tmpfh.write(item);
}
}
fileHandler.close();
tmpfh.close();
::remove(DATA_FILE.c_str());
rename(tmpName+1,DATA_FILE.c_str());
}

I_Item* ItemDL::getByName(string Name)
{
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
fileHandler.close();
string message="Item ";
message+=Name;
message+=" is invalid!";
throw DLException(message);
}
ItemHeader itemHeader;
fileHandler.read(&itemHeader);
if(itemHeader.getNumberOfRecords()==0)
{
fileHandler.close();
string message="Item ";
message+=Name;
message+=" is invalid!";
throw DLException(message);
}
I_Item *vItem=new Item;
int found=0;
while(true)
{
fileHandler.read(vItem);
if(fileHandler.failed()) break;
if(stricmp(vItem->getName().c_str(),Name.c_str())==0)
{
found=1;
break;
}
}
if(found==1) 
{
fileHandler.close();
return vItem;
}
else
{
delete vItem;
fileHandler.close();
string message="Item ";
message+=Name;
message+=" is invalid!";
throw DLException(message);
}
}

I_Item* ItemDL::getByCode(int code)
{
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
fileHandler.close();
string message="Item code ";
message+=to_string(code);
message+=" is invalid!";
throw DLException(message);
}
ItemHeader itemHeader;
fileHandler.read(&itemHeader);
if(itemHeader.getNumberOfRecords()==0)
{
fileHandler.close();
string message="Item code ";
message+=to_string(code);
message+=" is invalid!";
throw DLException(message);
}
I_Item *vItem=new Item;
int found=0;
while(true)
{
fileHandler.read(vItem);
if(fileHandler.failed()) break;
if(vItem->getCode()==code)
{
found=1;
break;
}
} 
fileHandler.close();
if(found==1)
{
return vItem;
}
else
{
delete vItem;
string message="Item code ";
message+=to_string(code);
message+=" is invalid!";
throw DLException(message);
}
}

forward_list<I_Item*>* inventory_dl::ItemDL::getAll()
{
forward_list<I_Item*> *items;
items=new forward_list<I_Item*>;
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
fileHandler.close();
return items;
} 
ItemHeader itemHeader;
fileHandler.read(&itemHeader);
if(itemHeader.getNumberOfRecords()==0)
{
fileHandler.close();
return items;
}
Item *item;
forward_list<I_Item *>::iterator iter;
iter=items->before_begin();
while(true)
{
item=new Item;
fileHandler.read(item);
if(fileHandler.failed())
{
delete item;
break;
}
iter=items->insert_after(iter,item);
}
fileHandler.close();
return items;
}

void ItemDL::removeAll()
{
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
fileHandler.close();
return;
}
ItemHeader itemHeader;
fileHandler.read(&itemHeader);
fileHandler.close();
::remove(DATA_FILE.c_str());
fileHandler.open(DATA_FILE);
itemHeader.setNumberOfRecords(0);
fileHandler.write(&itemHeader);
fileHandler.close();
}

int ItemDL::getCount()
{
FileHandler fileHandler;
fileHandler.open(DATA_FILE);
if(fileHandler.length()==0)
{
fileHandler.close();
return 0;
}
ItemHeader itemHeader;
fileHandler.read(&itemHeader);
fileHandler.close();
return itemHeader.getNumberOfRecords();
}

#endif