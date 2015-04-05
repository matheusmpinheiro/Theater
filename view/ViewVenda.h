#include "BaseView.h"
#include "../model/Venda.h"
#include "../lib/Lista.h"

#include <iostream>
#include <string>
using std::string;
using std::bad_alloc;

#ifndef VIEWVENDA_H
#define	VIEWVENDA_H

class ViewVenda : public BaseView {
	private:
		static const string menuItens[4];
        Lista<Venda>* vetVenda;
    	int op;
    	Venda v;
    	Data lerData();
    	Tipo lerTipoIngresso();
	public:
		ViewVenda();
	    virtual ~ViewVenda();
	    virtual void show();
	    void setVenda(Lista<Venda>* ls);
	    Lista<Venda>* getVenda();
	    void incluir();//inclui dados no vetor
	    void consultar();
	    void alterar();
	    void remover();
			
};
#endif	/* VIEWVENDA_H */
