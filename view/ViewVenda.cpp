#include "ViewVenda.h"
#include "../lib/Data.h"
#include "../model/Ingresso.h"

#include <string>
#include <iostream>

using namespace std;

const string ViewVenda::menuItens[4] = {"Comprar", "Mostrar Venda", "Remover Ingresso", "Voltar"};
enum Operacao {COMPRAR = 1, CONSULTAR, REMOVER, VOLTAR};

ViewVenda::ViewVenda():BaseView("BEM VINDO AO GERENCIAMENTO DE VENDAS") {
    vetVenda = NULL;
}

ViewVenda::~ViewVenda() {
}

void ViewVenda::show() {
    printHeaderE();
    setHeader("VENDA DE INGRESSOS");
    setMenu(menuItens, 4, "OPERACOES");
    op = readMenuOpt(1, 4);

    while( op != 4) {
        switch(op) {
            case INCLUIR:
                incluir();
                break;
            case CONSULTAR:
                consultar();
                break;
            case REMOVER:
                remover();
                break;
            case VOLTAR:
                break;
        }
        op = readMenuOpt(1, 4);
    }
}

void ViewVenda::setVenda(Lista<Venda>* ls) {
    this->vetVenda = ls;
}

Lista<Venda>* ViewVenda::getVenda() {
    return this->vetVenda;
}

void ViewVenda::incluir() {
    Data dtV;//data venda 
    Data dtI;//data ingresso
    int qtdIngressos;
    Ingresso ingr;
    double preco;
    Tipo t;

    dtV = lerData();

    v.setData(dtV);

    qtdIngressos = lerIntEntre(1, 20, "Informe a quantidade de ingressos que deseja comprar(1..20): ",
     "Por favor, informe apenas números entre 1 e 20");
    
    for(int i = 0; i < qtdIngressos; i++){
        dtI = lerData();
        ingr.setDtIngresso(dtI);
           
        cout << "Digite o preco do ingresso "<< i+1 <<":"<<endl;
        cin>>preco;

        ingr.setValor(preco);
        t=lerTipoIngresso();

        ingr.setTipo(t);
        v.addIngresso(ingr);
    }
}

void ViewVenda::consultar() {
   
   v.emitirIngresso();

 }

void ViewVenda::alterar(){
    Data dtI;
    Ingresso b, novoB;
    int i = 0;
    Tipo t;
    double preco;

    dtI = lerData();
    b.setDtIngresso(dtI);

    t = lerTipoIngresso();
    
    b.setTipo(t);

    v.removeIngresso(b);

    cout << "Digite a data do novo ingresso "<< i+1 <<":"<<endl;
    dtI = lerData();
    novoB.setDtIngresso(dtI);

    cout << "Digite o preco do ingresso "<< i+1 <<":"<<endl;
    cin>>preco;

    novoB.setValor(preco);

    t = lerTipoIngresso();

    novoB.setTipo(t);

    v.addIngresso(novoB);

}

void ViewVenda::remover(){
    Data dtI;
    Ingresso b;
    Tipo t;

    dtI = lerData();
    b.setDtIngresso(dtI);

    t = lerTipoIngresso();
    
    b.setTipo(t);

    v.removeIngresso(b);
}

Data ViewVenda::lerData(){
    Data dtI;
    int dia, mes, ano, i = 0;
    do {
        cout << "Digite a data do ingresso "<< i+1 <<":"<<endl;
        cout<<"Dia: "<<endl;
        cin>>dia;
        cout<<"Mes: "<<endl;
        cin>>mes;
        cout<<"Ano: "<<endl;
        cin>>ano;

        if(dia > 31 || dia < 1 || mes> 12 || mes < 1){
            cout << "Por favor informe somente um data valida!" << endl;
            continue;
        }

        dtI.atualizaDia(dia);
        dtI.atualizaMes(mes);
        dtI.atualizaAno(ano);
            
    } while (true);

    return dtI;
}

Tipo ViewVenda::lerTipoIngresso() {
    Tipo tp;

    tp = (Tipo) lerIntEntre(0, 1, "Informe o tipo do ingresso (0 = INTEIRO 1 = MEIA)",
     "Por favor, informe somente 0 ou 1");

    return tp;
}

