#ifndef __Serializable_h
#define __Serializable_h

#include <SerializedStream.h>

namespace ObjectIO
{
class Serializable
{
public:
virtual SerializedStream * serialize()=0;
virtual void deserialize(SerializedStream *)=0;
virtual void dispose(SerializedStream *)=0;
};
}

#endif