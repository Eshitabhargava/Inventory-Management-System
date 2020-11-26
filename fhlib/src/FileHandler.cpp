#ifndef __FileHandler_cpp
#define __FileHandler_cpp

#include<iostream>
#include<stdio.h>
#include <FileHandler.h>

using namespace ObjectIO;
using namespace std;

FileHandler::FileHandler()
{
this->fileName="";
this->_failed=false;
this->file=NULL;
}

FileHandler::FileHandler(string fileName)
{
this->fileName="";
this->_failed=false;
this->file=NULL;
this->open(fileName);
}

FileHandler::FileHandler(const FileHandler &other)
{
// do nothing
}

FileHandler::~FileHandler()
{
if(this->file)
{
fclose(this->file);
}
}

FileHandler& FileHandler::operator=(const FileHandler &other)
{
//do nothing
return *this;
}

void FileHandler::open(string fileName)
{
if(this->file)
{
fclose(this->file);
this->file=NULL;
this->fileName="";
this->_failed=false;
}
if(fileName.length()==0)
{
this->_failed=true;
return;
}
this->file=fopen(fileName.c_str(),"rb+");
if(this->file==NULL)
{
this->file=fopen(fileName.c_str(),"w");
if(this->file)
{
fclose(this->file);
this->file=fopen(fileName.c_str(),"rb+");
}
}
if(this->file==NULL)
{
this->_failed=true;
return;
}
this->fileName=fileName;
this->_failed=false;
}

void FileHandler::close()
{
if(this->file)
{
fclose(this->file);
this->file=NULL;
this->fileName="";
}
this->_failed=false;
}

void FileHandler::seek(int position)
{
if(this->file==NULL)
{
this->_failed=true;
return;
}
fseek(this->file,position,0);
}

int FileHandler::length()
{
if(this->file==NULL)
{
this->_failed=true;
return -1;
}
int len,cpos;
cpos=ftell(this->file);
fseek(this->file,0,2);
len=ftell(this->file);
fseek(this->file,cpos,0);
return len;
}

void FileHandler::read(Serializable *serializable)
{
this->_failed=false;
if(this->file==NULL)
{
this->_failed=true;
return;
}
struct RowHeader rh;
fread(&rh,sizeof(RowHeader),1,this->file);
if(feof(this->file))
{
this->_failed=true;
return;
}
char *ptr=new char[rh.recordSize];
fread(ptr,rh.recordSize,1,this->file);
if(feof(this->file))
{
this->_failed=true;
return;
}
SerializedStream *serializedStream=new SerializedStream(ptr,rh.recordSize);
serializable->deserialize(serializedStream);
delete [] ptr;
delete serializedStream;
}

void FileHandler::write(Serializable *serializable)
{
this->_failed=false;
if(this->file==NULL)
{
this->_failed=true;
return;
}
SerializedStream *serializedStream=serializable->serialize();
struct RowHeader rh;
rh.recordSize=serializedStream->getSize();
fwrite(&rh,sizeof(struct RowHeader),1,this->file);
fwrite(serializedStream->getBase(),serializedStream->getSize(),1,this->file);
serializable->dispose(serializedStream);
}

string  FileHandler::getFileName()
{
return this->fileName;
}

int FileHandler::failed()          
{
return this->_failed;
}

void FileHandler::setLength(int len)
{
if(this->file==NULL) return;
this->_failed=false;
int m=this->length();
if(len>m)
{
this->_failed=true;
return;
}
if(len==m) return;
int currentPosition=this->getPosition();
FILE *tmpFile;
char *tmpName=tmpnam(NULL);
tmpFile=fopen(tmpName+1,"wb+");
this->seek(0);
int j=0;
char buffer[1024];
int bufferSize=1024;
while(j<len)
{
if((j+bufferSize)>len)
{
bufferSize=len-j;
}
fread(buffer,bufferSize,1,this->file);
fwrite(buffer,bufferSize,1,tmpFile);
j=j+bufferSize;
}
fclose(this->file);
fclose(tmpFile);
remove(this->fileName.c_str());
rename(tmpName+1,this->fileName.c_str());
this->open(this->fileName);
if(currentPosition>=len)
{
fseek(this->file,0,2);
}
else
{
fseek(this->file,currentPosition,0);
}
}

int FileHandler::getPosition()
{
if(this->file)
{
return ftell(this->file);
}
return -1;
}

#endif           