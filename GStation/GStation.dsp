# Microsoft Developer Studio Project File - Name="GStation" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=GStation - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GStation.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GStation.mak" CFG="GStation - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GStation - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GStation - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GStation - Win32 Release"

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

!ELSEIF  "$(CFG)" == "GStation - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "GStation - Win32 Release"
# Name "GStation - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "ShowCPP"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\DlgToolBar.cpp
# End Source File
# Begin Source File

SOURCE=.\IniFile.cpp
# End Source File
# Begin Source File

SOURCE=.\StaticStatus.cpp
# End Source File
# End Group
# Begin Group "SettingCPP"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\SetAirSpeed.cpp
# End Source File
# Begin Source File

SOURCE=.\SetAltitude.cpp
# End Source File
# Begin Source File

SOURCE=.\SetInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\SetPhoto.cpp
# End Source File
# Begin Source File

SOURCE=.\SetPitchRoll.cpp
# End Source File
# Begin Source File

SOURCE=.\SetSafe.cpp
# End Source File
# Begin Source File

SOURCE=.\SetSerialport.cpp
# End Source File
# Begin Source File

SOURCE=.\SetSetUp.cpp
# End Source File
# Begin Source File

SOURCE=.\SetSteeringEngine.cpp
# End Source File
# Begin Source File

SOURCE=.\Setting.cpp
# End Source File
# Begin Source File

SOURCE=.\SetVersion.cpp
# End Source File
# End Group
# Begin Group "PacketCPP"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CRC.cpp
# End Source File
# Begin Source File

SOURCE=.\Message.cpp
# End Source File
# Begin Source File

SOURCE=.\Msg_Capture.cpp
# End Source File
# Begin Source File

SOURCE=.\Msg_OtherPIDAdjData.cpp
# End Source File
# Begin Source File

SOURCE=.\Msg_PhotoData.cpp
# End Source File
# Begin Source File

SOURCE=.\Msg_PhotoMode.cpp
# End Source File
# Begin Source File

SOURCE=.\Msg_PhotoNum.cpp
# End Source File
# Begin Source File

SOURCE=.\Msg_PIDAdjustData.cpp
# End Source File
# Begin Source File

SOURCE=.\Msg_PIDData.cpp
# End Source File
# Begin Source File

SOURCE=.\Msg_SetRPV.cpp
# End Source File
# Begin Source File

SOURCE=.\Msg_Telemetry.cpp
# End Source File
# Begin Source File

SOURCE=.\Msg_WayPoint.cpp
# End Source File
# Begin Source File

SOURCE=.\Packet.cpp
# End Source File
# Begin Source File

SOURCE=.\Parser.cpp
# End Source File
# Begin Source File

SOURCE=.\Payload.cpp
# End Source File
# End Group
# Begin Group "XListCtrlCPP"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\XListCtrl\XComboList.cpp
# End Source File
# Begin Source File

SOURCE=.\XListCtrl\XHeaderCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XListCtrl\XListCtrl.cpp
# End Source File
# End Group
# Begin Group "DownDataCPP"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\DownGPSDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DownMiddleDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DownSensorDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DownSteeringDlg.cpp
# End Source File
# End Group
# Begin Group "PIDTeeChartProActivex"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\adxfunction.cpp
# End Source File
# Begin Source File

SOURCE=.\annotationtool.cpp
# End Source File
# Begin Source File

SOURCE=.\areaseries.cpp
# End Source File
# Begin Source File

SOURCE=.\arrowseries.cpp
# End Source File
# Begin Source File

SOURCE=.\aspect.cpp
# End Source File
# Begin Source File

SOURCE=.\averagefunction.cpp
# End Source File
# Begin Source File

SOURCE=.\axes.cpp
# End Source File
# Begin Source File

SOURCE=.\axis.cpp
# End Source File
# Begin Source File

SOURCE=.\axisarrowtool.cpp
# End Source File
# Begin Source File

SOURCE=.\axislabels.cpp
# End Source File
# Begin Source File

SOURCE=.\axistitle.cpp
# End Source File
# Begin Source File

SOURCE=.\bar3dseries.cpp
# End Source File
# Begin Source File

SOURCE=.\barjoinseries.cpp
# End Source File
# Begin Source File

SOURCE=.\barseries.cpp
# End Source File
# Begin Source File

SOURCE=.\bezierseries.cpp
# End Source File
# Begin Source File

SOURCE=.\bmpexport.cpp
# End Source File
# Begin Source File

SOURCE=.\bollingerfunction.cpp
# End Source File
# Begin Source File

SOURCE=.\boxplotseries.cpp
# End Source File
# Begin Source File

SOURCE=.\brush.cpp
# End Source File
# Begin Source File

SOURCE=.\bubbleseries.cpp
# End Source File
# Begin Source File

SOURCE=.\calendarcell.cpp
# End Source File
# Begin Source File

SOURCE=.\calendarcellupper.cpp
# End Source File
# Begin Source File

SOURCE=.\calendarseries.cpp
# End Source File
# Begin Source File

SOURCE=.\candleseries.cpp
# End Source File
# Begin Source File

SOURCE=.\canvas.cpp
# End Source File
# Begin Source File

SOURCE=.\chartfont.cpp
# End Source File
# Begin Source File

SOURCE=.\chartimagetool.cpp
# End Source File
# Begin Source File

SOURCE=.\circlelabels.cpp
# End Source File
# Begin Source File

SOURCE=.\clockseries.cpp
# End Source File
# Begin Source File

SOURCE=.\colorbandtool.cpp
# End Source File
# Begin Source File

SOURCE=.\colorgridseries.cpp
# End Source File
# Begin Source File

SOURCE=.\colorlinetool.cpp
# End Source File
# Begin Source File

SOURCE=.\contourlevel.cpp
# End Source File
# Begin Source File

SOURCE=.\contourlevels.cpp
# End Source File
# Begin Source File

SOURCE=.\contourseries.cpp
# End Source File
# Begin Source File

SOURCE=.\cursortool.cpp
# End Source File
# Begin Source File

SOURCE=.\curvefittingfunction.cpp
# End Source File
# Begin Source File

SOURCE=.\donutseries.cpp
# End Source File
# Begin Source File

SOURCE=.\dragmarkstool.cpp
# End Source File
# Begin Source File

SOURCE=.\drawline.cpp
# End Source File
# Begin Source File

SOURCE=.\drawlinelist.cpp
# End Source File
# Begin Source File

SOURCE=.\drawlinetool.cpp
# End Source File
# Begin Source File

SOURCE=.\environment.cpp
# End Source File
# Begin Source File

SOURCE=.\errorbarseries.cpp
# End Source File
# Begin Source File

SOURCE=.\errorseries.cpp
# End Source File
# Begin Source File

SOURCE=.\expavgfunction.cpp
# End Source File
# Begin Source File

SOURCE=.\explodedslices.cpp
# End Source File
# Begin Source File

SOURCE=.\export.cpp
# End Source File
# Begin Source File

SOURCE=.\fastlineseries.cpp
# End Source File
# Begin Source File

SOURCE=.\funnelseries.cpp
# End Source File
# Begin Source File

SOURCE=.\ganttseries.cpp
# End Source File
# Begin Source File

SOURCE=.\gifexport.cpp
# End Source File
# Begin Source File

SOURCE=.\gradient.cpp
# End Source File
# Begin Source File

SOURCE=.\highlowseries.cpp
# End Source File
# Begin Source File

SOURCE=.\histogramseries.cpp
# End Source File
# Begin Source File

SOURCE=.\horizbarseries.cpp
# End Source File
# Begin Source File

SOURCE=.\horizboxplotseries.cpp
# End Source File
# Begin Source File

SOURCE=.\horizlineseries.cpp
# End Source File
# Begin Source File

SOURCE=.\htmlexport.cpp
# End Source File
# Begin Source File

SOURCE=.\imagebarseries.cpp
# End Source File
# Begin Source File

SOURCE=.\import.cpp
# End Source File
# Begin Source File

SOURCE=.\jpegexport.cpp
# End Source File
# Begin Source File

SOURCE=.\legend.cpp
# End Source File
# Begin Source File

SOURCE=.\legendsymbol.cpp
# End Source File
# Begin Source File

SOURCE=.\lineseries.cpp
# End Source File
# Begin Source File

SOURCE=.\macdfunction.cpp
# End Source File
# Begin Source File

SOURCE=.\mappolygon.cpp
# End Source File
# Begin Source File

SOURCE=.\mappolygonlist.cpp
# End Source File
# Begin Source File

SOURCE=.\mapseries.cpp
# End Source File
# Begin Source File

SOURCE=.\marks.cpp
# End Source File
# Begin Source File

SOURCE=.\markstiptool.cpp
# End Source File
# Begin Source File

SOURCE=.\metafileexport.cpp
# End Source File
# Begin Source File

SOURCE=.\movingavgfunction.cpp
# End Source File
# Begin Source File

SOURCE=.\nativeexport.cpp
# End Source File
# Begin Source File

SOURCE=.\nearesttool.cpp
# End Source File
# Begin Source File

SOURCE=.\page.cpp
# End Source File
# Begin Source File

SOURCE=.\pagenumtool.cpp
# End Source File
# Begin Source File

