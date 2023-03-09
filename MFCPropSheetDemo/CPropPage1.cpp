// CPropPage1.cpp : implementation file
//

#include "pch.h"
#include "MFCPropSheetDemo.h"
#include "CPropPage1.h"
#include "afxdialogex.h"


// CPropPage1 dialog

IMPLEMENT_DYNAMIC(CPropPage1, CMFCPropertyPage)

CPropPage1::CPropPage1(CWnd* pParent /*=nullptr*/)
	: CMFCPropertyPage(IDD_PROPPAGE_1, pParent)
{

}

CPropPage1::~CPropPage1()
{
}

void CPropPage1::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPropPage1, CMFCPropertyPage)
END_MESSAGE_MAP()


// CPropPage1 message handlers
