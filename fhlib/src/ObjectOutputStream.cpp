#ifndef __ObjectOutputStream_cpp
#define __ObjectOutputStream_cpp

#include "ObjectOutputStream.h"

using namespace ObjectIO;

ObjectOutputStream::ObjectOutputStream(const ObjectOutputStream &other)
{
//
}

ObjectOutputStream& ObjectOutputStream::operator=(const ObjectOutputStream& other)
{
//do nothing
return *this;
}

ObjectOutputStream::ObjectOutputStream()
{
file=NULL;
lastOperationFailed=false;
}

ObjectOutputStream::~ObjectOutputStream()
{
//
}

void ObjectOutputStream::openOrCreate(const char *fileName)
{
lastOperationFailed=false;
if(fileName==NULL)
{
lastOperationFailed=true;
return;
}
this->file=fopen(fileName,"ab");
}

void ObjectOutputStream::create(const char *fileName)
{
lastOperationFailed=false;
if(fileName==NULL)
{
lastOperationFailed=true;
return;
}
this->file=fopen(fileName,"wb");
}

void ObjectOutputStream::close()
{
lastOperationFailed=false;
if(this->file==NULL)
{
lastOperationFailed=true;
return;
}
fclose(this->file);
}

void ObjectOutputStream::writeObject(Serializable *serializable)
{
lastOperationFailed=false;
if(this->file==NULL)
{
lastOperationFailed=true;
return;
}
SerializedStream *serializedStream=serializable->serialize();
struct RowHeader rh;
rh.recordSize=serializedStream->getSize();
fwrite(&rh,sizeof(struct RowHeader),1,this->file);
fwrite(serializedStream->getBase(),serializedStream->getSize(),1,this->file);
serializable->dispose(serializedStream);
}

int ObjectOutputStream::failed()
{
return this->lastOperationFailed;
}

#endif