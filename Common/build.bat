rd /q/s lib
md lib
rd /q/s temp
md temp
g++ -std=c++11 -I include -c src\*.cpp
move *.o temp >trash
del trash
ar rcs lib\common.lib temp\*.o