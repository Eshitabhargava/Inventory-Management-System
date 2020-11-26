#ifndef __ObjectInputStream_cpp
#define __ObjectInputStream_cpp 1

#include <ObjectInputStream.h>

using namespace ObjectIO;

ObjectInputStream::ObjectInputStream()
{
lastOperationFailed=false;
file=NULL;
}

ObjectInputStream::ObjectInputStream(const ObjectInputStream &other)
{
lastOperationFailed=false;
this->file=other.file;
}

ObjectInputStream& ObjectInputStream::operator=(const ObjectInputStream &other)
{
//
return *this;
}

ObjectInputStream::~ObjectInputStream()
{
//
}

void ObjectInputStream::open(const char *fileName)
{
lastOperationFailed=false;
if(fileName==NULL)
{
lastOperationFailed=true;
return;
}
this->file=fopen(fileName,"rb");
if(this->file==NULL)
{
lastOperationFailed=true;
}
}

void ObjectInputStream::close()
{
this->lastOperationFailed=false;
if(this->file==NULL)
{
this->lastOperationFailed=true;
return;
}
fclose(this->file);
}              

int ObjectInputStream::failed()
{
return this->lastOperationFailed;
}

void ObjectInputStream::readObject(Serializable *serializable)
{
this->lastOperationFailed=false;
if(this->file=NULL)
{
this->lastOperationFailed=true;
return;
}
struct RowHeader rh;
fread(&rh,sizeof(struct RowHeader),1,this->file);
if(feof(this->file))
{
this->lastOperationFailed=true;
return;
}
char *ptr=new char[rh.recordSize];
fread(ptr,rh.recordSize,1,this->file);
if(feof(file))
{
this->lastOperationFailed=true;
return;
}
SerializedStream *serializedStream=new SerializedStream(ptr,rh.recordSize);
serializable->deserialize(serializedStream);
delete [] ptr;
delete serializedStream;
}

#endif
