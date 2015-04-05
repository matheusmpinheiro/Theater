/* 
* File:   main.cpp
* Author: pc
*
* Created on 18 de Junho de 2014, 11:05
*/

/*
#############################################
# TRABALHO INTEGRADO ED1+POO                #
# Sistema de Gerenciamento de Cinema        #
#                                           #
# Grupo Formado por:                        #
#   Caio Bonafé Cacuro          R.A: 489654 #
#   Gabriela de Jesus Martins   R.A: 489689 #
#   Matheus Moraes Pinheiro     R.A: 489719 #
#   Thais Akemi Iwanaga Inaba   R.A: 489891 #
#   Valdeir Soares Perozim      R.A: 489786 #
#############################################
*/

#include <iostream>
using namespace std;

#include "view/BaseView.h"
#include "control/GerenciarSala.h"
#include "control/GerenciarSessao.h"
//#include "control/VenderIngresso.h"

enum Control {SALA = 1, SESSAO, RELATORIOS, VENDA, SOBRE, SAIR};

void dispatch(Control ctl);
void mostrarSobre();

/*
 * 
 */
int main() {
    
    BaseView tela;

    string menu[] = {"Sala", "Sessao", "Relatorios", "Venda", "Sobre", "Sair"};
    string titulo = "BEM VINDO AO SISTEMA";
    
    // string[] com itens do menu, número de opções, título para o menu
    tela.setMenu(menu, 6, "Menu Principal");
    tela.setHeader(titulo);
    
    Control opt;
    do {
        //Ler opções entre <inicio>,<fim>
        opt = (Control) tela.readMenuOpt(1, 6);
        dispatch(opt);

    } while(opt != SAIR);

    return 0;
}

void dispatch(Control ctl) {

    static GerenciarSala gSala;
    static GerenciarSessao gSessao;
    //VenderIngresso vender;

    switch(ctl) {
        case SALA:
            gSala.process();
            break;
        case SESSAO:
            gSessao.process();
            break;
        case RELATORIOS:
            //relatorio.process();
            cout << "Sem exibicao de relatorios" << endl;
            break;
        case VENDA:
            //vender.process();
            cout << "Sem modulo de vendas" << endl;
            break;
        case SOBRE:
            mostrarSobre();
            break;
        case SAIR:
            cout << endl;
            cout << "Encerrando aplicacao..." << endl;
            break;
        default:
            cerr << endl;
            cerr << "Opção incorreta!" << endl;
            break;
    }
}

void mostrarSobre() {

    BaseView tela("SOBRE O PROJETO");
    tela.clearScreen();
    tela.printHeaderE();

    cout << endl;
    cout << "*********************************************" << endl;
    cout << "* TRABALHO INTEGRADO ED1+PROJETO            *" << endl;
    cout << "* Sistema de Gerenciamento de Cinema        *" << endl;
    cout << "*                                           *" << endl;
    cout << "* Grupo Formado por:                        *" << endl;
    cout << "*  Caio Bonafe Cacuro          R.A: 489654  *" << endl;
    cout << "*  Gabriela de Jesus Martins   R.A: 489689  *" << endl;
    cout << "*  Matheus Moraes Pinheiro     R.A: 489719  *" << endl;
    cout << "*  Thais Akemi Iwanaga Inaba   R.A: 489891  *" << endl;
    cout << "*  Valdeir Soares Perozim      R.A: 489786  *" << endl;
    cout << "*********************************************" << endl;

}
