#pragma once


// CPropPage1 dialog

class CPropPage1 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CPropPage1)

public:
	CPropPage1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPropPage1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
