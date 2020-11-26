#ifndef __Item_Header_h
#define __Item_Header_h 1

#include<iostream>
#include <Serializable.h>

using namespace std;
using namespace ObjectIO;

namespace inventory_dl
{
class ItemHeader:public Serializable
{
private:
unsigned int numberOfRecords;
unsigned int lastGeneratedItemCode;

public:
ItemHeader();
ItemHeader(unsigned int numberOfRecords,unsigned int lastGeneratedItemCode);
ItemHeader(const ItemHeader &other);

virtual ~ItemHeader();

ItemHeader& operator=(const ItemHeader &other);

void setNumberOfRecords(unsigned int numberOfRecords);
unsigned int getNumberOfRecords();
void setLastGeneratedItemCode(unsigned int lastGeneratedItemCode);
unsigned int getLastGeneratedItemCode();

SerializedStream* serialize();
void deserialize(SerializedStream *stream);
void dispose(SerializedStream *stream);
};
}

#endif