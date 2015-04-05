#include "../view/ViewVenda.h"
#include "../lib/Lista.h"

#ifndef GERENCIARVENDA_H
#define GERENCIARVENDA_H

class GerenciarVenda {
public:
    GerenciarVenda();
    void process();
private:
    ViewVenda tela;
};

#endif  /* GERENCIARVENDA_H */