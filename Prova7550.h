
// Prova7550.h: arquivo de cabeçalho principal para o aplicativo Prova7550
//
#pragma once

#ifndef __AFXWIN_H__
	#error "inclua 'pch.h' antes de incluir este arquivo para PCH"
#endif

#include "resource.h"       // símbolos principais


// CProva7550App:
// Consulte Prova7550.cpp para a implementação desta classe
//

class CProva7550App : public CWinApp
{
public:
	CProva7550App() noexcept;
	double rs{ 200 };
	double rt{ 40 };
	double rl{ 15 };
	double ol{ 60 };
	double ot{ 300 };
	int anguloLua{ 30 };
	int anguloTerra{ 30 };
	COLORREF cor_sol{ RGB(0,0,0) };
	COLORREF cor_lua{ RGB(100,100,100) };
	COLORREF cor_terra{ RGB(0,0,255) };
	COLORREF cor_caneta{ RGB(0,0,0) };
	CPoint posicao_sol{ 600,300 };
	UINT Temporizador{ 0 };

// Substitui
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementação
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProva7550App theApp;
