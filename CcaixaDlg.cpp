// CcaixaDlg.cpp : arquivo de implementação
//

#include "pch.h"
#include "Prova7550.h"
#include "afxdialogex.h"
#include "CcaixaDlg.h"


// caixa de diálogo de CcaixaDlg

IMPLEMENT_DYNAMIC(CcaixaDlg, CDialogEx)

CcaixaDlg::CcaixaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, rs(0)
	, rl(0)
	, rt(0)
	, ot(0)
	, ol(0)
{

}

CcaixaDlg::~CcaixaDlg()
{
}

void CcaixaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, rs);
	DDX_Text(pDX, IDC_EDIT2, rl);
	DDX_Text(pDX, IDC_EDIT3, rt);
	DDX_Text(pDX, IDC_EDIT4, ot);
	DDX_Text(pDX, IDC_EDIT5, ol);
}


BEGIN_MESSAGE_MAP(CcaixaDlg, CDialogEx)
END_MESSAGE_MAP()


// manipuladores de mensagens de CcaixaDlg
