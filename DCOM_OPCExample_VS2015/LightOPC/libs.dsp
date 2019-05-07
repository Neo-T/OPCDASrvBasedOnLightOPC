# Microsoft Developer Studio Project File - Name="libs" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Generic Project" 0x010a

CFG=libs - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "libs.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "libs.mak" CFG="libs - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "libs - Win32 Release" (based on "Win32 (x86) Generic Project")
!MESSAGE "libs - Win32 Debug" (based on "Win32 (x86) Generic Project")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
MTL=midl.exe

!IF  "$(CFG)" == "libs - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "."
# PROP Intermediate_Dir "."
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "libs - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "libs___Win32_Debug"
# PROP BASE Intermediate_Dir "libs___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "."
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "libs - Win32 Release"
# Name "libs - Win32 Debug"
# Begin Source File

SOURCE=.\lightopc.lib

!IF  "$(CFG)" == "libs - Win32 Release"

# PROP Ignore_Default_Tool 1
USERDEP__LIGHT="../$(InputName)/$(InputName).def"	
# Begin Custom Build
InputPath=.\lightopc.lib
InputName=lightopc

BuildCmds= \
	lib /MACHINE:i386 /DEF:../$(InputName)/$(InputName).def

"$(InputPath)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputName).exp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "libs - Win32 Debug"

# PROP Ignore_Default_Tool 1
USERDEP__LIGHT="../$(InputName)/$(InputName).def"	
# Begin Custom Build
InputPath=.\lightopc.lib
InputName=lightopc

BuildCmds= \
	lib /MACHINE:i386 /DEF:../$(InputName)/$(InputName).def

"$(InputPath)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputName).exp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\unilog.lib

!IF  "$(CFG)" == "libs - Win32 Release"

# PROP Ignore_Default_Tool 1
USERDEP__UNILO="../$(InputName)/$(InputName).def"	
# Begin Custom Build
InputPath=.\unilog.lib
InputName=unilog

BuildCmds= \
	lib /MACHINE:i386 /DEF:../$(InputName)/$(InputName).def

"$(InputPath)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputName).exp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "libs - Win32 Debug"

# PROP Ignore_Default_Tool 1
USERDEP__UNILO="../$(InputName)/$(InputName).def"	
# Begin Custom Build
InputPath=.\unilog.lib
InputName=unilog

BuildCmds= \
	lib /MACHINE:i386 /DEF:../$(InputName)/$(InputName).def

"$(InputPath)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputName).exp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# End Target
# End Project
