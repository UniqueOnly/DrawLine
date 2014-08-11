; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=InputDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GraphDraw.h"
LastPage=0

ClassCount=6
Class1=CGraphDrawApp
Class2=CGraphDrawDoc
Class3=CGraphDrawView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=InputDialog
Resource3=IDD_DIALOG1

[CLS:CGraphDrawApp]
Type=0
HeaderFile=GraphDraw.h
ImplementationFile=GraphDraw.cpp
Filter=N

[CLS:CGraphDrawDoc]
Type=0
HeaderFile=GraphDrawDoc.h
ImplementationFile=GraphDrawDoc.cpp
Filter=N

[CLS:CGraphDrawView]
Type=0
HeaderFile=GraphDrawView.h
ImplementationFile=GraphDrawView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=GraphDraw.cpp
ImplementationFile=GraphDraw.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_DDALINE
Command17=ID_MIDPOINTLINE
Command18=ID_BRESENHAMLINE
Command19=ID_MIDPOINTCIRCLE
Command20=ID_BRESENHAMCIRCLE
Command21=ID_MIDPOINTELLIPSE
Command22=ID_CLEARCREEN
Command23=ID_APP_ABOUT
CommandCount=23

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=InputDialog
ControlCount=18
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC1,static,1342308352
Control4=IDC_STATIC2,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_EDIT4,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BUTTON1,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT5,edit,1350633600
Control15=IDC_EDIT6,edit,1350633600
Control16=IDC_EDIT7,edit,1350633600
Control17=IDC_DRAWBTN,button,1342242816
Control18=IDC_RESETBTN,button,1342242816

[CLS:InputDialog]
Type=0
HeaderFile=InputDialog.h
ImplementationFile=InputDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

