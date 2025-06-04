# Projeto-POO

Este repositório contém o projeto **Prova7550**, desenvolvido para a disciplina de Programação Orientada a Objetos (POO).

## Sobre o Projeto

Este projeto é uma aplicação MDI (Multiple Document Interface) desenvolvida em C++ utilizando MFC (Microsoft Foundation Classes). O objetivo principal é simular o sistema Sol-Terra-Lua, permitindo manipular parâmetros como raios, cores e órbitas dos astros, além de exibir animações e interações gráficas.

## Funcionalidades

- **Simulação do Sistema Sol-Terra-Lua:** Visualização gráfica das órbitas e posições relativas.
- **Configuração de Parâmetros:** Permite alterar as cores do Sol, Terra e Lua, bem como modificar os raios das órbitas.
- **Timer/Animação:** É possível iniciar/parar a animação do movimento dos astros.
- **Interação Gráfica:** O usuário pode reposicionar o Sol clicando com o botão direito do mouse na visualização.
- **Persistência:** Os parâmetros (raios, cores, posições) podem ser salvos e carregados.

## Principais Classes

- `CProva7550App`: Classe principal da aplicação.
- `CProva7550Doc`: Gerencia os dados do documento e os parâmetros físicos/visuais do sistema.
- `CProva7550View`: Responsável pelo desenho dos elementos na tela e manipulação das interações do usuário.

## Como Executar

1. **Pré-requisitos:**  
   - Windows  
   - Visual Studio com suporte a MFC  
2. **Compilação:**  
   - Abra o projeto no Visual Studio.
   - Compile a solução.
3. **Execução:**  
   - Execute o programa diretamente do Visual Studio ou pelo executável gerado.

## Estrutura dos Arquivos

- `Prova7550.cpp`, `Prova7550.h`: Inicialização da aplicação.
- `Prova7550Doc.cpp`, `Prova7550Doc.h`: Lógica de dados e serialização.
- `Prova7550View.cpp`, `Prova7550View.h`: Lógica de visualização e interação.
- `MainFrm.h/cpp`, `ChildFrm.h/cpp`: Janelas principais e secundárias da interface MDI.

## Créditos

Desenvolvido por [Eduelvs](https://github.com/Eduelvs) para fins acadêmicos.
