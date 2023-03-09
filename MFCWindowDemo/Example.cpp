#include "framework.h"
//An APPLICATION needs
//a CLASS           (off CWinApp)
//a FRAME or WINDOW (off CFrameWnd)

class CMyFrame : public CFrameWnd {
public:
    CMyFrame() {
//      Create(NULL, _T("MFC Application Tutorial")); //<- this is our Application FRAME/WINDOW!!!!!!
       //NULL is "name of the class" which is correct, and name of the window (shown on the title bar)
//      Create(NULL, _T("MFC Application Tutorial"), WS_VISIBLE | WS_OVERLAPPED);
                                              //WS is Windows Styles
                                              //here we overrode WS_OVERLAPPED_WINDOW default
                                              //which is WS_OVERLAPPED, WS_CAPTION, WS_SYSMENU,
                                              //WS_THICKFRAME, WS_MINIMIZEBOX and WS_MAXIMIZEBOX
                                              //with WS_VISIBLE (initially visible) and WS_OVERLAPPED
                                              //overlapped window with caption and border (WS_BORDER)
        Create(NULL, _T("MFC Application Tutorial"), WS_SYSMENU, CRect(90, 120, 550, 480), NULL);
                                                                              //last NULL is no Parent
    }
};
                   //derive a class from the MFC's CWinApp

                   //To initialize the application, WinMain calls your application object's
                   //InitApplication and InitInstance member functions. To run the application's
                   //message loop, WinMain calls the Run member function. On termination, WinMain
                   //calls the application object's ExitInstance member function.
class CExample : public CWinApp {          //<------------ this is our Application CLASS !!!!!!!!!!!!!
    BOOL InitInstance() {     //InitInstance() must be overidden per the CWinApp documentation
        CMyFrame *frame = new CMyFrame();
        m_pMainWnd = frame;   //Use a pointer to show the class used to create the CFrameWnd.
                              //To use the frame window, assign its pointer to CWinThread::m_pMainWnd
        frame->ShowWindow(SW_NORMAL);
        frame->UpdateWindow();
        return (TRUE);
    }
};

CExample theApp;
