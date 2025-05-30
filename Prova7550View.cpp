
// Prova7550View.cpp: implementação da classe CProva7550View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS pode ser definido em um projeto ATL implementando a visualização, a miniatura
// e manipuladores de filtro de pesquisa e permite o compartilhamento de código do documento com esse projeto.
#ifndef SHARED_HANDLERS
#include "Prova7550.h"
#endif

#include "Prova7550Doc.h"
#include "Prova7550View.h"
#include "CcaixaDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProva7550View

IMPLEMENT_DYNCREATE(CProva7550View, CView)

BEGIN_MESSAGE_MAP(CProva7550View, CView)
	// Comandos de impressão padrão
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_CONFIGURAR_ALTERARCORLUA, &CProva7550View::OnConfigurarAlterarcorlua)
	ON_COMMAND(ID_CONFIGURAR_ALTERARCORSOL, &CProva7550View::OnConfigurarAlterarcorsol)
	ON_COMMAND(ID_CONFIGURAR_ALTERARCORTERRA, &CProva7550View::OnConfigurarAlterarcorterra)
	ON_COMMAND(ID_CONFIGURAR_ALTERARRAIO, &CProva7550View::OnConfigurarAlterarraio)
	ON_COMMAND(ID_CONFIGURAR_MOSTRARORBITA, &CProva7550View::OnConfigurarMostrarorbita)
	ON_COMMAND(ID_CONFIGURAR_MOSTRARTIMER, &CProva7550View::OnConfigurarMostrartimer)
	ON_WM_DESTROY()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_CONFIGURAR_MOSTRARORBITA, &CProva7550View::OnUpdateConfigurarMostrarorbita)
	ON_UPDATE_COMMAND_UI(ID_CONFIGURAR_MOSTRARTIMER, &CProva7550View::OnUpdateConfigurarMostrartimer)
END_MESSAGE_MAP()

// Construção/destruição de CProva7550View

CProva7550View::CProva7550View() noexcept
{
	// TODO: adicione o código de construção aqui

}

CProva7550View::~CProva7550View()
{
}

BOOL CProva7550View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modifique a classe ou os estilos de Janela aqui modificando
	//  os cs CREATESTRUCT

	return CView::PreCreateWindow(cs);
}

// desenho de CProva7550View

void CProva7550View::OnDraw(CDC* pDC)
{
	CProva7550Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPoint posicao_terra{};
	CPoint posicao_lua{};

	posicao_terra.x = GetDocument()->posicao_sol.x - GetDocument()->ot * cos((float)GetDocument()->at * 3.141592 / 180);
	posicao_terra.y = GetDocument()->posicao_sol.y - GetDocument()->ot * sin((float)GetDocument()->at * 3.141592 / 180);

	CPen* ant_caneta, orbita(PS_DOT, 1, GetDocument()->cc);
	ant_caneta = pDC->SelectObject(&orbita);
	pDC->SelectObject(orbita);

	pDC->Ellipse((GetDocument()->posicao_sol.x - GetDocument()->ot), (GetDocument()->posicao_sol.y - GetDocument()->ot), (GetDocument()->posicao_sol.x + GetDocument()->ot), (GetDocument()->posicao_sol.y + GetDocument()->ot));
	pDC->Ellipse((posicao_terra.x - GetDocument()->ol), (posicao_terra.y - GetDocument()->ol), (posicao_terra.x + GetDocument()->ol), (posicao_terra.y + GetDocument()->ol));


	pDC->SelectObject(ant_caneta);


	posicao_lua.x = posicao_terra.x - GetDocument()->ol * cos((float)GetDocument()->al * 3.141592 / 180);
	posicao_lua.y = posicao_terra.y - GetDocument()->ol * sin((float)GetDocument()->al * 3.141592 / 180);



	CBrush* ant_pincel, sol(GetDocument()->cor_sol), terra(GetDocument()->cor_terra), lua(GetDocument()->cor_lua);
	ant_pincel = pDC->SelectObject(&sol);
	pDC->SelectObject(sol);
	pDC->Ellipse((GetDocument()->posicao_sol.x - GetDocument()->rs), (GetDocument()->posicao_sol.y - GetDocument()->rs), (GetDocument()->posicao_sol.x + GetDocument()->rs), (GetDocument()->posicao_sol.y + GetDocument()->rs));

	pDC->SelectObject(terra);
	pDC->Ellipse((posicao_terra.x - GetDocument()->rt), (posicao_terra.y - GetDocument()->rt), (posicao_terra.x + GetDocument()->rt), (posicao_terra.y + GetDocument()->rt));

	pDC->SelectObject(lua);
	pDC->Ellipse((posicao_lua.x - GetDocument()->rl), (posicao_lua.y - GetDocument()->rl), (posicao_lua.x + GetDocument()->rl), (posicao_lua.y + GetDocument()->rl));

	// TODO: adicione o código de desenho para dados nativos aqui
}