SOURCE=.\panel.cpp
# End Source File
# Begin Source File

SOURCE=.\pcxexport.cpp
# End Source File
# Begin Source File

SOURCE=.\pen.cpp
# End Source File
# Begin Source File

SOURCE=.\pieotherslice.cpp
# End Source File
# Begin Source File

SOURCE=.\pieseries.cpp
# End Source File
# Begin Source File

SOURCE=.\pngexport.cpp
# End Source File
# Begin Source File

SOURCE=.\point3dseries.cpp
# End Source File
# Begin Source File

SOURCE=.\pointer.cpp
# End Source File
# Begin Source File

SOURCE=.\pointseries.cpp
# End Source File
# Begin Source File

SOURCE=.\polarseries.cpp
# End Source File
# Begin Source File

SOURCE=.\printer.cpp
# End Source File
# Begin Source File

SOURCE=.\pyramidseries.cpp
# End Source File
# Begin Source File

SOURCE=.\radarseries.cpp
# End Source File
# Begin Source File

SOURCE=.\rmsfunction.cpp
# End Source File
# Begin Source File

SOURCE=.\rotatetool.cpp
# End Source File
# Begin Source File

SOURCE=.\rsifunction.cpp
# End Source File
# Begin Source File

SOURCE=.\scroll.cpp
# End Source File
# Begin Source File

SOURCE=.\series.cpp
# End Source File
# Begin Source File

SOURCE=.\seriesmarkposition.cpp
# End Source File
# Begin Source File

SOURCE=.\seriesmarkspositions.cpp
# End Source File
# Begin Source File

SOURCE=.\shapeseries.cpp
# End Source File
# Begin Source File

SOURCE=.\smithseries.cpp
# End Source File
# Begin Source File

SOURCE=.\stddeviationfunction.cpp
# End Source File
# Begin Source File

SOURCE=.\strings.cpp
# End Source File
# Begin Source File

SOURCE=.\surfaceseries.cpp
# End Source File
# Begin Source File

SOURCE=.\tchart.cpp
# End Source File
# Begin Source File

SOURCE=.\teefont.cpp
# End Source File
# Begin Source File

SOURCE=.\teefunction.cpp
# End Source File
# Begin Source File

SOURCE=.\teeopengl.cpp
# End Source File
# Begin Source File

SOURCE=.\teepoint2d.cpp
# End Source File
# Begin Source File

SOURCE=.\teepoint3d.cpp
# End Source File
# Begin Source File

SOURCE=.\teeshadow.cpp
# End Source File
# Begin Source File

SOURCE=.\teeshapepanel.cpp
# End Source File
# Begin Source File

SOURCE=.\textexport.cpp
# End Source File
# Begin Source File

SOURCE=.\titles.cpp
# End Source File
# Begin Source File

SOURCE=.\toollist.cpp
# End Source File
# Begin Source File

SOURCE=.\tools.cpp
# End Source File
# Begin Source File

SOURCE=.\trisurfaceseries.cpp
# End Source File
# Begin Source File

SOURCE=.\valuelist.cpp
# End Source File
# Begin Source File

SOURCE=.\valuelists.cpp
# End Source File
# Begin Source File

SOURCE=.\volumeseries.cpp
# End Source File
# Begin Source File

SOURCE=.\wall.cpp
# End Source File
# Begin Source File

SOURCE=.\walls.cpp
# End Source File
# Begin Source File

SOURCE=.\waterfallseries.cpp
# End Source File
# Begin Source File

SOURCE=.\windroseseries.cpp
# End Source File
# Begin Source File

SOURCE=.\xlsexport.cpp
# End Source File
# Begin Source File

SOURCE=.\xmlexport.cpp
# End Source File
# Begin Source File

SOURCE=.\zoom.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\commondialog.cpp
# End Source File
# Begin Source File

SOURCE=.\DownPhotoDataDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FlyGPSPointRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\GStation.cpp
# End Source File
# Begin Source File

SOURCE=.\GStation.rc
# End Source File
# Begin Source File

SOURCE=.\GStationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\instrumentcircle.cpp
# End Source File
# Begin Source File

SOURCE=.\instrumentpanel.cpp
# End Source File
# Begin Source File

SOURCE=.\LayerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MAPX.CPP
# End Source File
# Begin Source File

SOURCE=.\mscomm.cpp
# End Source File
# Begin Source File

SOURCE=.\PIDAdjDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PlaneUAV.cpp
# End Source File
# Begin Source File

SOURCE=.\SignDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TakeOffCheck.cpp
# End Source File
# Begin Source File

SOURCE=.\WayPointDownDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WayPointEditDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WayPointShowDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WayPointUpDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "ShowH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\DlgToolBar.h
# End Source File
# Begin Source File

SOURCE=.\IniFile.h
# End Source File
# Begin Source File

SOURCE=.\StaticStatus.h
# End Source File
# End Group
# Begin Group "SettingH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\SetAirSpeed.h
# End Source File
# Begin Source File

SOURCE=.\SetAltitude.h
# End Source File
# Begin Source File

SOURCE=.\SetInterface.h
# End Source File
# Begin Source File

SOURCE=.\SetPhoto.h
# End Source File
# Begin Source File

SOURCE=.\SetPitchRoll.h
# End Source File
# Begin Source File

SOURCE=.\SetSafe.h
# End Source File
# Begin Source File

SOURCE=.\SetSerialport.h
# End Source File
# Begin Source File

SOURCE=.\SetSetUp.h
# End Source File
# Begin Source File

SOURCE=.\SetSteeringEngine.h
# End Source File
# Begin Source File

SOURCE=.\Setting.h
# End Source File
# Begin Source File

SOURCE=.\SetVersion.h
# End Source File
# End Group
# Begin Group "PacketH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CRC.h
# End Source File
# Begin Source File

SOURCE=.\Message.h
# End Source File
# Begin Source File

SOURCE=.\Msg_Capture.h
# End Source File
# Begin Source File

SOURCE=.\Msg_OtherPIDAdjData.h
# End Source File
# Begin Source File

SOURCE=.\Msg_PhotoData.h
# End Source File
# Begin Source File

SOURCE=.\Msg_PhotoMode.h
# End Source File
# Begin Source File

SOURCE=.\Msg_PhotoNum.h
# End Source File
# Begin Source File

SOURCE=.\Msg_PIDAdjustData.h
# End Source File
# Begin Source File

SOURCE=.\Msg_PIDData.h
# End Source File
# Begin Source File

SOURCE=.\Msg_SetRPV.h
# End Source File
# Begin Source File

SOURCE=.\Msg_Telemetry.h
# End Source File
# Begin Source File

SOURCE=.\Msg_WayPoint.h
# End Source File
# Begin Source File

SOURCE=.\Packet.h
# End Source File
# Begin Source File

SOURCE=.\Parser.h
# End Source File
# Begin Source File

SOURCE=.\Payload.h
# End Source File
# End Group
# Begin Group "XListCtrlH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\XListCtrl\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\XListCtrl\XComboList.h
# End Source File
# Begin Source File

SOURCE=.\XListCtrl\XHeaderCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XListCtrl\XListCtrl.h
# End Source File
# End Group
# Begin Group "DownDataH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\DownGPSDlg.h
# End Source File
# Begin Source File

SOURCE=.\DownMiddleDlg.h
# End Source File
# Begin Source File

SOURCE=.\DownSensorDlg.h
# End Source File
# Begin Source File

SOURCE=.\DownSteeringDlg.h
# End Source File
# End Group
# Begin Group "PIDTeeChartProActivexH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\adxfunction.h
# End Source File
# Begin Source File

SOURCE=.\annotationtool.h
# End Source File
# Begin Source File

SOURCE=.\areaseries.h
# End Source File
# Begin Source File

SOURCE=.\arrowseries.h
# End Source File
# Begin Source File

SOURCE=.\aspect.h
# End Source File
# Begin Source File

SOURCE=.\averagefunction.h
# End Source File
# Begin Source File

SOURCE=.\axes.h
# End Source File
# Begin Source File

SOURCE=.\axis.h
# End Source File
# Begin Source File

SOURCE=.\axisarrowtool.h
# End Source File
# Begin Source File

SOURCE=.\axislabels.h
# End Source File
# Begin Source File

SOURCE=.\axistitle.h
# End Source File
# Begin Source File

SOURCE=.\bar3dseries.h
# End Source File
# Begin Source File

SOURCE=.\barjoinseries.h
# End Source File
# Begin Source File

SOURCE=.\barseries.h
# End Source File
# Begin Source File

SOURCE=.\bezierseries.h
# End Source File
# Begin Source File

SOURCE=.\bmpexport.h
# End Source File
# Begin Source File

SOURCE=.\bollingerfunction.h
# End Source File
# Begin Source File

SOURCE=.\boxplotseries.h
# End Source File
# Begin Source File

SOURCE=.\brush.h
# End Source File
# Begin Source File

SOURCE=.\bubbleseries.h
# End Source File
# Begin Source File

SOURCE=.\calendarcell.h
# End Source File
# Begin Source File

SOURCE=.\calendarcellupper.h
# End Source File
# Begin Source File

SOURCE=.\calendarseries.h
# End Source File
# Begin Source File

SOURCE=.\candleseries.h
# End Source File
# Begin Source File

