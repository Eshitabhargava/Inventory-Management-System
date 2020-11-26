rd /q/s lib
md lib
rd /q/s temp
md temp
g++ -std=c++11 -I ..\..\Common\include -I ..\..\fhlib\include -I include -c src\*.cpp
move *.o temp >junk
del junk
ar rcs lib\inventorydl.lib temp\*.o