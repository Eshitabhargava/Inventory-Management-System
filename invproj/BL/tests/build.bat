g++ -std=c++11 -static %1.cpp -I ..\..\..\Common\include -I ..\..\..\fhlib\include -I ..\..\DL\include -I ..\include -l inventorybl -L ..\lib -l inventoryDL -L ..\..\DL\lib  -l common -L ..\..\..\Common\lib -l fh -L ..\..\..\fhlib\lib -o %1.exe