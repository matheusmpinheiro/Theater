/* 
* File:   Ingresso.cpp
* Author: pc
*
* Created on 24 de Junho de 2014
*/

#include "Ingresso.h"
#include "../lib/Data.h"

#include <iostream>
using namespace std;

Ingresso::Ingresso() : dtIngresso(1, 1, 1) {
 	this->valor = -1;
 	this->tipo = MEIA;
}

Data Ingresso::getDtIngresso() const {
	return dtIngresso;
}

double Ingresso::getValor() const {
	return valor;
}

Tipo Ingresso::getTipo() const {
 	return tipo;
}

void Ingresso::setDtIngresso(Data& data){
 	this->dtIngresso = data;
}

void Ingresso::setValor(double valor){
 	if (valor >= 0) {
 		this->valor = valor;
 	} else {
 		throw "O valor do ingresso nao pode ser negativo";
 	}
}

void Ingresso::setTipo(Tipo tipoIngresso){
 	this->tipo = tipoIngresso;
}

std::ostream &operator<< (std::ostream &out, const Ingresso& i) {
	out << " ____________________________ " << endl;
	out << "|                            |" << endl;
	out << "| Data de emissao: " 	<< i.dtIngresso << " |" << endl;
	out.precision(2);
	out << "| Valor do Ingresso: R$ " << i.valor << "  |" << endl;
	if(i.tipo == INTEIRO)
		out << "| Tipo de ingresso: INTEIRA " << " |" << endl;
	else
		out << "| Tipo de ingresso: MEIA" << "    |" << endl;

	out << "|____________________________|" << endl;

	return out;
}

/*bool Ingresso::operator==(const Ingresso& t) { 
  
    if (this->dtIngresso != t.dtIngresso || this->tipo != t.tipo) 
        return false; 

    return true; 
}*/

