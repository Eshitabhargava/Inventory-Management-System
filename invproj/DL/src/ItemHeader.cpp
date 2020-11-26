#ifndef __ItemHeader_cpp
#define __ItemHeader_cpp 1

#include <dl\ItemHeader.h>
#include <Serializable.h>
#include <SerializedStream.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace inventory_dl;
using namespace ObjectIO;
using namespace std;

ItemHeader::ItemHeader()
{
this->numberOfRecords=0;
this->lastGeneratedItemCode=0;
}

ItemHeader::ItemHeader(unsigned int numberOfRecords,unsigned int lastGeneratedItemCode)
{
this->numberOfRecords=numberOfRecords;
this->lastGeneratedItemCode=lastGeneratedItemCode;
}

ItemHeader::ItemHeader(const ItemHeader &other)
{
this->numberOfRecords=other.numberOfRecords;
this->lastGeneratedItemCode=other.lastGeneratedItemCode;
}

ItemHeader::~ItemHeader()
{
//do nothing
}

ItemHeader& ItemHeader::operator=(const ItemHeader &other)
{
this->numberOfRecords=other.numberOfRecords;
this->lastGeneratedItemCode=other.lastGeneratedItemCode;
return *this;
}

void ItemHeader::setNumberOfRecords(unsigned int numberOfRecords)
{
this->numberOfRecords=numberOfRecords;
}

unsigned int ItemHeader::getNumberOfRecords()
{
return this->numberOfRecords;
}

void ItemHeader::setLastGeneratedItemCode(unsigned int lastGeneratedItemCode)
{
this->lastGeneratedItemCode=lastGeneratedItemCode;
}

unsigned int ItemHeader::getLastGeneratedItemCode()
{
return this->lastGeneratedItemCode;
}

SerializedStream* ItemHeader::serialize()
{
char *str=new char[22];
sprintf(str,"%10d",numberOfRecords);
sprintf(str+11,"%10d",this->lastGeneratedItemCode);
SerializedStream *serializedStream= new SerializedStream(str,22);
return serializedStream;
}

void ItemHeader::deserialize(SerializedStream *serializedStream)
{
const char *str=serializedStream->getBase();
numberOfRecords=0;
lastGeneratedItemCode=0;
char a[22];
strcpy(a,str);
strcpy(a+11,str+11);
int i=0;
while(a[i]==' ')
{
i++;
}
while(a[i]!='\0')
{
numberOfRecords=numberOfRecords*10+(a[i]-48);
i++;
}
i++;
while(a[i]==' ')
{
i++;
}
while(a[i]!='\0')
{
lastGeneratedItemCode=lastGeneratedItemCode*10+(a[i]-48);
i++;
}
}

void ItemHeader::dispose(SerializedStream *stream)
{
const char *ptr=stream->getBase();
delete [] ptr;
delete stream;
}
#endif