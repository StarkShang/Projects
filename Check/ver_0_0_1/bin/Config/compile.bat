@echo off
set path=%path%;C:\Softwares\Microsoft Visual Studio 14.0\VC\bin\amd64;C:\Softwares\Microsoft Visual Studio 14.0\Common7\IDE
set include=C:\Softwares\Microsoft Visual Studio 14.0\VC\include;C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include;C:\Program Files (x86)\Windows Kits\10\Include\10.0.14393.0\ucrt
set lib=C:\Softwares\Microsoft Visual Studio 14.0\VC\lib\amd64;C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib\x64;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.14393.0\ucrt\x64
cl.exe /EHsc /Femain ..\Config\main.cpp ..\Config\test.cpp
del main.obj test.obj
move .\main.exe ..\Config\main.exe