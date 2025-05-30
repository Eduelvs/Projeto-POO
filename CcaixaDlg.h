#pragma once
#include "afxdialogex.h"


// caixa de diálogo de CcaixaDlg

class CcaixaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CcaixaDlg)

public:
	CcaixaDlg(CWnd* pParent = nullptr);   // construtor padrão
	virtual ~CcaixaDlg();

// Janela de Dados
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Suporte DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	double rs;
	double rl;
	double rt;
	double ot;
	double ol;
};