// impressão de CProva7550View

BOOL CProva7550View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// preparação padrão
	return DoPreparePrinting(pInfo);
}

void CProva7550View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: adicione inicialização extra antes de imprimir
}

void CProva7550View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: adicione a limpeza após a impressão
}


// Diagnóstico de CProva7550View

#ifdef _DEBUG
void CProva7550View::AssertValid() const
{
	CView::AssertValid();
}

void CProva7550View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProva7550Doc* CProva7550View::GetDocument() const // a versão sem depuração está embutida
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProva7550Doc)));
	return (CProva7550Doc*)m_pDocument;
}
#endif //_DEBUG


// Manipuladores de mensagens de CProva7550View


void CProva7550View::OnConfigurarAlterarcorlua()
{
	// TODO: Adicione seu código de manipulador de comandos aqui
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		GetDocument()->cor_lua= dlg.GetColor();
		Invalidate();
	}
}


void CProva7550View::OnConfigurarAlterarcorsol()
{
	// TODO: Adicione seu código de manipulador de comandos aqui
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		GetDocument()->cor_sol = dlg.GetColor();
		Invalidate();
	}
}


void CProva7550View::OnConfigurarAlterarcorterra()
{
	// TODO: Adicione seu código de manipulador de comandos aqui
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		GetDocument()->cor_terra = dlg.GetColor();
		Invalidate();
	}
}


void CProva7550View::OnConfigurarAlterarraio()
{
	// TODO: Adicione seu código de manipulador de comandos aqui
	CcaixaDlg dlg;
	dlg.rs = GetDocument()->rs;
	dlg.rt = GetDocument()->rt;
	dlg.rl = GetDocument()->rl;
	dlg.ot = GetDocument()->ot;
	dlg.ol = GetDocument()->ol;
	if (dlg.DoModal() == IDOK) {
		GetDocument()->rs = dlg.rs;
		GetDocument()->rl = dlg.rl;
		GetDocument()->rt = dlg.rt;
		GetDocument()->ot = dlg.ot;
		GetDocument()->ol = dlg.ol;
		Invalidate();
	}
}


void CProva7550View::OnConfigurarMostrarorbita()
{
	// TODO: Adicione seu código de manipulador de comandos aqui
	if (GetDocument()->cc == RGB(0, 0, 0)) {
		GetDocument()->cc = RGB(255, 255, 255);
	}
	else {
		GetDocument()->cc = RGB(0, 0, 0);
	}
	Invalidate();
}


void CProva7550View::OnConfigurarMostrartimer()
{
	// TODO: Adicione seu código de manipulador de comandos aqui
	if (GetDocument()->Timer) {
		KillTimer(GetDocument()->Timer);
		GetDocument()->Timer = 0;
	}
	else {
		GetDocument()->Timer = SetTimer(1, 365, NULL);
	}
}


void CProva7550View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Adicione seu código de manipulador de mensagens aqui
	CView::OnDestroy();
	if (GetDocument()->Timer) {
		KillTimer(GetDocument()->Timer);
		GetDocument()->Timer = 0;
	}
}


void CProva7550View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Adicione seu código de manipulador de mensagens e/ou chame o padrão

	GetDocument()->posicao_sol = point;
	GetDocument()->SetModifiedFlag();
	GetDocument()->UpdateAllViews(NULL);
	// TODO: Adicione seu código de manipulador de mensagens e/ou chame o padrão
	CView::OnRButtonDown(nFlags, point);

}


void CProva7550View::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1) {
		GetDocument()->at += 1;
		GetDocument()->at %= 380;
		GetDocument()->al += 15;
		GetDocument()->at %= 380;
		Invalidate();
	}
	// TODO: Adicione seu código de manipulador de mensagens e/ou chame o padrão

	CView::OnTimer(nIDEvent);
}


void CProva7550View::OnUpdateConfigurarMostrarorbita(CCmdUI* pCmdUI)
{
	// TODO: Adicione seu código de manipulador da interface do usuário de atualização de comando aqui
	pCmdUI->SetCheck(GetDocument()->cc == RGB(0, 0, 0));
}


void CProva7550View::OnUpdateConfigurarMostrartimer(CCmdUI* pCmdUI)
{
	// TODO: Adicione seu código de manipulador da interface do usuário de atualização de comando aqui
	pCmdUI->SetCheck(GetDocument()->Timer);
}
