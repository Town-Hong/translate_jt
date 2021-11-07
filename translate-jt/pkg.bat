set BUILD_NUMBER=%1%
set MODEL_NAME=translate-3dm

if not exist pkg mkdir pkg
del .\pkg\*.* /q/s

xcopy .\bin\vc15\x64\Release\*.dll .\pkg\bin\ /y
xcopy .\bin\vc15\x64\Release\*.exe .\pkg\bin\ /y

cd pkg
echo %BUILD_NUMBER% > .\bin\ver.txt
d:\tools\7z\7z.exe -tZip a %MODEL_NAME%.zip .\bin\*.*

xcopy  %MODEL_NAME%.zip D:\Web\packages\%MODEL_NAME%-dev\%BUILD_NUMBER%\ /y
xcopy  %MODEL_NAME%.zip D:\Web\packages\%MODEL_NAME%-dev\dev\ /y