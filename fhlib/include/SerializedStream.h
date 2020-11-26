#ifndef __SerializedStream_h
#define __SerializedStream_h 1

namespace ObjectIO
{
class SerializedStream
{
private:
const char *base;
unsigned int size;

public:
virtual ~SerializedStream();

SerializedStream(const char *base,unsigned int size);
SerializedStream(const SerializedStream &);

SerializedStream& operator=(const SerializedStream &other);

const char* getBase();
unsigned int getSize();
};
}

#endif