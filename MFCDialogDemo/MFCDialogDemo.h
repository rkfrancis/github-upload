#pragma once

#include "framework.h"
#include "resource.h"

//derive a class from the MFC's CWinApp
class CExample : public CWinApp   //Application Class
{
    BOOL InitInstance();     //InitInstance() must be overidden per the CWinApp documentation
};

class CExampleDlg : public CDialog
{
public:
    enum { IDD = IDD_EXAMPLE_DIALOG };

    CExampleDlg();
    ~CExampleDlg();
};