SOURCE=.\canvas.h
# End Source File
# Begin Source File

SOURCE=.\chartfont.h
# End Source File
# Begin Source File

SOURCE=.\chartimagetool.h
# End Source File
# Begin Source File

SOURCE=.\circlelabels.h
# End Source File
# Begin Source File

SOURCE=.\clockseries.h
# End Source File
# Begin Source File

SOURCE=.\colorbandtool.h
# End Source File
# Begin Source File

SOURCE=.\colorgridseries.h
# End Source File
# Begin Source File

SOURCE=.\colorlinetool.h
# End Source File
# Begin Source File

SOURCE=.\contourlevel.h
# End Source File
# Begin Source File

SOURCE=.\contourlevels.h
# End Source File
# Begin Source File

SOURCE=.\contourseries.h
# End Source File
# Begin Source File

SOURCE=.\cursortool.h
# End Source File
# Begin Source File

SOURCE=.\curvefittingfunction.h
# End Source File
# Begin Source File

SOURCE=.\donutseries.h
# End Source File
# Begin Source File

SOURCE=.\dragmarkstool.h
# End Source File
# Begin Source File

SOURCE=.\drawline.h
# End Source File
# Begin Source File

SOURCE=.\drawlinelist.h
# End Source File
# Begin Source File

SOURCE=.\drawlinetool.h
# End Source File
# Begin Source File

SOURCE=.\environment.h
# End Source File
# Begin Source File

SOURCE=.\errorbarseries.h
# End Source File
# Begin Source File

SOURCE=.\errorseries.h
# End Source File
# Begin Source File

SOURCE=.\expavgfunction.h
# End Source File
# Begin Source File

SOURCE=.\explodedslices.h
# End Source File
# Begin Source File

SOURCE=.\export.h
# End Source File
# Begin Source File

SOURCE=.\fastlineseries.h
# End Source File
# Begin Source File

SOURCE=.\funnelseries.h
# End Source File
# Begin Source File

SOURCE=.\ganttseries.h
# End Source File
# Begin Source File

SOURCE=.\gifexport.h
# End Source File
# Begin Source File

SOURCE=.\gradient.h
# End Source File
# Begin Source File

SOURCE=.\highlowseries.h
# End Source File
# Begin Source File

SOURCE=.\histogramseries.h
# End Source File
# Begin Source File

SOURCE=.\horizbarseries.h
# End Source File
# Begin Source File

SOURCE=.\horizboxplotseries.h
# End Source File
# Begin Source File

SOURCE=.\horizlineseries.h
# End Source File
# Begin Source File

SOURCE=.\htmlexport.h
# End Source File
# Begin Source File

SOURCE=.\imagebarseries.h
# End Source File
# Begin Source File

SOURCE=.\import.h
# End Source File
# Begin Source File

SOURCE=.\jpegexport.h
# End Source File
# Begin Source File

SOURCE=.\legend.h
# End Source File
# Begin Source File

SOURCE=.\legendsymbol.h
# End Source File
# Begin Source File

SOURCE=.\lineseries.h
# End Source File
# Begin Source File

SOURCE=.\macdfunction.h
# End Source File
# Begin Source File

SOURCE=.\mappolygon.h
# End Source File
# Begin Source File

SOURCE=.\mappolygonlist.h
# End Source File
# Begin Source File

SOURCE=.\mapseries.h
# End Source File
# Begin Source File

SOURCE=.\marks.h
# End Source File
# Begin Source File

SOURCE=.\markstiptool.h
# End Source File
# Begin Source File

SOURCE=.\metafileexport.h
# End Source File
# Begin Source File

SOURCE=.\movingavgfunction.h
# End Source File
# Begin Source File

SOURCE=.\nativeexport.h
# End Source File
# Begin Source File

SOURCE=.\nearesttool.h
# End Source File
# Begin Source File

SOURCE=.\page.h
# End Source File
# Begin Source File

SOURCE=.\pagenumtool.h
# End Source File
# Begin Source File

SOURCE=.\panel.h
# End Source File
# Begin Source File

SOURCE=.\pcxexport.h
# End Source File
# Begin Source File

SOURCE=.\pen.h
# End Source File
# Begin Source File

SOURCE=.\pieotherslice.h
# End Source File
# Begin Source File

SOURCE=.\pieseries.h
# End Source File
# Begin Source File

SOURCE=.\pngexport.h
# End Source File
# Begin Source File

SOURCE=.\point3dseries.h
# End Source File
# Begin Source File

SOURCE=.\pointer.h
# End Source File
# Begin Source File

SOURCE=.\pointseries.h
# End Source File
# Begin Source File

SOURCE=.\polarseries.h
# End Source File
# Begin Source File

SOURCE=.\printer.h
# End Source File
# Begin Source File

SOURCE=.\pyramidseries.h
# End Source File
# Begin Source File

SOURCE=.\radarseries.h
# End Source File
# Begin Source File

SOURCE=.\rmsfunction.h
# End Source File
# Begin Source File

SOURCE=.\rotatetool.h
# End Source File
# Begin Source File

SOURCE=.\rsifunction.h
# End Source File
# Begin Source File

SOURCE=.\scroll.h
# End Source File
# Begin Source File

SOURCE=.\series.h
# End Source File
# Begin Source File

SOURCE=.\seriesmarkposition.h
# End Source File
# Begin Source File

SOURCE=.\seriesmarkspositions.h
# End Source File
# Begin Source File

SOURCE=.\shapeseries.h
# End Source File
# Begin Source File

SOURCE=.\smithseries.h
# End Source File
# Begin Source File

SOURCE=.\stddeviationfunction.h
# End Source File
# Begin Source File

SOURCE=.\strings.h
# End Source File
# Begin Source File

SOURCE=.\surfaceseries.h
# End Source File
# Begin Source File

SOURCE=.\tchart.h
# End Source File
# Begin Source File

SOURCE=.\teefont.h
# End Source File
# Begin Source File

SOURCE=.\teefunction.h
# End Source File
# Begin Source File

SOURCE=.\teeopengl.h
# End Source File
# Begin Source File

SOURCE=.\teepoint2d.h
# End Source File
# Begin Source File

SOURCE=.\teepoint3d.h
# End Source File
# Begin Source File

SOURCE=.\teeshadow.h
# End Source File
# Begin Source File

SOURCE=.\teeshapepanel.h
# End Source File
# Begin Source File

SOURCE=.\textexport.h
# End Source File
# Begin Source File

SOURCE=.\titles.h
# End Source File
# Begin Source File

SOURCE=.\toollist.h
# End Source File
# Begin Source File

SOURCE=.\tools.h
# End Source File
# Begin Source File

SOURCE=.\trisurfaceseries.h
# End Source File
# Begin Source File

SOURCE=.\valuelist.h
# End Source File
# Begin Source File

SOURCE=.\valuelists.h
# End Source File
# Begin Source File

SOURCE=.\volumeseries.h
# End Source File
# Begin Source File

SOURCE=.\wall.h
# End Source File
# Begin Source File

SOURCE=.\walls.h
# End Source File
# Begin Source File

SOURCE=.\waterfallseries.h
# End Source File
# Begin Source File

SOURCE=.\windroseseries.h
# End Source File
# Begin Source File

SOURCE=.\xlsexport.h
# End Source File
# Begin Source File

SOURCE=.\xmlexport.h
# End Source File
# Begin Source File

SOURCE=.\zoom.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\commondialog.h
# End Source File
# Begin Source File

SOURCE=.\DownPhotoDataDlg.h
# End Source File
# Begin Source File

SOURCE=.\FlyGPSPointRecord.h
# End Source File
# Begin Source File

SOURCE=.\GStation.h
# End Source File
# Begin Source File

SOURCE=.\GStationDlg.h
# End Source File
# Begin Source File

SOURCE=.\instrumentcircle.h
# End Source File
# Begin Source File

SOURCE=.\instrumentpanel.h
# End Source File
# Begin Source File

SOURCE=.\LayerDlg.h
# End Source File
# Begin Source File

SOURCE=.\MAPX.H
# End Source File
# Begin Source File

SOURCE=.\mscomm.h
# End Source File
# Begin Source File

SOURCE=.\PIDAdjDlg.h
# End Source File
# Begin Source File

SOURCE=.\PlaneUAV.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SignDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TakeOffCheck.h
# End Source File
# Begin Source File

SOURCE=.\WayPointDownDlg.h
# End Source File
# Begin Source File

SOURCE=.\WayPointEditDlg.h
# End Source File
# Begin Source File

SOURCE=.\WayPointShowDlg.h
# End Source File
# Begin Source File

SOURCE=.\WayPointUpDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\016.bmp
# End Source File
# Begin Source File

SOURCE=".\res\XYG\3-1.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Center.ico
# End Source File
# Begin Source File

SOURCE=.\res\checkboxes.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CleanTrack.ico
# End Source File
# Begin Source File

SOURCE=.\res\CleanUAVWayPoint.ico
# End Source File
# Begin Source File

SOURCE=.\res\CopyUAVWayPoint.ico
# End Source File
# Begin Source File

SOURCE=.\res\CPV.ico
# End Source File
# Begin Source File

SOURCE=.\res\Distance.ico
# End Source File
# Begin Source File

