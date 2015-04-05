/* 
* File:   GerenciarSessao.h
* 
* Created on 19 de Junho de 2014
*
* Implementa o control GerenciarSessao do Diagrama de classes
*/

/*
******************************************************************************
* GERENCIAR SESSÕES
* ****************************************************************************
* 	1. INSTANCIA
* 	
*	ViewSessao	: Objeto tela;
*	SessaoDAO	: sDAO;
* 
* ****************************************************************************
*	2. FUNCIONAMENTO
*	
* 	A classe instancia um objeto tela para apresentar um menu e receber os 
* dados de cadastro de uma ou mais sessoes. 
*	Após instanciá-la passa define através do método setSessoes() uma lista
* de sessões previamente cadastradas que leu do arquivo Sessoes.dat com o 
* objeto sDAO.
* 	Após o usuário selecionar umas das possíveis opções de CRUD, recebe uma
* lista de sessões que salvará em arquivo com o objeto sDAO após chamar seu
* método gravar(). 
* ****************************************************************************
*/

#include "../view/ViewSessao.h"
#include "../lib/Lista.h"

#ifndef GERENCIARSESSAO_H
#define GERENCIARSESSAO_H

class GerenciarSessao {
public:
    GerenciarSessao();
    void process();
private:
    ViewSessao tela;
};

#endif  /* GERENCIARSESSAO_H */