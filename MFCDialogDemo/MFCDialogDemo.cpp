// MFCDialogDemo.cpp : Defines the entry point for the application.
//

#include "MFCDialogDemo.h"

//An APPLICATION needs
//a CLASS           (off CWinApp)
//a FRAME or WINDOW (off CFrameWnd)

CExample theApp;

//To initialize the application, WinMain calls your application object's
//InitApplication and InitInstance member functions. To run the application's
//message loop, WinMain calls the Run member function. On termination, WinMain
//calls the application object's ExitInstance member function.
BOOL CExample::InitInstance() {     //InitInstance() must be overidden per the CWinApp documentation
    CExampleDlg myDlg;
    m_pMainWnd = &myDlg;
    myDlg.DoModal();
    return (TRUE);
}

//*******************************************************************
CExampleDlg::CExampleDlg()
:
    CDialog(CExampleDlg::IDD)
{
}

CExampleDlg::~CExampleDlg()
{
}
