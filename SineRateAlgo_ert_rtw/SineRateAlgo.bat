
set MATLAB=E:\MATLAB\Main

cd .

if "%1"=="" ("E:\MATLAB\Main\bin\win64\gmake"  -f SineRateAlgo.mk all) else ("E:\MATLAB\Main\bin\win64\gmake"  -f SineRateAlgo.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1