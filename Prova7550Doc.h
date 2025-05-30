
// Prova7550Doc.h: interface da classe CProva7550Doc
//


#pragma once


class CProva7550Doc : public CDocument
{
protected: // criar apenas com base na serialização
	CProva7550Doc() noexcept;
	DECLARE_DYNCREATE(CProva7550Doc)

// Atributos
public:
	COLORREF cor_sol{ RGB(255,255,0) };
	COLORREF cor_lua{ RGB(211,211,211) };
	COLORREF cor_terra{ RGB(0,127,255) };
	COLORREF cc{ RGB(0,0,0) };
	CPoint posicao_sol{ 600,300 };
	UINT Timer{ 0 };
	int al{ 30 };
	int at{ 30 };
	double rs{ 150 };
	double rt{ 30 };
	double rl{ 10 };
	double ol{ 60 };
	double ot{ 300 };



// Operações
public:

// Substitui
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementação
public:
	virtual ~CProva7550Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funções geradas de mapa de mensagens
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Função auxiliar que define o conteúdo de pesquisa para um Manipulador de Pesquisa
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
