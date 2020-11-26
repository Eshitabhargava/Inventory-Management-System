#ifndef __Utility_h
#define __Utility_h 1

namespace tools
{
class Utility
{
private:
Utility();

public:
static int getDigitsCount(int n);
static int compareStrings(const char *left,const char *right);
static int iCompareStrings(const char *left,const char *right);
};
}

#endif