
// Prova7550Doc.cpp: implementação da classe CProva7550Doc
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS pode ser definido em um projeto ATL implementando a visualização, a miniatura
// e manipuladores de filtro de pesquisa e permite o compartilhamento de código do documento com esse projeto.
#ifndef SHARED_HANDLERS
#include "Prova7550.h"
#endif

#include "Prova7550Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CProva7550Doc

IMPLEMENT_DYNCREATE(CProva7550Doc, CDocument)

BEGIN_MESSAGE_MAP(CProva7550Doc, CDocument)
END_MESSAGE_MAP()


// Construção/destruição de CProva7550Doc

CProva7550Doc::CProva7550Doc() noexcept
{
	// TODO: adicione o código de construção avulsa aqui

}

CProva7550Doc::~CProva7550Doc()
{
}

BOOL CProva7550Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: adicione código de reinicialização aqui
	// (Os documentos SDI reutilizarão este documento)

	return TRUE;
}




// serialização de CProva7550Doc

void CProva7550Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: adicione código de armazenamento aqui
		ar << rs << rl<<rt<<cor_lua<<cor_sol<<cor_terra<<posicao_sol;
	}
	else
	{
		// TODO: adicione código de carregamento aqui
		ar >> rs>>rl>>rt>>cor_lua>>cor_sol>>cor_terra>>posicao_sol;
	}
}

#ifdef SHARED_HANDLERS

// Suporte a miniaturas
void CProva7550Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modificar este código para desenhar os dados do documento
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Suporte a Manipuladores de Pesquisa
void CProva7550Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Definir o conteúdo da pesquisa dos dados do documento.
	// As partes do conteúdo devem ser separadas por ";"

	// Por exemplo: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CProva7550Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Diagnóstico de CProva7550Doc

#ifdef _DEBUG
void CProva7550Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProva7550Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// comandos de CProva7550Doc
