/* 
 * File:   GerenciarSala.cpp
 * 
 * Created on 19 de Junho de 2014, 00:04
 */

#include "GerenciarSala.h"
#include "../model/Sala.h"
#include "../model/SalaDAO.h"

#include <iostream>
using namespace std;

GerenciarSala::GerenciarSala() {
}

void GerenciarSala::process() {
    //SessaoDAO sDAO;
    //Lista<Sessao> sessoes = sDAO.consultar();
    Lista<Sala> salas(200);

    tela.setSalas(&salas);

    tela.show();

    cout << "Olha o que cadastrou: Sessoes...." << endl;
    salas.mostra();

    cout << "Saindo do Gerenciamento de Sessoes..." << endl << endl;
}
