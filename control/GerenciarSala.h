/* 
* File:   GerenciarSala.h
* 
* Created on 19 de Junho de 2014
*
* Implementa o control gerenciarSala do Diagrama de classes
*/

#include "../view/ViewSala.h"
#include "../lib/Lista.h"

#ifndef GERENCIARSALA_H
#define GERENCIARSALA_H

class GerenciarSala {
public:
    GerenciarSala();
    void process();
private:
    ViewSala tela;
};

#endif  /* GERENCIARSALA_H */