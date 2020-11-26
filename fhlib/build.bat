rd /q/s lib
md lib
rd /q/s temp
md temp
g++ -std=c++11 -I include -I ..\tmcommon\include -c src\FileHandler.cpp src\SerializedStream.cpp
move *.o temp >fhaltu
del fhaltu
ar rcs lib\tmfh.lib temp\FileHandler.o temp\SerializedStream.o