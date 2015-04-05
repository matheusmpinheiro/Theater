#include "ViewVenda.h"
#include "../lib/Data.h"
#include "../model/Ingresso.h"

#include <string>
#include <iostream>

using namespace std;

const string ViewVenda::menuItems[5] = {"Incluir Ingresso", "Mostrar Venda", "Alterar Venda", "Remover Ingresso", "Voltar"};
enum Operacao {INCLUIR INGRESSO = 1, MOSTRAR VENDA, ALTERAR VENDA, REMOVER INGRESSO, VOLTAR};

ViewVenda::ViewVenda():BaseView("BEM VINDO AO GERENCIAMENTO DE VENDAS") {
}

void ViewVenda::show(){
   printHeaderE();
    setHeader("VENDA DE INGRESSOS");
    setMenu(menuItems, 5, "OPERACOES");
    op = readMenuOpt(1, 5);

    while(op!=5) {
        switch(op) {
            case 1:
                Incluir();
                break;
            case 2:
                Consultar();
                break;
            case 3:
                Alterar();
                break;
            case 4:
                Remover();
                break;
        }
        op = readMenuOpt(1, 5);
    }
}

void ViewVenda::setVenda(Lista<Venda>* ls) {
    this->vetVenda = ls;
}

Lista<Venda>* ViewVenda::getVenda() {
    return this->vetVenda;
}

void ViewVenda::Incluir() {
    Data dtV;//data venda 
    Data dtI;//data ingresso
    int qtdIngressos;
    int dia, mes, ano;
    Ingresso b;
    int i;
    int t;//tipo
    double preco;
    

    cout<<"Digite a data da venda:"<<endl;
    cout<<"Dia: "<<endl;
    cin>>dia;
    cout<<"Mes: "<<endl;
    cin>>mes;
    cout<<"Ano: "<<endl;
    cin>>ano;

    dtV.atualizaDia(dia);
    dtV.atualizaMes(mes);
    dtV.atualizaAno(ano);

    v.setData(dtV);

    cout <<"Digite a quantidade de ingressos que deseja comprar"<<endl;
    cin>>qtdIngressos;

    if(qtdIngressos < 20){
        for(i=0; i<qtdIngressos; i++){
            cout << "Digite a data do ingresso "<< i+1 <<":"<<endl;
            cout<<"Dia: "<<endl;
            cin>>dia;
            cout<<"Mes: "<<endl;
            cin>>mes;
            cout<<"Ano: "<<endl;
            cin>>ano;

            dtI.atualizaDia(dia);
            dtI.atualizaMes(mes);
            dtI.atualizaAno(ano);
            b.setDtIngresso(dtI);

            cout << "Digite o preco do ingresso "<< i+1 <<":"<<endl;
            cin>>preco;

            b.setValor(preco);

            cout << "Digite o tipo do ingresso (0 para inteiro e 1 para meia) "<< i+1 <<":"<<endl;
            cin>>(Tipo)t;

            b.setTipo(t);

            v.addIngresso(b);
        }
    }
}

void ViewSessao::Consultar() {
   
   v.emitirIngresso();

 }

void ViewSessao::Alterar(){
    Data dtI;
    int dia, mes, ano;
    Ingresso b, novoB;
    int t;//tipo
    double preco;

    cout<<"Digite a data do ingresso que deseja alterar: "<<endl;
    cout<<"Dia: "<<endl;
    cin>>dia;
    cout<<"Mes: "<<endl;
    cin>>mes;
    cout<<"Ano: "<<endl;
    cin>>ano;

    dtI.atualizaDia(dia);
    dtI.atualizaMes(mes);
    dtI.atualizaAno(ano);
    b.setDtIngresso(dtI);

    cout << "Digite o tipo do ingresso (0 para inteiro e 1 para meia) que deseja alterar: "<<endl;
    cin>>(Tipo)t;
    
    b.setTipo(t);

    v.removeIngresso(b);

    cout << "Digite a data do novo ingresso "<< i+1 <<":"<<endl;
    cout<<"Dia: "<<endl;
    cin>>dia;
    cout<<"Mes: "<<endl;
    cin>>mes;
    cout<<"Ano: "<<endl;
    cin>>ano;

    dtI.atualizaDia(dia);
    dtI.atualizaMes(mes);
    dtI.atualizaAno(ano);
    novoB.setDtIngresso(dtI);

    cout << "Digite o preco do ingresso "<< i+1 <<":"<<endl;
    cin>>preco;

    novoB.setValor(preco);

    cout << "Digite o tipo do ingresso (0 para inteiro e 1 para meia) "<< i+1 <<":"<<endl;
    cin>>(Tipo)t;

    novoB.setTipo(t);

    v.addIngresso(novoB);

}

void ViewSessao::Remover(){
   Data dtI;
    int dia, mes, ano;
    Ingresso b;
    int t;

    cout<<"Digite a data do ingresso que deseja remover: "<<endl;
    cout<<"Dia: "<<endl;
    cin>>dia;
    cout<<"Mes: "<<endl;
    cin>>mes;
    cout<<"Ano: "<<endl;
    cin>>ano;

    dtI.atualizaDia(dia);
    dtI.atualizaMes(mes);
    dtI.atualizaAno(ano);
    b.setDtIngresso(dtI);

    cout << "Digite o tipo do ingresso (0 para inteiro e 1 para meia) que deseja remover: "<<endl;
    cin>>(Tipo)t;
    
    b.setTipo(t);

    v.removeIngresso(b);
}

