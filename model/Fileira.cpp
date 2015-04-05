/* 
* File:   Fileira.cpp
* Author: pc
*
* Created on 21 de Junho de 2014
*/

#include "Fileira.h"

#include <iostream>
#include <iomanip>
using namespace std;

/* Construtor padrão: Cria uma fileira "vazia" */
Fileira::Fileira() : assentos(1) {
	this->idFileira = 0;
	this->qtdAssentos = 0;
	this->assentoDisponivel = false;
}

/* Construtor para criar um objeto somente informando o id */
Fileira::Fileira(char id) {
	this->idFileira = id;
	this->qtdAssentos = 0;
	this->assentoDisponivel = false;
}

/* Construtor para definir id da Fileira e assentos */
Fileira::Fileira(char id, int qtdAssentos) : assentos(qtdAssentos) {
	this->idFileira = id;
	this->assentoDisponivel = true;
	this->qtdAssentos = qtdAssentos;
}

/* Construtor de cópia: Para a lista de assentos */
Fileira::Fileira(const Fileira& fila) : assentos(fila.assentos) {
	this->idFileira = fila.idFileira;
	this->assentoDisponivel = fila.assentoDisponivel;
	this->qtdAssentos = fila.qtdAssentos;
}

/* Retorna a disponibilidade de assentos na fileira */
bool Fileira::verificaDisponibilidade() const{
	
	int lim = assentos.tamanho();
	int qtd = 0;

	for(int i = 0; i < lim; i++) {
		if (assentos.elementoEm(i).verificaDisponibilidade() == true) {
			qtd++;
			break;
		}
	}

	return (qtd > 0);
}

void Fileira::adicionarAssento(int idAssento) {
	Assento aux(idAssento, idFileira);
	
	try {
		assentos.insere(aux);
	} catch(const string* e) {
		cerr << e << endl;
	}
}

void Fileira::removerAssento(int idAssento) {

	Assento aux(idAssento, idFileira);
	try {
		assentos.remove(aux);
	} catch(const string* e) {
		cerr << e << endl;
	}
}

/* Sobrecarga do operador == para uso no algoritmo de ordenação de LISTA_H */
bool Fileira::operator==(const Fileira& fila) {

	if (this->idFileira != fila.idFileira) {
		return false;
	}

	return true;
}

/* Sobrecarga do operador < para uso no algoritmo de ordenação de LISTA_H */
bool Fileira::operator<(const Fileira& fila) {
	return (this->idFileira < fila.idFileira);
}

/* Sobrecarga do operador << */
std::ostream& operator<<(std::ostream& out, const Fileira& fila) {
	out << std::setw(17) << "Identificacao: " << fila.idFileira;
	out << std::setw(17) << "Assentos: " << fila.qtdAssentos << endl;
	out << std::setw(17) << "Disponibilidade: ";
	if (fila.assentoDisponivel)
		cout << "Assentos disponiveis";
	else
		cout << "Sem assentos disponiveis";

	cout << endl;

	return out;
}