SOURCE=.\res\down_way.ico
# End Source File
# Begin Source File

SOURCE=.\res\DownPhotoData.ico
# End Source File
# Begin Source File

SOURCE=.\res\DownWayPoint.ico
# End Source File
# Begin Source File

SOURCE=.\res\GStation.ico
# End Source File
# Begin Source File

SOURCE=.\res\GStation.rc2
# End Source File
# Begin Source File

SOURCE=.\res\HandPhotoOne.ico
# End Source File
# Begin Source File

SOURCE=.\res\InquirePhotoNum.ico
# End Source File
# Begin Source File

SOURCE=.\res\Layer.ico
# End Source File
# Begin Source File

SOURCE=.\res\LedOff.ico
# End Source File
# Begin Source File

SOURCE=.\res\LedOn.ico
# End Source File
# Begin Source File

SOURCE=.\res\LedWarn.ico
# End Source File
# Begin Source File

SOURCE=.\res\PromptWayLine.ico
# End Source File
# Begin Source File

SOURCE=.\res\Rect.ico
# End Source File
# Begin Source File

SOURCE=.\res\RunWay.ico
# End Source File
# Begin Source File

SOURCE=.\res\SetUp.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ShowUAVWayPoint.ico
# End Source File
# Begin Source File

SOURCE=.\res\SignLine.ico
# End Source File
# Begin Source File

SOURCE=.\res\SignPoint.ico
# End Source File
# Begin Source File

SOURCE=.\res\SignPoly.ico
# End Source File
# Begin Source File

SOURCE=.\res\SignPolyLine.ico
# End Source File
# Begin Source File

SOURCE=.\res\StartContinuePhoto.ico
# End Source File
# Begin Source File

SOURCE=.\res\StopContinuePhoto.ico
# End Source File
# Begin Source File

SOURCE=.\res\temp.ico
# End Source File
# Begin Source File

SOURCE=.\res\toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\UpWayLine.ico
# End Source File
# Begin Source File

