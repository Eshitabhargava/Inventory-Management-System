#ifndef __Item_cpp
#define __Item_cpp 1

#include <dl\Item.h>
#include <SerializedStream.h>
#include <Utility.h>
#include<string.h>

using namespace inventory_dl;
using namespace tools;

Item::Item() 
{
this->code=0;
this->name=""; 
this->category=' ';
}

Item::Item(int code,string name,char category)
{
this->code=code;
this->name=name; 
this->category=category;
}

Item::Item(const Item &other) 
{
this->code=other.code;
this->name=other.name; 
this->category=other.category;
}

Item::~Item() 
{
// do nothing 
}

Item & Item::operator=(const Item &other) 
{
this->code=other.code;
this->name=other.name;
this->category=other.category;
return *this; 
}

void Item::setCode(int code) 
{
this->code=code; 
}

int Item::getCode() 
{
return this->code; 
}

void Item::setName(string name) 
{
this->name=name; 
}

string Item::getName() 
{
return this->name; 
}

void Item::setCategory(char category)
{
this->category=category;
}

char Item::getCategory()
{
return this->category;
}

SerializedStream* Item::serialize()
{
SerializedStream *serializedStream;
int digitCount=Utility::getDigitsCount(this->code);
int size=digitCount+this->name.length()+4;
char *stream=new char[size];
sprintf(stream,"%d",this->code);
strcpy(stream+digitCount+1,this->name.c_str());
*(stream+size-2)=this->category;
*(stream+size-1)='\0';
serializedStream=new SerializedStream(stream,size);
return serializedStream;
}

void Item::deserialize(SerializedStream *serializedStream)
{
this->code=0;
this->name="";
this->category=' ';
if(serializedStream==NULL) return;
const char* stream=serializedStream->getBase();
int size=serializedStream->getSize();
if(stream==NULL) return;
int i=0;
while(stream[i]!='\0')
{
this->code=this->code*10+(stream[i]-48);
i++;
}
this->name=string(stream+i+1);
this->category=*(stream+size-2);
}

void Item::dispose(SerializedStream *serializedStream)
{
const char* base=serializedStream->getBase();
delete [] base;
delete serializedStream;
}

#endif