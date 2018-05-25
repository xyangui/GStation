# Microsoft Developer Studio Project File - Name="TF1D" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TF1D - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TF1D.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TF1D.mak" CFG="TF1D - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TF1D - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TF1D - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TF1D - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "TF1D - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"Release/TF1D.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TF1D - Win32 Release"
# Name "TF1D - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\_meter.cpp
# End Source File
# Begin Source File

SOURCE=.\air.cpp
# End Source File
# Begin Source File

SOURCE=.\AirToZeroDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AltSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BTSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ButtonXP.cpp
# End Source File
# Begin Source File

SOURCE=.\commondialog.cpp
# End Source File
# Begin Source File

SOURCE=.\commondialog1.cpp
# End Source File
# Begin Source File

SOURCE=.\Data.cpp
# End Source File
# Begin Source File

SOURCE=.\DownPoints.cpp
# End Source File
# Begin Source File

SOURCE=.\LineComputerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LyersctrDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MAPX.CPP
# End Source File
# Begin Source File

SOURCE=.\mscomm.cpp
# End Source File
# Begin Source File

SOURCE=.\MyMiniFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\PhotoSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\picture.cpp
# End Source File
# Begin Source File

SOURCE=.\PortsetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PotdataDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RangePod.cpp
# End Source File
# Begin Source File

SOURCE=.\SafesetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TF1D.cpp
# End Source File
# Begin Source File

SOURCE=.\TF1D.rc
# End Source File
# Begin Source File

SOURCE=.\TF1DDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\toolBarEX.cpp
# End Source File
# Begin Source File

SOURCE=.\UAVSetDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\_meter.h
# End Source File
# Begin Source File

SOURCE=.\air.h
# End Source File
# Begin Source File

SOURCE=.\AirToZeroDlg.h
# End Source File
# Begin Source File

SOURCE=.\AltSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\BTSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\ButtonXP.h
# End Source File
# Begin Source File

SOURCE=.\commondialog.h
# End Source File
# Begin Source File

SOURCE=.\commondialog1.h
# End Source File
# Begin Source File

SOURCE=.\Data.h
# End Source File
# Begin Source File

SOURCE=.\DownPoints.h
# End Source File
# Begin Source File

SOURCE=.\LineComputerDlg.h
# End Source File
# Begin Source File

SOURCE=.\LyersctrDlg.h
# End Source File
# Begin Source File

SOURCE=.\MAPX.H
# End Source File
# Begin Source File

SOURCE=.\mscomm.h
# End Source File
# Begin Source File

SOURCE=.\MyMiniFrm.h
# End Source File
# Begin Source File

SOURCE=.\PhotoSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\picture.h
# End Source File
# Begin Source File

SOURCE=.\PortsetDlg.h
# End Source File
# Begin Source File

SOURCE=.\PotdataDlg.h
# End Source File
# Begin Source File

SOURCE=.\RangePod.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SafesetDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TF1D.h
# End Source File
# Begin Source File

SOURCE=.\TF1DDlg.h
# End Source File
# Begin Source File

SOURCE=.\toolBarEX.h
# End Source File
# Begin Source File

SOURCE=.\UAVSetDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CASIC.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CASIC1.BMP
# End Source File
# Begin Source File

SOURCE=.\res\CASIC2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CASIC3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00002.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00003.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00004.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00005.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00006.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00007.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00008.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00009.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00010.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00011.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00012.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00013.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon10.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon3.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon4.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon5.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon6.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon8.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon9.ico
# End Source File
# Begin Source File

SOURCE=.\res\LedOff.ico
# End Source File
# Begin Source File

SOURCE=.\res\LedOn.ico
# End Source File
# Begin Source File

SOURCE=.\res\sunbird.ico
# End Source File
# Begin Source File

SOURCE=.\res\TF1D.ico
# End Source File
# Begin Source File

SOURCE=.\res\TF1D.rc2
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\UP20.ico
# End Source File
# Begin Source File

SOURCE=.\res\warning.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\html1.htm
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section TF1D : {083039C2-13F4-11D1-8B7E-0000F8754DA1}
# 	2:5:Class:CCommonDialog2
# 	2:10:HeaderFile:commondialog1.h
# 	2:8:ImplFile:commondialog1.cpp
# End Section
# Section TF1D : {F9043C85-F6F2-101A-A3C9-08002B2F49FB}
# 	2:21:DefaultSinkHeaderFile:commondialog1.h
# 	2:16:DefaultSinkClass:CCommonDialog2
# End Section
