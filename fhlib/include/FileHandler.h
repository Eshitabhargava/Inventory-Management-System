#ifndef ___FileHandler_h
#define ___FileHandler_h 1

#include <Serializable.h>
#include <SerializedStream.h>
#include<string.h>
#include<stdio.h>
#include<iostream>

using namespace std;

namespace ObjectIO
{
class FileHandler
{
struct RowHeader
{
int recordSize;
};
FILE *file;
int _failed;
string fileName;

public:

FileHandler();
FileHandler(string fileName);
FileHandler(const FileHandler &other);

virtual ~FileHandler();

FileHandler& operator=(const FileHandler &other);

void open(string fileName);
void close();
void seek(int position);
int length();
void read(Serializable *serializable);
void write(Serializable *serializable);
string  getFileName();
int failed();
int getPosition();
void setLength(int length);
};
}
#endif





