@echo off
set path=C:\Windows\Microsoft.NET\Framework64\v4.0.30319
MSBuild test.vcxproj /p:Configuration=Release,Platform=x64
del *.obj,*.iobj,*.pdb,*.ipdb
for /d %%d in (*) do rmdir /s/q .\"%%d"
pause