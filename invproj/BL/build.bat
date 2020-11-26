@echo off
rd /q/s lib
md lib
rd /q/s temp
md temp
g++ -std=c++11 -I ..\..\Common\include -I ..\..\fhlib\include -I ..\DL\include -I include -c src\*.cpp
move *.o temp >trash
del trash
ar rcs lib\inventorybl.lib temp\*.o