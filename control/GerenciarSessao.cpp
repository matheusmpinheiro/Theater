
#include "GerenciarSessao.h"
#include "../view/ViewSessao.h"
#include "../lib/Lista.h"
#include "../model/Sessao.h"
#include "../model/SessaoDAO.h"

#include <iostream>
using namespace std;
using std::string;
#include <cstdlib>

GerenciarSessao::GerenciarSessao() {
}

void GerenciarSessao::process() {
    //SessaoDAO sDAO;
    //Lista<Sessao> sessoes = sDAO.consultar();
    
    Lista<Sessao> sessoes(200);

    tela.setSessoes(&sessoes);

    tela.show();

    cout << "Saindo do Gerenciamento de Sessoes..." << endl << endl;
}
