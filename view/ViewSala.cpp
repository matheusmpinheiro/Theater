/* 
 * File:   ViewSala.cpp
 * Author: pc
 * 
 * Created on 18 de Junho de 2014, 21:18
 */

#include "ViewSala.h"

#include <string>
#include <iostream>
using namespace std;

const string ViewSala::menuItems[5] = {"Incluir", "Consultar", "Alterar", "Remover", "Sair"};
const string ViewSala::titulo = "CADASTRO DE SALAS";

ViewSala::ViewSala() : BaseView(titulo) {
}

ViewSala::~ViewSala() {                     
}

void ViewSala::show() {
    setMenu(menuItems, 5, "OPERACOES");
    printHeaderE();
    printMenuE();
    int opt = readMenuOpt(1, 5);
    
    while (opt != 5) {
        switch(opt) {
            case 1:
                incluir();
                break;
            case 2:
                consultar();
                break;
            case 3:
                alterar();
                break;
            case 4:
                remover();
                break;
        }
        opt = readMenuOpt(1, 5);
    }
}

void ViewSala::setSalas(Lista<Sala>* ls) {
    this->vetSala = ls;
}

void ViewSala::incluir() {
    int num, capacidade, qtdFileiras;
    Situacao situ;
    
    num = lerIntMaiorQue(1, "Informe o numero da sala(A partir de 1): ",
        "O numero deve ser maior que 0");

    capacidade = lerIntEntre(50, 200, "Informe a capacidade da sala, assentos(50..200): ",
        "A capacidade deve estar entre 50 e 200");

    qtdFileiras = lerIntEntre(1, 26, "Informe a quantidade de fileiras(1..26): ",
        "A quantidade deve estar entre 1 e 26");

    situ = lerSituacao();

    Sala s(num, situ, capacidade, qtdFileiras);

    try {
        vetSala->insere(s);
        cout << "Sala inserida com sucesso." << endl;
        cout << "___________________________________" << endl;
        cout << s << endl;;
    } catch(const string& s) {
        cerr << s << endl;
    }
}

void ViewSala::consultar() {
    Sala s;

    int num = lerIntMaiorQue(1, "Informe o numero da sala(A partir de 1): ",
        "O numero deve ser maior que 0");

    s.setNumSala(num);

    //retorna -1 se não encontra
    int pos = vetSala->localiza(s);

    if(pos != -1){
        cout << "A sala consultada: " << endl;
        cout << "___________________________________" << endl;
        cout << vetSala->elementoEm(pos) << endl;
    } else {
        cout << "A sala " << num << " não foi encontrada!" << endl;
    }
}

void ViewSala::alterar(){
    Sala s;

    int num = lerIntMaiorQue(1, "Informe o numero da sala(A partir de 1): ",
        "O numero deve ser maior que 0");

    s.setNumSala(num);

    int pos = vetSala->localiza(s);

    if(pos != -1){
        Sala s(vetSala->elementoEm(pos));
        try {
            vetSala->remove(s);
            cout << "Alteração da sala: " << num << endl;
            incluir();
        } catch(const string& s) {
            cerr << "Desculpe! Não foi possível realizar a operação" << endl;
        }
    } else {
        cout << "A sala " << num << " não foi encontrado!" << endl;
    }
}

void ViewSala::remover() {
    Sala s;

    int num = lerIntMaiorQue(1, "Informe o numero da sala(A partir de 1): ",
        "O numero deve ser maior que 0");

    s.setNumSala(num);

    int pos = vetSala->localiza(s);

    if (pos != -1) {
        Sala s(vetSala->elementoEm(pos));
        try {
            vetSala->remove(s);
            cout << "Sala removida com sucesso." << endl;
            cout << "___________________________________" << endl;
            cout << s << endl;
        } catch(const string& s) {
            cerr << s << endl;
        }
    } else {
        cout << "Impossível remover! A sala " << num << " nao foi encontrada!" << endl;
    }
    
}

/* Receber corretamente a situação de uma sala */
Situacao ViewSala::lerSituacao() {
    Situacao situ;

    cout << "1. Disponivel\t2. Manutencao em Equipamento\t3. Reforma\t4.Manutencao geral" << endl;
    situ = (Situacao) lerIntEntre(1, 4, "Informe a situacão da sala", "Apenas valores entre 1 e 4");

    return situ;
}
