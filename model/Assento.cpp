/* 
 * File:   Assento.cpp
 * Author: pc
 *
 * Created on 21 de Junho de 2014
 */

#include "Assento.h"

#include <iostream>
using namespace std;

/* Construtor padrão */
Assento::Assento() {
	this->idAssento = -1;
	this->idFileira = 0;
	this->disponibilidade = false;
}

/* Construtor para definir id e idFileira */
Assento::Assento(int id, char idFileira) {
	idAssento = id;
	this->idFileira = idFileira;
	disponibilidade = true;
}

/* Retorna o id do assento */
int Assento::getID() const {
	return idAssento;
}

/* Retorna o id da Fileira a qual pertence */
char Assento::getFileira() const {
	return idFileira;
}

/* Retorna o estado de disponibilidade do assento */
bool Assento::verificaDisponibilidade() const {
	return disponibilidade;
}

/* Altera a disponibilidade do assento caso já não esteja reservado */
bool Assento::reservarAssento() {
	if (disponibilidade) {
		disponibilidade = false;
		return true;
	}
	
	return false;
}

/* Libera um assento que não esteja disponível, retorna false caso contrário */
bool Assento::liberarAssento() {
	if (disponibilidade == false) {
		disponibilidade = true;
		return true;
	}

	return false;
}

/* Sobrecarga do operador < para uso no algoritmo de ordenação de LISTA_H */
bool Assento::operator<(const Assento& assento) {
	return (this->idAssento < assento.idAssento);
}

/* Sobrecarga do operador == para uso no algoritmo de ordenação de LISTA_H */
bool Assento::operator==(const Assento& assento) {

	if (this->idAssento != assento.idAssento)
		return false;
	
	if (this->idFileira != assento.idFileira)
		return false;

	/*
	if (this->disponibilidade != assento.disponibilidade)
		return false;*/

	return true;
}

/* Sobrecarga do operador stream extractor << */
std::ostream& operator<<(std::ostream& out, const Assento& assento) {
	out << "ID: " << assento.idAssento;
	out << "\tFileira: " << assento.idFileira;
	out << "\tDisponibilidade: " << assento.disponibilidade << endl;

	return out;
}
