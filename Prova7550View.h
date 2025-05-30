
// Prova7550View.h: interface da classe CProva7550View
//

#pragma once


class CProva7550View : public CView
{
protected: // criar apenas com base na serialização
	CProva7550View() noexcept;
	DECLARE_DYNCREATE(CProva7550View)

// Atributos
public:
	CProva7550Doc* GetDocument() const;

// Operações
public:

// Substitui
public:
	virtual void OnDraw(CDC* pDC);  // substituído para desenhar esta visualização
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementação
public:
	virtual ~CProva7550View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funções geradas de mapa de mensagens
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnConfigurarAlterarcorlua();
	afx_msg void OnConfigurarAlterarcorsol();
	afx_msg void OnConfigurarAlterarcorterra();
	afx_msg void OnConfigurarAlterarraio();
	afx_msg void OnConfigurarMostrarorbita();
	afx_msg void OnConfigurarMostrartimer();
	afx_msg void OnDestroy();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnUpdateConfigurarMostrarorbita(CCmdUI* pCmdUI);
	afx_msg void OnUpdateConfigurarMostrartimer(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // versão de depuração em Prova7550View.cpp
inline CProva7550Doc* CProva7550View::GetDocument() const
   { return reinterpret_cast<CProva7550Doc*>(m_pDocument); }
#endif

