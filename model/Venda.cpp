#include "Venda.h"

#include <iostream>
#include <iomanip>
using namespace std;

Venda::Venda() : dtVenda(1, 1, 1) {
    this->valorTotal = 0;
    this->qtdIngresso = 0;
    this->pagamento = DINHEIRO;
}

Venda::Venda(Data dt, FormaPgto forma) : dtVenda(dt) { 
	this->valorTotal = 0;
	this->qtdIngresso = 0;
    this->pagamento = forma;
}

Venda::~Venda() {
}

void Venda::setData(Data& dt){ //alterei aqui
    dtVenda = dt;
}

Data Venda::getData(){ //alterei aqui
    return dtVenda;
}

int Venda::localizaIngresso(Ingresso& bilhete) {
    for (int i = 0; i < MAX; i++) {
        if (bilhetes[i].getTipo() == bilhete.getTipo())
            if (bilhetes[i].getDtIngresso() == bilhete.getDtIngresso())
                return i;
    }

    return -1;
}

double Venda::calcularValorTotal() {
    int i;   
    for(i = 0; i < qtdIngresso; i++) {
        // Se não é INTEIRO é MEIA  
        if (bilhetes[i].getTipo() == INTEIRO)
            valorTotal += bilhetes[i].getValor();
        else
            valorTotal += bilhetes[i].getValor() / 2;
    }      

    return valorTotal;
}

void Venda::emitirIngresso() {
    cout << "Recibo:" << endl;
    cout << "Data: " << dtVenda << endl;
    cout << "Valor: R$" << valorTotal << endl;
    cout << "__________________________________" << endl;
    for (int i = 0; i < qtdIngresso; i++) {
        cout << "Bilhete n. " << i + 1 << endl;
        cout << this->bilhetes[i] << endl;
    }
    cout << "__________________________________" << endl;
}

void Venda::addIngresso(Ingresso& bilhete){
    
    if (qtdIngresso < MAX) {
        if (localizaIngresso(bilhete) < 0)
            bilhetes[qtdIngresso++] = bilhete;
        else
            throw "Ingresso ja incluido";
    } else {
        throw "Voce atingiu limite de 20 ingressos por compra";
    }
}

void Venda::removeIngresso(Ingresso& bilhete) {
    int pos = localizaIngresso(bilhete);
    if (pos >= 0) {
        // Compacta vetor
        for (int i = pos; i < qtdIngresso-1; i++) {
            bilhetes[i] = bilhetes[i+1];
        }
        qtdIngresso--;
    } else {
        throw "Impossivel remover. Ingresso nao encontrado.";
    }
}

bool Venda::operator==(const Venda &v) {
    if(this->dtVenda != v.dtVenda && this->valorTotal != v.valorTotal)
        return false;
     
    return true;
}

bool Venda::operator<(const Venda &v) {
    return (this->valorTotal < v.valorTotal);
}

std::ostream& operator<<(std::ostream& out, Venda &v) {
    out.precision(2);
    out << setw(15) << "Data de venda: " << setw(10) << v.dtVenda << endl;
    out << setw(15) << "Valor da venda:" << setw(10) << " R$ " << v.valorTotal;
    
    return out;
}
