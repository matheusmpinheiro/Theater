#include "VenderIngresso.h"
#include "../model/Venda.h"
#include "../model/Ingresso.h"
#include "../model/Sessao.h"
#include "../view/ViewVenda.h"
#include "../lib/Data.h"
#include "../lib/Lista.h"

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
    cout << "instanciando venda"<<endl;
    Lista<Venda> vetVenda(100);

    cout << "instanciando vendas" << endl;
    Data dt;
    dt.atualizaDia(01);
    dt.atualizaDia(01);
    dt.atualizaDia(01);

    Venda v1(dt, 1);
    Venda v2(dt, 1);
    

    cout << "inserindo venda" << endl;
    try {
        vetVenda.insere(v1);
        vetVenda.insere(v2);
    } catch(const string& s) {
        cerr << s << endl;
        exit(1);
    }
    //Fim código

    cout << "Adicionar sessao" << endl;
    tela.setVenda(&vetVenda);

    cout << "mostra tela" << endl;
    tela.show();

    Lista<Venda>* venda_res(tela.getVenda());

    cout << "Olha o que cadastrou: Sessoes...." << endl;
    venda_res->mostra();

    /*SessaoDAO sDAO;
    sDAO.incluir(sessao2);

    cout << "Agora vai ler a parada:" << endl;

    Sessao sleu = sDAO.consultar(1);

    cout << "Vai printar a parada:...." << endl;
    cout << sleu << endl;*/

    cout << "Saindo do Gerenciamento de Venda..." << endl << endl;
}
