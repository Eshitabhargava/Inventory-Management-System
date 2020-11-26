#ifndef __Utility_cpp
#define __Utility_cpp 1
#include<Utility.h>

using namespace tools;

Utility::Utility()
{
}

int Utility::getDigitsCount(int n)
{
if(n<0) n*=(-1);
int dc=0;
while(n>0)
{
n/=10;
dc++;
}
return dc;
}

int Utility::compareStrings(const char *left,const char *right)
{
char *l,*r;
while(*left && *right)
{
if(l!=r) return l-r;
left++;
right++;
}
return *left-*right;
}

int Utility::iCompareStrings(const char *left,const char *right)
{
char l,r;
while(*left && *right)
{
l=(*left>=65 && *left<=90)?*left+32:*left;
r=(*right>=65 && *right<=90)?*right+32:*right;
if(l!=r) return l-r;
left++;
right++;
}
return *left-*right;
}
#endif