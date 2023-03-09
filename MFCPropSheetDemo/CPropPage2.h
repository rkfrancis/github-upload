#pragma once


// CPropPage2 dialog

class CPropPage2 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CPropPage2)

public:
	CPropPage2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPropPage2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
