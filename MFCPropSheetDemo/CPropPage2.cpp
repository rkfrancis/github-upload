// CPropPage2.cpp : implementation file
//

#include "pch.h"
#include "MFCPropSheetDemo.h"
#include "CPropPage2.h"
#include "afxdialogex.h"


// CPropPage2 dialog

IMPLEMENT_DYNAMIC(CPropPage2, CMFCPropertyPage)

CPropPage2::CPropPage2(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_PROPPAGE_2, pParent)
{

}

CPropPage2::~CPropPage2()
{
}

void CPropPage2::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPropPage2, CMFCPropertyPage)
END_MESSAGE_MAP()


// CPropPage2 message handlers
