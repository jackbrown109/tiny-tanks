@echo off
goto :CopyResources
==========================================================================================
CopyResources
  Usage:
    This script sets copies the required files for the project into the "Build Directory"

  Notes:
   

==========================================================================================
:CopyResources

echo xcopy "%~dp0..\resources\"*.* %1 /s /y /d /r 
xcopy "%~dp0..\resources\"*.* %1 /s /y /d /r 
echo xcopy "%~dp0..\deps\mathLib\dll\%2\mathLib.dll" %1 /s /y /d /r
xcopy "%~dp0..\deps\mathLib\dll\%2\mathLib.dll" %1 /s /y /d /r

@echo off
