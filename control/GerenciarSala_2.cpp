#include "GerenciarSala.h"
#include "../view/ViewSala.h"
#include "../lib/Lista.h"
#include "../model/Sala.h"
//#include "../model/SessaoDAO.h"

#include <iostream>
using namespace std;
using std::string;
#include <cstdlib>

GerenciarSessao::GerenciarSessao() {
}

void GerenciarSessao::process() {
    //SessaoDAO sDAO;
    //Lista<Sessao> sessoes = sDAO.consultar();
    
    // Código a ser substituido
    cout << "instanciando sala"<<endl;
    Lista<Sala> vetSala(50);

    cout << "instanciando salas" << endl;
    
    Sala sl1(1, 1, 30, 3);
    Sala sl1(1, 4, 30, 3);
    

    cout << "inserindo salas" << endl;
    try {
        vetVenda.insere(sl1);
        vetVenda.insere(sl2);
    } catch(const string& s) {
        cerr << s << endl;
        exit(1);
    }
    //Fim código

    cout << "Adicionar sessao" << endl;
    tela.setVenda(&vetSala);

    cout << "mostra tela" << endl;
    tela.show();

    //Lista<Sala>* sala_res(tela.getSala());//não existe esse método em viewSala (veja essa linha)

    cout << "Olha o que cadastrou: Sala...." << endl;
    sala_res->mostra();

    /*SessaoDAO sDAO;
    sDAO.incluir(sessao2);

    cout << "Agora vai ler a parada:" << endl;

    Sessao sleu = sDAO.consultar(1);

    cout << "Vai printar a parada:...." << endl;
    cout << sleu << endl;*/

    cout << "Saindo do Gerenciamento de Sala..." << endl << endl;
}