SOURCE=.\res\WayLine.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section GStation : {3B2B9819-FBBF-11D4-93CA-006008A7EED4}
# 	2:5:Class:CTeeFont
# 	2:10:HeaderFile:teefont.h
# 	2:8:ImplFile:teefont.cpp
# End Section
# Section GStation : {B6C1048F-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CCanvas
# 	2:10:HeaderFile:canvas.h
# 	2:8:ImplFile:canvas.cpp
# End Section
# Section GStation : {B6C104EB-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CChartFont
# 	2:10:HeaderFile:chartfont.h
# 	2:8:ImplFile:chartfont.cpp
# End Section
# Section GStation : {2E375632-A81D-400A-9369-F609B6B914AC}
# 	2:5:Class:CBoxPlotSeries
# 	2:10:HeaderFile:boxplotseries.h
# 	2:8:ImplFile:boxplotseries.cpp
# End Section
# Section GStation : {B6C104CB-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CBarSeries
# 	2:10:HeaderFile:barseries.h
# 	2:8:ImplFile:barseries.cpp
# End Section
# Section GStation : {B6C104DB-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CHorizBarSeries
# 	2:10:HeaderFile:horizbarseries.h
# 	2:8:ImplFile:horizbarseries.cpp
# End Section
# Section GStation : {B6C10510-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CRSIFunction
# 	2:10:HeaderFile:rsifunction.h
# 	2:8:ImplFile:rsifunction.cpp
# End Section
# Section GStation : {B6C1053C-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CBar3DSeries
# 	2:10:HeaderFile:bar3dseries.h
# 	2:8:ImplFile:bar3dseries.cpp
# End Section
# Section GStation : {B4B8B973-32BF-40A8-8E07-EFBA557E13F8}
# 	2:5:Class:CHighLowSeries
# 	2:10:HeaderFile:highlowseries.h
# 	2:8:ImplFile:highlowseries.cpp
# End Section
# Section GStation : {69A3C18D-728E-47B5-9144-7C58B59AA42D}
# 	2:5:Class:CSmithSeries
# 	2:10:HeaderFile:smithseries.h
# 	2:8:ImplFile:smithseries.cpp
# End Section
# Section GStation : {C746269F-0A39-4EC5-B52F-7E489835035B}
# 	2:5:Class:CAxisArrowTool
# 	2:10:HeaderFile:axisarrowtool.h
# 	2:8:ImplFile:axisarrowtool.cpp
# End Section
# Section GStation : {235FB755-F8ED-11D4-93C8-006008A7EED4}
# 	2:5:Class:CChartImageTool
# 	2:10:HeaderFile:chartimagetool.h
# 	2:8:ImplFile:chartimagetool.cpp
# End Section
# Section GStation : {2EF654E2-FE50-11D2-98A9-00A0C9742CCA}
# 	2:5:Class:CCMapXRowValue
# 	2:10:HeaderFile:cmapxrowvalue.h
# 	2:8:ImplFile:cmapxrowvalue.cpp
# End Section
# Section GStation : {806FA9D7-C5D9-43E9-B381-69E30C991E84}
# 	2:5:Class:CCMapXAllFeaturesConstraint
# 	2:10:HeaderFile:cmapxallfeaturesconstraint.h
# 	2:8:ImplFile:cmapxallfeaturesconstraint.cpp
# End Section
# Section GStation : {CF466D04-7FAB-11D2-8CE0-00207812C7EB}
# 	2:5:Class:CCMapXFindMatch
# 	2:10:HeaderFile:cmapxfindmatch.h
# 	2:8:ImplFile:cmapxfindmatch.cpp
# End Section
# Section GStation : {AC690AD7-0730-11D5-93E3-006008A7EED4}
# 	2:5:Class:CTextExport
# 	2:10:HeaderFile:textexport.h
# 	2:8:ImplFile:textexport.cpp
# End Section
# Section GStation : {B6C104A8-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CLegend
# 	2:10:HeaderFile:legend.h
# 	2:8:ImplFile:legend.cpp
# End Section
# Section GStation : {B6C10493-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CAxisLabels
# 	2:10:HeaderFile:axislabels.h
# 	2:8:ImplFile:axislabels.cpp
# End Section
# Section GStation : {B6C10509-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CSeriesMarksPositions
# 	2:10:HeaderFile:seriesmarkspositions.h
# 	2:8:ImplFile:seriesmarkspositions.cpp
# End Section
# Section GStation : {9CE4E780-4431-4504-948A-797D83C1E310}
# 	2:5:Class:CDragMarksTool
# 	2:10:HeaderFile:dragmarkstool.h
# 	2:8:ImplFile:dragmarkstool.cpp
# End Section
# Section GStation : {46FF43C0-C9ED-11CF-8796-00AA00B7EF73}
# 	2:5:Class:CCMapXSourceRows
# 	2:10:HeaderFile:cmapxsourcerows.h
# 	2:8:ImplFile:cmapxsourcerows.cpp
# End Section
# Section GStation : {985148C3-C84B-11CF-9BEE-00AA00A478CB}
# 	2:5:Class:CCMapXIValueCategory
# 	2:10:HeaderFile:cmapxivaluecategory.h
# 	2:8:ImplFile:cmapxivaluecategory.cpp
# End Section
# Section GStation : {B6C104A3-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CScroll
# 	2:10:HeaderFile:scroll.h
# 	2:8:ImplFile:scroll.cpp
# End Section
# Section GStation : {B6C104BF-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CAreaSeries
# 	2:10:HeaderFile:areaseries.h
# 	2:8:ImplFile:areaseries.cpp
# End Section
# Section GStation : {B6C104E8-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CCurveFittingFunction
# 	2:10:HeaderFile:curvefittingfunction.h
# 	2:8:ImplFile:curvefittingfunction.cpp
# End Section
# Section GStation : {B86AE373-50DC-4AE9-8872-8E3F9FC21A4E}
# 	2:5:Class:CMACDFunction
# 	2:10:HeaderFile:macdfunction.h
# 	2:8:ImplFile:macdfunction.cpp
# End Section
# Section GStation : {70C80BD0-D36A-46C9-A9D6-AE8687CA0EA5}
# 	2:5:Class:CHistogramSeries
# 	2:10:HeaderFile:histogramseries.h
# 	2:8:ImplFile:histogramseries.cpp
# End Section
# Section GStation : {449C6526-C2F8-47EE-8386-32D20B488B8B}
# 	2:5:Class:CCursorTool
# 	2:10:HeaderFile:cursortool.h
# 	2:8:ImplFile:cursortool.cpp
# End Section
# Section GStation : {B6C104AF-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CValueList
# 	2:10:HeaderFile:valuelist.h
# 	2:8:ImplFile:valuelist.cpp
# End Section
# Section GStation : {B6C104C8-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CShapeSeries
# 	2:10:HeaderFile:shapeseries.h
# 	2:8:ImplFile:shapeseries.cpp
# End Section
# Section GStation : {B6C10504-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CBezierSeries
# 	2:10:HeaderFile:bezierseries.h
# 	2:8:ImplFile:bezierseries.cpp
# End Section
# Section GStation : {B6C10539-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CClockSeries
# 	2:10:HeaderFile:clockseries.h
# 	2:8:ImplFile:clockseries.cpp
# End Section
# Section GStation : {750EB847-B333-4A73-8AEE-9087F8B98D1E}
# 	2:5:Class:CToolList
# 	2:10:HeaderFile:toollist.h
# 	2:8:ImplFile:toollist.cpp
# End Section
# Section GStation : {62DD8659-F041-11D4-93B1-006008A7EED4}
# 	2:5:Class:CDrawLine
# 	2:10:HeaderFile:drawline.h
# 	2:8:ImplFile:drawline.cpp
# End Section
# Section GStation : {CDE865C4-6B25-4604-8813-F0A65E51F1C8}
# 	2:5:Class:CColorLineTool
# 	2:10:HeaderFile:colorlinetool.h
# 	2:8:ImplFile:colorlinetool.cpp
# End Section
# Section GStation : {4EC9B528-DFCF-11CF-9BEE-00AA00A478CB}
# 	2:5:Class:CCMapXLegendTexts
# 	2:10:HeaderFile:cmapxlegendtexts.h
# 	2:8:ImplFile:cmapxlegendtexts.cpp
# End Section
# Section GStation : {77306D54-5C82-11CF-8795-00AA00B7EF73}
# 	2:5:Class:CCMapXThemes
# 	2:10:HeaderFile:cmapxthemes.h
# 	2:8:ImplFile:cmapxthemes.cpp
# End Section
# Section GStation : {4C952040-3331-11D0-8796-00AA00B7EF73}
# 	2:5:Class:CCMapXRectangle
# 	2:10:HeaderFile:cmapxrectangle.h
# 	2:8:ImplFile:cmapxrectangle.cpp
# End Section
# Section GStation : {968303A2-8F18-11D0-8796-00AA00B7EF73}
# 	2:5:Class:CCMapXPoints
# 	2:10:HeaderFile:cmapxpoints.h
# 	2:8:ImplFile:cmapxpoints.cpp
# End Section
# Section GStation : {083039C2-13F4-11D1-8B7E-0000F8754DA1}
# 	2:5:Class:CCommonDialog1
# 	2:10:HeaderFile:commondialog.h
# 	2:8:ImplFile:commondialog.cpp
# End Section
# Section GStation : {235FB744-F8ED-11D4-93C8-006008A7EED4}
# 	2:5:Class:CPNGExport
# 	2:10:HeaderFile:pngexport.h
# 	2:8:ImplFile:pngexport.cpp
# End Section
# Section GStation : {B6C10497-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CImport
# 	2:10:HeaderFile:import.h
# 	2:8:ImplFile:import.cpp
# End Section
# Section GStation : {B6C1053B-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CImageBarSeries
# 	2:10:HeaderFile:imagebarseries.h
# 	2:8:ImplFile:imagebarseries.cpp
# End Section
# Section GStation : {FDB6AE9B-AE83-4CC3-AC6D-03CF0E133867}
# 	2:5:Class:CPyramidSeries
# 	2:10:HeaderFile:pyramidseries.h
# 	2:8:ImplFile:pyramidseries.cpp
# End Section
# Section GStation : {B6C10534-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CTeePoint3D
# 	2:10:HeaderFile:teepoint3d.h
# 	2:8:ImplFile:teepoint3d.cpp
# End Section
# Section GStation : {B6C104AA-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CPage
# 	2:10:HeaderFile:page.h
# 	2:8:ImplFile:page.cpp
# End Section
# Section GStation : {B6C104DF-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CErrorBarSeries
# 	2:10:HeaderFile:errorbarseries.h
# 	2:8:ImplFile:errorbarseries.cpp
# End Section
# Section GStation : {B6C1050B-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CPolarSeries
# 	2:10:HeaderFile:polarseries.h
# 	2:8:ImplFile:polarseries.cpp
# End Section
# Section GStation : {3752717C-15C0-4C15-9532-C9C371388028}
# 	2:5:Class:CADXFunction
# 	2:10:HeaderFile:adxfunction.h
# 	2:8:ImplFile:adxfunction.cpp
# End Section
# Section GStation : {1C66DB81-D40D-11CF-9BEE-00AA00A478CB}
# 	2:5:Class:CCMapXAnnotation
# 	2:10:HeaderFile:cmapxannotation.h
# 	2:8:ImplFile:cmapxannotation.cpp
# End Section
# Section GStation : {A77491E3-F825-11D4-93C7-006008A7EED4}
# 	2:5:Class:CJPEGExport
# 	2:10:HeaderFile:jpegexport.h
# 	2:8:ImplFile:jpegexport.cpp
# End Section
# Section GStation : {662C9054-0898-4F09-881E-5ABB47978FB6}
# 	2:5:Class:CRMSFunction
# 	2:10:HeaderFile:rmsfunction.h
# 	2:8:ImplFile:rmsfunction.cpp
# End Section
# Section GStation : {4CC67466-2A11-45C6-924E-15E8B9F6B780}
# 	2:5:Class:CWaterfallSeries
# 	2:10:HeaderFile:waterfallseries.h
# 	2:8:ImplFile:waterfallseries.cpp
# End Section
# Section GStation : {C9F8E464-0B4B-4427-8678-363CF8E1955D}
# 	2:5:Class:CColorBandTool
# 	2:10:HeaderFile:colorbandtool.h
# 	2:8:ImplFile:colorbandtool.cpp
# End Section
# Section GStation : {235FB74B-F8ED-11D4-93C8-006008A7EED4}
# 	2:5:Class:CPCXExport
# 	2:10:HeaderFile:pcxexport.h
# 	2:8:ImplFile:pcxexport.cpp
# End Section
# Section GStation : {B6C1048E-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CStrings
# 	2:10:HeaderFile:strings.h
# 	2:8:ImplFile:strings.cpp
# End Section
# Section GStation : {B6C104EA-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CMovingAvgFunction
# 	2:10:HeaderFile:movingavgfunction.h
# 	2:8:ImplFile:movingavgfunction.cpp
# End Section
# Section GStation : {968303A6-8F18-11D0-8796-00AA00B7EF73}
# 	2:5:Class:CCMapXPoint
# 	2:10:HeaderFile:cmapxpoint.h
# 	2:8:ImplFile:cmapxpoint.cpp
# End Section
# Section GStation : {B0929662-BA3A-11CF-9019-00AA00A53B3C}
# 	2:5:Class:CCMapXFeature
# 	2:10:HeaderFile:cmapxfeature.h
# 	2:8:ImplFile:cmapxfeature.cpp
# End Section
# Section GStation : {DC09D461-9575-11D0-83F7-00AA00BD34FC}
# 	2:5:Class:CCMapXGeoset
# 	2:10:HeaderFile:cmapxgeoset.h
# 	2:8:ImplFile:cmapxgeoset.cpp
# End Section
# Section GStation : {B6C10538-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CTeeOpenGL
# 	2:10:HeaderFile:teeopengl.h
# 	2:8:ImplFile:teeopengl.cpp
# End Section
# Section GStation : {AC690ACD-0730-11D5-93E3-006008A7EED4}
# 	2:5:Class:CNativeExport
# 	2:10:HeaderFile:nativeexport.h
# 	2:8:ImplFile:nativeexport.cpp
# End Section
# Section GStation : {B6C104C7-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CGanttSeries
# 	2:10:HeaderFile:ganttseries.h
# 	2:8:ImplFile:ganttseries.cpp
# End Section
# Section GStation : {E517CB27-1C48-11D5-9400-006008A7EED4}
# 	2:5:Class:CCalendarCellUpper
# 	2:10:HeaderFile:calendarcellupper.h
# 	2:8:ImplFile:calendarcellupper.cpp
# End Section
# Section GStation : {A841A3E5-3ED7-11D5-943D-006008A7EED4}
# 	2:5:Class:CValueLists
# 	2:10:HeaderFile:valuelists.h
# 	2:8:ImplFile:valuelists.cpp
# End Section
# Section GStation : {B6C10508-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CSurfaceSeries
# 	2:10:HeaderFile:surfaceseries.h
# 	2:8:ImplFile:surfaceseries.cpp
# End Section
# Section GStation : {B6C104A7-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CWalls
# 	2:10:HeaderFile:walls.h
# 	2:8:ImplFile:walls.cpp
# End Section
# Section GStation : {5970102E-E487-4B12-88A8-A7930EF23E5D}
# 	2:5:Class:CDrawLineTool
# 	2:10:HeaderFile:drawlinetool.h
# 	2:8:ImplFile:drawlinetool.cpp
# End Section
# Section GStation : {77306D48-5C82-11CF-8795-00AA00B7EF73}
# 	2:5:Class:CCMapXLayer
# 	2:10:HeaderFile:cmapxlayer.h
# 	2:8:ImplFile:cmapxlayer.cpp
# End Section
# Section GStation : {58A009FA-D7D0-4AD9-A593-69ADC20A6A21}
# 	2:5:Class:CCMapXLabel
# 	2:10:HeaderFile:cmapxlabel.h
# 	2:8:ImplFile:cmapxlabel.cpp
# End Section
# Section GStation : {61E82A60-FB59-11CF-9019-00AA00A53B3C}
# 	2:5:Class:CCMapXLabelProperties
# 	2:10:HeaderFile:cmapxlabelproperties.h
# 	2:8:ImplFile:cmapxlabelproperties.cpp
# End Section
# Section GStation : {A4274C81-7E2E-11D2-8CE0-00207812C7EB}
# 	2:5:Class:CCMapXFindResult
# 	2:10:HeaderFile:cmapxfindresult.h
# 	2:8:ImplFile:cmapxfindresult.cpp
# End Section
# Section GStation : {436052C0-43E3-11D0-83EB-00AA00BD34FC}
# 	2:5:Class:CCMapXLayerFind
# 	2:10:HeaderFile:cmapxlayerfind.h
# 	2:8:ImplFile:cmapxlayerfind.cpp
# End Section
# Section GStation : {DE279C62-DCDF-11D0-934C-00AA004603B3}
# 	2:5:Class:CCMapXAffineTransform
# 	2:10:HeaderFile:cmapxaffinetransform.h
# 	2:8:ImplFile:cmapxaffinetransform.cpp
# End Section
# Section GStation : {235FB74F-F8ED-11D4-93C8-006008A7EED4}
# 	2:5:Class:CBMPExport
# 	2:10:HeaderFile:bmpexport.h
# 	2:8:ImplFile:bmpexport.cpp
# End Section
# Section GStation : {B6C104C2-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CFastLineSeries
# 	2:10:HeaderFile:fastlineseries.h
# 	2:8:ImplFile:fastlineseries.cpp
# End Section
# Section GStation : {B6C1050A-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CSeriesMarkPosition
# 	2:10:HeaderFile:seriesmarkposition.h
# 	2:8:ImplFile:seriesmarkposition.cpp
# End Section
# Section GStation : {B6C10533-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CTeePoint2D
# 	2:10:HeaderFile:teepoint2d.h
# 	2:8:ImplFile:teepoint2d.cpp
# End Section
# Section GStation : {BA3A0E2D-CCE7-4CF6-82D2-044B2A64EE59}
# 	2:5:Class:CColorGridSeries
# 	2:10:HeaderFile:colorgridseries.h
# 	2:8:ImplFile:colorgridseries.cpp
# End Section
# Section GStation : {E517CB2E-1C48-11D5-9400-006008A7EED4}
# 	2:5:Class:CPageNumTool
# 	2:10:HeaderFile:pagenumtool.h
# 	2:8:ImplFile:pagenumtool.cpp
# End Section
# Section GStation : {AC690AD1-0730-11D5-93E3-006008A7EED4}
# 	2:5:Class:CXMLExport
# 	2:10:HeaderFile:xmlexport.h
# 	2:8:ImplFile:xmlexport.cpp
# End Section
# Section GStation : {B6C104AE-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CMarks
# 	2:10:HeaderFile:marks.h
# 	2:8:ImplFile:marks.cpp
# End Section
# Section GStation : {CB0CE331-76CB-449C-9BE7-FB69C03C3439}
# 	2:5:Class:CHorizBoxPlotSeries
# 	2:10:HeaderFile:horizboxplotseries.h
# 	2:8:ImplFile:horizboxplotseries.cpp
# End Section
# Section GStation : {ECC81860-038E-11D1-9DC6-00AA00A478CB}
# 	2:5:Class:CCMapXRangeCategoriesCollection
# 	2:10:HeaderFile:cmapxrangecategoriescollection.h
# 	2:8:ImplFile:cmapxrangecategoriescollection.cpp
# End Section
# Section GStation : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section
# Section GStation : {9D6ED197-5910-11D2-98A6-00A0C9742CCA}
# 	2:5:Class:CCMapX
# 	2:10:HeaderFile:cmapx.h
# 	2:8:ImplFile:cmapx.cpp
# End Section
# Section GStation : {7A5FFDC2-FE6C-11D2-98A9-00A0C9742CCA}
# 	2:5:Class:CCMapXRowValues
# 	2:10:HeaderFile:cmapxrowvalues.h
# 	2:8:ImplFile:cmapxrowvalues.cpp
# End Section
# Section GStation : {97F45D06-BF8A-11CF-9BEE-00AA00A478CB}
# 	2:5:Class:CCMapXRangeCategory
# 	2:10:HeaderFile:cmapxrangecategory.h
# 	2:8:ImplFile:cmapxrangecategory.cpp
# End Section
# Section GStation : {B6C1048D-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CBrush1
# 	2:10:HeaderFile:brush.h
# 	2:8:ImplFile:brush.cpp
# End Section
# Section GStation : {3B2B9817-FBBF-11D4-93CA-006008A7EED4}
# 	2:5:Class:CTitles
# 	2:10:HeaderFile:titles.h
# 	2:8:ImplFile:titles.cpp
# End Section
# Section GStation : {B6C10496-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CExport
# 	2:10:HeaderFile:export.h
# 	2:8:ImplFile:export.cpp
# End Section
# Section GStation : {B6C1053A-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CWindRoseSeries
# 	2:10:HeaderFile:windroseseries.h
# 	2:8:ImplFile:windroseseries.cpp
# End Section
# Section GStation : {235FB753-F8ED-11D4-93C8-006008A7EED4}
# 	2:5:Class:CMarksTipTool
# 	2:10:HeaderFile:markstiptool.h
# 	2:8:ImplFile:markstiptool.cpp
# End Section
# Section GStation : {49EB5384-BFFB-11D0-934C-00AA004603B3}
# 	2:5:Class:CCMapXDatum
# 	2:10:HeaderFile:cmapxdatum.h
# 	2:8:ImplFile:cmapxdatum.cpp
# End Section
# Section GStation : {F9043C85-F6F2-101A-A3C9-08002B2F49FB}
# 	2:21:DefaultSinkHeaderFile:commondialog.h
# 	2:16:DefaultSinkClass:CCommonDialog1
# End Section
# Section GStation : {AC690AD5-0730-11D5-93E3-006008A7EED4}
# 	2:5:Class:CHTMLExport
# 	2:10:HeaderFile:htmlexport.h
# 	2:8:ImplFile:htmlexport.cpp
# End Section
# Section GStation : {2DCBF4FF-BEDF-4140-B726-70996BB2B6E6}
# 	2:5:Class:CBollingerFunction
# 	2:10:HeaderFile:bollingerfunction.h
# 	2:8:ImplFile:bollingerfunction.cpp
# End Section
# Section GStation : {B6C10507-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CPoint3DSeries
# 	2:10:HeaderFile:point3dseries.h
# 	2:8:ImplFile:point3dseries.cpp
# End Section
# Section GStation : {B6C10491-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CAxes
# 	2:10:HeaderFile:axes.h
# 	2:8:ImplFile:axes.cpp
# End Section
# Section GStation : {ECC81864-038E-11D1-9DC6-00AA00A478CB}
# 	2:5:Class:CCMapXMultivarCategoriesCollection
# 	2:10:HeaderFile:cmapxmultivarcategoriescollection.h
# 	2:8:ImplFile:cmapxmultivarcategoriescollection.cpp
# End Section
# Section GStation : {090703E0-9563-11D0-8796-00AA00B7EF73}
# 	2:5:Class:CCMapXFeatures
# 	2:10:HeaderFile:cmapxfeatures.h
# 	2:8:ImplFile:cmapxfeatures.cpp
# End Section
# Section GStation : {B6C104BD-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CPointer
# 	2:10:HeaderFile:pointer.h
# 	2:8:ImplFile:pointer.cpp
# End Section
# Section GStation : {B6C104AD-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CTeeFunction
# 	2:10:HeaderFile:teefunction.h
# 	2:8:ImplFile:teefunction.cpp
# End Section
# Section GStation : {B6C10512-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CEnvironment
# 	2:10:HeaderFile:environment.h
# 	2:8:ImplFile:environment.cpp
# End Section
# Section GStation : {B6C104C6-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CAxis
# 	2:10:HeaderFile:axis.h
# 	2:8:ImplFile:axis.cpp
# End Section
# Section GStation : {B6C1050E-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CStdDeviationFunction
# 	2:10:HeaderFile:stddeviationfunction.h
# 	2:8:ImplFile:stddeviationfunction.cpp
# End Section
# Section GStation : {01E6D0D8-07EE-11D5-93E4-006008A7EED4}
# 	2:5:Class:CFunnelSeries
# 	2:10:HeaderFile:funnelseries.h
# 	2:8:ImplFile:funnelseries.cpp
# End Section
# Section GStation : {B6C104A6-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CWall
# 	2:10:HeaderFile:wall.h
# 	2:8:ImplFile:wall.cpp
# End Section
# Section GStation : {62DD8657-F041-11D4-93B1-006008A7EED4}
# 	2:5:Class:CDrawLineList
# 	2:10:HeaderFile:drawlinelist.h
# 	2:8:ImplFile:drawlinelist.cpp
# End Section
# Section GStation : {22A5D9BB-B643-11D5-94F8-006008A7EED4}
# 	2:5:Class:CTeeShapePanel
# 	2:10:HeaderFile:teeshapepanel.h
# 	2:8:ImplFile:teeshapepanel.cpp
# End Section
# Section GStation : {984C9420-93BA-11D0-B374-444553540000}
# 	2:5:Class:CCMapXGeosets
# 	2:10:HeaderFile:cmapxgeosets.h
# 	2:8:ImplFile:cmapxgeosets.cpp
# End Section
# Section GStation : {77306D42-5C82-11CF-8795-00AA00B7EF73}
# 	2:5:Class:CCMapXLayers
# 	2:10:HeaderFile:cmapxlayers.h
# 	2:8:ImplFile:cmapxlayers.cpp
# End Section
# Section GStation : {77306D4E-5C82-11CF-8795-00AA00B7EF73}
# 	2:5:Class:CCMapXDatasets
# 	2:10:HeaderFile:cmapxdatasets.h
# 	2:8:ImplFile:cmapxdatasets.cpp
# End Section
# Section GStation : {968303A0-8F18-11D0-8796-00AA00B7EF73}
# 	2:5:Class:CCMapXParts
# 	2:10:HeaderFile:cmapxparts.h
# 	2:8:ImplFile:cmapxparts.cpp
# End Section
# Section GStation : {14E2FEE7-6904-4433-8472-BE07EAF2F7B3}
# 	2:5:Class:CInstrumentCircle
# 	2:10:HeaderFile:instrumentcircle.h
# 	2:8:ImplFile:instrumentcircle.cpp
# End Section
# Section GStation : {74DE98EE-DE61-46C1-AA56-9616C1E49E90}
# 	2:21:DefaultSinkHeaderFile:instrumentcircle.h
# 	2:16:DefaultSinkClass:CInstrumentCircle
# End Section
# Section GStation : {9B91C551-22A6-441D-A68A-A48B5E85B3EA}
# 	2:5:Class:CInstrumentPanel
# 	2:10:HeaderFile:instrumentpanel.h
# 	2:8:ImplFile:instrumentpanel.cpp
# End Section
# Section GStation : {B6C10485-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CTChart
# 	2:10:HeaderFile:tchart.h
# 	2:8:ImplFile:tchart.cpp
# End Section
# Section GStation : {41A5C203-7F36-4E11-840D-D41230760D8E}
# 	2:5:Class:CDonutSeries
# 	2:10:HeaderFile:donutseries.h
# 	2:8:ImplFile:donutseries.cpp
# End Section
# Section GStation : {B6C104C1-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CLineSeries
# 	2:10:HeaderFile:lineseries.h
# 	2:8:ImplFile:lineseries.cpp
# End Section
# Section GStation : {B6C104ED-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CPieOtherSlice
# 	2:10:HeaderFile:pieotherslice.h
# 	2:8:ImplFile:pieotherslice.cpp
# End Section
# Section GStation : {C793DB5D-E235-4248-87AD-E436822E64F2}
# 	2:5:Class:CHorizLineSeries
# 	2:10:HeaderFile:horizlineseries.h
# 	2:8:ImplFile:horizlineseries.cpp
# End Section
# Section GStation : {CF466D01-7FAB-11D2-8CE0-00207812C7EB}
# 	2:5:Class:CCMapXFindMatches
# 	2:10:HeaderFile:cmapxfindmatches.h
# 	2:8:ImplFile:cmapxfindmatches.cpp
# End Section
# Section GStation : {B2504160-E149-11CF-9BEE-00AA00A478CB}
# 	2:5:Class:CCMapXTitle
# 	2:10:HeaderFile:cmapxtitle.h
# 	2:8:ImplFile:cmapxtitle.cpp
# End Section
# Section GStation : {33A0CF4E-AE1F-43DB-A3CF-B7F9905085C8}
# 	2:5:Class:CMapSeries
# 	2:10:HeaderFile:mapseries.h
# 	2:8:ImplFile:mapseries.cpp
# End Section
# Section GStation : {AC690AD9-0730-11D5-93E3-006008A7EED4}
# 	2:5:Class:CMapPolygonList
# 	2:10:HeaderFile:mappolygonlist.h
# 	2:8:ImplFile:mappolygonlist.cpp
# End Section
# Section GStation : {01E6D0DA-07EE-11D5-93E4-006008A7EED4}
# 	2:5:Class:CCalendarSeries
# 	2:10:HeaderFile:calendarseries.h
# 	2:8:ImplFile:calendarseries.cpp
# End Section
# Section GStation : {F66470FB-1309-47FF-A790-26E2E38BEBD0}
# 	2:5:Class:CContourLevels
# 	2:10:HeaderFile:contourlevels.h
# 	2:8:ImplFile:contourlevels.cpp
# End Section
# Section GStation : {DA944291-24C8-4956-BEE4-3129A675A49C}
# 	2:5:Class:CBarJoinSeries
# 	2:10:HeaderFile:barjoinseries.h
# 	2:8:ImplFile:barjoinseries.cpp
# End Section
# Section GStation : {97763CEC-4D57-4612-A799-05C6E19AC789}
# 	2:5:Class:CRotateTool
# 	2:10:HeaderFile:rotatetool.h
# 	2:8:ImplFile:rotatetool.cpp
# End Section
# Section GStation : {46FF43C2-C9ED-11CF-8796-00AA00B7EF73}
# 	2:5:Class:CCMapXSourceRow
# 	2:10:HeaderFile:cmapxsourcerow.h
# 	2:8:ImplFile:cmapxsourcerow.cpp
# End Section
# Section GStation : {B0929660-BA3A-11CF-9019-00AA00A53B3C}
# 	2:5:Class:CCMapXSelection
# 	2:10:HeaderFile:cmapxselection.h
# 	2:8:ImplFile:cmapxselection.cpp
# End Section
# Section GStation : {44DB7B47-B2F5-11CF-9BEE-00AA00A478CB}
# 	2:5:Class:CCMapXThemeProperties
# 	2:10:HeaderFile:cmapxthemeproperties.h
# 	2:8:ImplFile:cmapxthemeproperties.cpp
# End Section
# Section GStation : {BBE482A1-037F-11D1-8796-00AA00B7EF73}
# 	2:5:Class:CCMapXFeatureFactory
# 	2:10:HeaderFile:cmapxfeaturefactory.h
# 	2:8:ImplFile:cmapxfeaturefactory.cpp
# End Section
# Section GStation : {7A35D061-6AAC-11CF-96AE-00AA00A4760F}
# 	2:5:Class:CCMapXAnnotations
# 	2:10:HeaderFile:cmapxannotations.h
# 	2:8:ImplFile:cmapxannotations.cpp
# End Section
# Section GStation : {B6C104A5-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CPrinter
# 	2:10:HeaderFile:printer.h
# 	2:8:ImplFile:printer.cpp
# End Section
# Section GStation : {B6C10490-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CAspect
# 	2:10:HeaderFile:aspect.h
# 	2:8:ImplFile:aspect.cpp
# End Section
# Section GStation : {CC476B13-71AC-463F-85E4-0AA8DD8B8BDE}
# 	2:5:Class:CLegendSymbol
# 	2:10:HeaderFile:legendsymbol.h
# 	2:8:ImplFile:legendsymbol.cpp
# End Section
# Section GStation : {0B304B42-253F-4221-8C87-8AD1FCA76C94}
# 	2:5:Class:CContourLevel
# 	2:10:HeaderFile:contourlevel.h
# 	2:8:ImplFile:contourlevel.cpp
# End Section
# Section GStation : {B6C10506-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CErrorSeries
# 	2:10:HeaderFile:errorseries.h
# 	2:8:ImplFile:errorseries.cpp
# End Section
# Section GStation : {4B6690A0-D4D1-11CF-9BEE-00AA00A478CB}
# 	2:5:Class:CCMapXText
# 	2:10:HeaderFile:cmapxtext.h
# 	2:8:ImplFile:cmapxtext.cpp
# End Section
# Section GStation : {77306D56-5C82-11CF-8795-00AA00B7EF73}
# 	2:5:Class:CCMapXTheme
# 	2:10:HeaderFile:cmapxtheme.h
# 	2:8:ImplFile:cmapxtheme.cpp
# End Section
# Section GStation : {B6C10489-FB89-11D4-93C9-006008A7EED4}
# 	2:21:DefaultSinkHeaderFile:tchart.h
# 	2:16:DefaultSinkClass:CTChart
# End Section
# Section GStation : {B6C104DC-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CCandleSeries
# 	2:10:HeaderFile:candleseries.h
# 	2:8:ImplFile:candleseries.cpp
# End Section
# Section GStation : {2EB35E28-80CF-4F35-9B6B-427E2AC1BFA6}
# 	2:5:Class:CNearestTool
# 	2:10:HeaderFile:nearesttool.h
# 	2:8:ImplFile:nearesttool.cpp
# End Section
# Section GStation : {235FB746-F8ED-11D4-93C8-006008A7EED4}
# 	2:5:Class:CGIFExport
# 	2:10:HeaderFile:gifexport.h
# 	2:8:ImplFile:gifexport.cpp
# End Section
# Section GStation : {B6C104AC-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CSeries
# 	2:10:HeaderFile:series.h
# 	2:8:ImplFile:series.cpp
# End Section
# Section GStation : {B6C104C5-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CBubbleSeries
# 	2:10:HeaderFile:bubbleseries.h
# 	2:8:ImplFile:bubbleseries.cpp
# End Section
# Section GStation : {B6C10501-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CExplodedSlices
# 	2:10:HeaderFile:explodedslices.h
# 	2:8:ImplFile:explodedslices.cpp
# End Section
# Section GStation : {B6C104E5-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CAverageFunction
# 	2:10:HeaderFile:averagefunction.h
# 	2:8:ImplFile:averagefunction.cpp
# End Section
# Section GStation : {AC690ADB-0730-11D5-93E3-006008A7EED4}
# 	2:5:Class:CMapPolygon
# 	2:10:HeaderFile:mappolygon.h
# 	2:8:ImplFile:mappolygon.cpp
# End Section
# Section GStation : {E517CB25-1C48-11D5-9400-006008A7EED4}
# 	2:5:Class:CCalendarCell
# 	2:10:HeaderFile:calendarcell.h
# 	2:8:ImplFile:calendarcell.cpp
# End Section
# Section GStation : {4ABEC4CB-DFD0-444F-9472-B5192D6F4526}
# 	2:5:Class:CCMapXBoundsConstraint
# 	2:10:HeaderFile:cmapxboundsconstraint.h
# 	2:8:ImplFile:cmapxboundsconstraint.cpp
# End Section
# Section GStation : {77306D51-5C82-11CF-8795-00AA00B7EF73}
# 	2:5:Class:CCMapXDataset
# 	2:10:HeaderFile:cmapxdataset.h
# 	2:8:ImplFile:cmapxdataset.cpp
# End Section
# Section GStation : {9542050C-6B62-4250-865F-46579FA576B8}
# 	2:21:DefaultSinkHeaderFile:instrumentpanel.h
# 	2:16:DefaultSinkClass:CInstrumentPanel
# End Section
# Section GStation : {B6C10494-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CAxisTitle
# 	2:10:HeaderFile:axistitle.h
# 	2:8:ImplFile:axistitle.cpp
# End Section
# Section GStation : {5101D067-AD02-426B-832E-A898AF6E4F5E}
# 	2:5:Class:CTeeShadow
# 	2:10:HeaderFile:teeshadow.h
# 	2:8:ImplFile:teeshadow.cpp
# End Section
# Section GStation : {235FB74D-F8ED-11D4-93C8-006008A7EED4}
# 	2:5:Class:CMetafileExport
# 	2:10:HeaderFile:metafileexport.h
# 	2:8:ImplFile:metafileexport.cpp
# End Section
# Section GStation : {B6C104C0-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CPointSeries
# 	2:10:HeaderFile:pointseries.h
# 	2:8:ImplFile:pointseries.cpp
# End Section
# Section GStation : {B6C104E0-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CVolumeSeries
# 	2:10:HeaderFile:volumeseries.h
# 	2:8:ImplFile:volumeseries.cpp
# End Section
# Section GStation : {DFBF9393-46FD-11D2-AEC3-00400141862D}
# 	2:5:Class:CContourSeries
# 	2:10:HeaderFile:contourseries.h
# 	2:8:ImplFile:contourseries.cpp
# End Section
# Section GStation : {5B9827E5-3BE4-4DA3-9A6F-611BF900E4E1}
# 	2:5:Class:CTriSurfaceSeries
# 	2:10:HeaderFile:trisurfaceseries.h
# 	2:8:ImplFile:trisurfaceseries.cpp
# End Section
# Section GStation : {49EB5382-BFFB-11D0-934C-00AA004603B3}
# 	2:5:Class:CCMapXCoordSys
# 	2:10:HeaderFile:cmapxcoordsys.h
# 	2:8:ImplFile:cmapxcoordsys.cpp
# End Section
# Section GStation : {3DBD18C2-C2AC-11CF-8796-00AA00B7EF73}
# 	2:5:Class:CCMapXFields
# 	2:10:HeaderFile:cmapxfields.h
# 	2:8:ImplFile:cmapxfields.cpp
# End Section
# Section GStation : {4EC9B520-DFCF-11CF-9BEE-00AA00A478CB}
# 	2:5:Class:CCMapXLegendText
# 	2:10:HeaderFile:cmapxlegendtext.h
# 	2:8:ImplFile:cmapxlegendtext.cpp
# End Section
# Section GStation : {B06B11B1-EBEC-4972-B786-369EB41C18B2}
# 	2:21:DefaultSinkHeaderFile:cmapx.h
# 	2:16:DefaultSinkClass:CMapX
# End Section
# Section GStation : {B6C104C9-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CArrowSeries
# 	2:10:HeaderFile:arrowseries.h
# 	2:8:ImplFile:arrowseries.cpp
# End Section
# Section GStation : {B6C10505-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CRadarSeries
# 	2:10:HeaderFile:radarseries.h
# 	2:8:ImplFile:radarseries.cpp
# End Section
# Section GStation : {E517CB29-1C48-11D5-9400-006008A7EED4}
# 	2:5:Class:CAnnotationTool
# 	2:10:HeaderFile:annotationtool.h
# 	2:8:ImplFile:annotationtool.cpp
# End Section
# Section GStation : {B6C1048B-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CPen1
# 	2:10:HeaderFile:pen.h
# 	2:8:ImplFile:pen.cpp
# End Section
# Section GStation : {B6C104A9-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CGradient
# 	2:10:HeaderFile:gradient.h
# 	2:8:ImplFile:gradient.cpp
# End Section
# Section GStation : {ECC81862-038E-11D1-9DC6-00AA00A478CB}
# 	2:5:Class:CCMapXIndividualValueCategoriesCollection
# 	2:10:HeaderFile:cmapxindividualvaluecategoriescollection.h
# 	2:8:ImplFile:cmapxindividualvaluecategoriescollection.cpp
# End Section
# Section GStation : {E6E17E90-DF38-11CF-8E74-00A0C90F26F8}
# 	2:5:Class:CMSComm
# 	2:10:HeaderFile:mscomm.h
# 	2:8:ImplFile:mscomm.cpp
# End Section
# Section GStation : {C6AAE3F1-88D9-45FB-B816-7D635B3F259B}
# 	2:5:Class:CCMapXLabels
# 	2:10:HeaderFile:cmapxlabels.h
# 	2:8:ImplFile:cmapxlabels.cpp
# End Section
# Section GStation : {648A5600-2C6E-101B-82B6-000000000014}
# 	2:21:DefaultSinkHeaderFile:mscomm.h
# 	2:16:DefaultSinkClass:CMSComm
# End Section
# Section GStation : {436052C2-43E3-11D0-83EB-00AA00BD34FC}
# 	2:5:Class:CCMapXFindFeature
# 	2:10:HeaderFile:cmapxfindfeature.h
# 	2:8:ImplFile:cmapxfindfeature.cpp
# End Section
# Section GStation : {B6C104AB-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CPanel
# 	2:10:HeaderFile:panel.h
# 	2:8:ImplFile:panel.cpp
# End Section
# Section GStation : {B6C104C4-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CPieSeries
# 	2:10:HeaderFile:pieseries.h
# 	2:8:ImplFile:pieseries.cpp
# End Section
# Section GStation : {AC690AD3-0730-11D5-93E3-006008A7EED4}
# 	2:5:Class:CXLSExport
# 	2:10:HeaderFile:xlsexport.h
# 	2:8:ImplFile:xlsexport.cpp
# End Section
# Section GStation : {B6C1050C-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CCircleLabels
# 	2:10:HeaderFile:circlelabels.h
# 	2:8:ImplFile:circlelabels.cpp
# End Section
# Section GStation : {B6C104E9-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CExpAvgFunction
# 	2:10:HeaderFile:expavgfunction.h
# 	2:8:ImplFile:expavgfunction.cpp
# End Section
# Section GStation : {B6C104A4-FB89-11D4-93C9-006008A7EED4}
# 	2:5:Class:CZoom
# 	2:10:HeaderFile:zoom.h
# 	2:8:ImplFile:zoom.cpp
# End Section
# Section GStation : {67D7AA1C-12FA-4F34-8EB2-B3E8646E0E5F}
# 	2:5:Class:CTools
# 	2:10:HeaderFile:tools.h
# 	2:8:ImplFile:tools.cpp
# End Section
# Section GStation : {1C1EE340-C439-11CF-9BEE-00AA00A478CB}
# 	2:5:Class:CCMapXStyle
# 	2:10:HeaderFile:cmapxstyle.h
# 	2:8:ImplFile:cmapxstyle.cpp
# End Section
# Section GStation : {77306D5C-5C82-11CF-8795-00AA00B7EF73}
# 	2:5:Class:CCMapXLegend
# 	2:10:HeaderFile:cmapxlegend.h
# 	2:8:ImplFile:cmapxlegend.cpp
# End Section
# Section GStation : {064F4C93-D40A-4FE4-9FC0-4A6C4A6EAA8D}
# 	2:5:Class:CCMapXFeaturesConstraint
# 	2:10:HeaderFile:cmapxfeaturesconstraint.h
# 	2:8:ImplFile:cmapxfeaturesconstraint.cpp
# End Section
# Section GStation : {6DDA5660-C853-11CF-9BEE-00AA00A478CB}
# 	2:5:Class:CCMapXMultiVarCategory
# 	2:10:HeaderFile:cmapxmultivarcategory.h
# 	2:8:ImplFile:cmapxmultivarcategory.cpp
# End Section
# Section GStation : {77306D4C-5C82-11CF-8795-00AA00B7EF73}
# 	2:5:Class:CCMapXField
# 	2:10:HeaderFile:cmapxfield.h
# 	2:8:ImplFile:cmapxfield.cpp
# End Section
