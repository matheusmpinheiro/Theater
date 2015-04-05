/* 
 * File:   ViewSala.h
 * Author: pc
 *
 * Created on 18 de Junho de 2014, 21:18
 */

#include "BaseView.h"
#include "../model/Sala.h"
#include "../model/Fileira.h"
#include "../lib/Lista.h"

#include <iostream>
using std::string;

#ifndef VIEWSALA_H
#define	VIEWSALA_H

class ViewSala : public BaseView {
private:
    static const string menuItems[5];
    static const string titulo;
    Lista<Sala>* vetSala;
    Situacao lerSituacao();
public:
    ViewSala();
    virtual ~ViewSala();
    virtual void show();
    void setSalas(Lista<Sala>* ls);
    void incluir();
    void consultar();
    void alterar();
    void remover();
};

#endif	/* VIEWSALA_H */

