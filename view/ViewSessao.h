#include "BaseView.h"
#include "../model/Sessao.h"
#include "../lib/Lista.h"

#include <string>
#include <iostream>
using std::string;
using std::bad_alloc;

#ifndef SESSAOVIEW_H
#define	SESSAOVIEW_H

class ViewSessao : BaseView {
private:
	static const string menuItems[5];
	Lista<Sessao>* vetSessao;
    int op;
    int lerStatus();
    string lerFilme();
public:
    ViewSessao();
    virtual ~ViewSessao();
    virtual void show();
    void setSessoes(Lista<Sessao>* ls);
    Lista<Sessao>* getSessoes();
    void incluir();
    void consultar();
    void alterar();
    void remover();
};

#endif	/* BASEVIEW_H */
