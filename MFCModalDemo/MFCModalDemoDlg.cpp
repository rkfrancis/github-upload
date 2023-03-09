
// MFCModalDemoDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCModalDemo.h"
#include "MFCModalDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCModalDemoDlg dialog



CMFCModalDemoDlg::CMFCModalDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCMODALDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(/* IDR_MAINFRAME */ IDR_MYICON);
}

void CMFCModalDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCModalDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_NEW32771, &CMFCModalDemoDlg::OnFileNew)
END_MESSAGE_MAP()


// CMFCModalDemoDlg message handlers

BOOL CMFCModalDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	if (!m_wndToolBar.Create(this)
		|| !m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
		//if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD |
		// WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS |
		// CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		// !m_wndToolBar.LoatToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to Create Dialog Toolbar\n");
		EndDialog(IDCANCEL);
	}
	butD = TRUE;
	CRect rcClientOld; // Old Client Rect
	CRect rcClientNew; // New Client Rect with Toolbar Added

	// Retrieve the Old Client WindowSize
	// Called to reposition and resize control bars in the client area of a window
	// The reposQuery FLAG does not really draw the Toolbar. It only does the calculations.
	// And puts the new ClientRect values in rcClientNew so we can do the rest of the Math.

	GetClientRect(rcClientOld);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0, reposQuery, rcClientNew);
	// All of the Child Windows (Controls) now need to be moved so the Toolbar does not cover them up.
	// Offset to move all child controls after adding Toolbar
	CPoint ptOffset(rcClientNew.left - rcClientOld.left, rcClientNew.top - rcClientOld.top);

	CRect rcChild;
	CWnd *pwndChild = GetWindow(GW_CHILD); //Handle to the Dialog Controls

	while (pwndChild) { // Cycle through all child controls
		pwndChild->GetWindowRect(rcChild); // Get the child control RECT
		ScreenToClient(rcChild);

		// Changes the Child Rect by the values of the calculated offset
		rcChild.OffsetRect(ptOffset);
		pwndChild->MoveWindow(rcChild, FALSE); // Move the Child Control
		pwndChild = pwndChild->GetNextWindow();
	}

	CRect rcWindow;
	// Get the RECT of the Dialog
	GetWindowRect(rcWindow);

	// Increase width to new Client Width
	rcWindow.right += rcClientOld.Width() - rcClientNew.Width();

	// Increase height to new Client Height
	rcWindow.bottom += rcClientOld.Height() - rcClientNew.Height();
	// Redraw Window
	MoveWindow(rcWindow, FALSE);

	// Now we REALLY Redraw the Toolbar
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCModalDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCModalDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCModalDemoDlg::OnFileNew()
{
	// TODO: Add your command handler code here
	MessageBox(L"File > New menu option");
}
