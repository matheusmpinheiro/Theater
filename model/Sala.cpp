/* 
* File:   Sala.cpp
* Author: pc
* 
* Created on 18 de Junho de 2014, 20:54
*/

#include "Sala.h"

#include <iostream>
#include <iomanip>
using namespace std;

/* 
* Construtor padrão: Define numSala como -1
* Indicativo de sala vazia no registro salvo em arquivo
*/
Sala::Sala() : fileiras(1) {
	this->numSala = -1;
	this->capacidade = 0;
	this->qtdFileira = 0;
	this->alocada = false;
	this->situacao = REMOVIDA;
}

/* Construtor: Aloca dinamicamente a lista de fileiras */
Sala::Sala(int num, Situacao situacao, int capacidade, int qtdFileiras) 
	: fileiras(qtdFileiras) {
	this->numSala = num;
	this->capacidade = capacidade;
	this->qtdFileira = qtdFileiras;
	this->situacao = situacao;
	alocada = false;
}

/* Construtor de cópia: Necessário para copiar fileiras */
Sala::Sala(const Sala& orig) : fileiras(orig.fileiras) {
	this->numSala = orig.numSala;
	this->capacidade = orig.capacidade;
	this->qtdFileira = orig.qtdFileira;
	this->situacao = orig.situacao;
	this->alocada = orig.alocada;
}

/* Retorna se a sala está ou não alocada para uma sessão */
bool Sala::getAlocacao() const {
	return alocada;
} 

/* Retorna a quantidade de assentos da sala */
int Sala::getCapacidade() const {
    return capacidade;
}

/* Retorna o número da sala */
int Sala::getNumSala() const {
    return numSala;
}

/* Retorna a situação da sala */
Situacao Sala::getSituacao() const {
    return situacao;
}

/* 
* Define que a sala está alocada para uma sessão 
* Retorna true se a sala estiver com situação disponível
* e não estiver alocada.
*/
bool Sala::alocarSala() {
	
	if (alocada == false && situacao == DISPONIVEL) {
		alocada = true;
	}
	
	return alocada;
}

/* Desaloca uma sala alocada, retorna false se já estiver alocada */
bool Sala::desalocarSala() {

	if (alocada == true) {
		alocada = false;
		return true;
	}

	return false;
}

/* Define o número de identificação da sala */
void Sala::setNumSala(int num) {
	this->numSala = num;
}

/* Define a quantidade de assentos da sala */
void Sala::setCapacidade(int capacidade) {
    this->capacidade = capacidade;
}

/* Define a situação da sala de acordo com enum Situação */
void Sala::setSituacao(Situacao situacao) {
    this->situacao = situacao;
}

void Sala::adicionarFileira(char idFileira, int qtdAssentos) {
	Fileira f(idFileira, qtdAssentos);

	// Lista de fileiras
	try {
		fileiras.insere(f);
	} catch (const string& e) {
		cerr << e << endl;
	}
}

void Sala::removerFileira(char idFileira) {
	Fileira f(idFileira);
	
	// Fileira é comparada por id! No remove, será
	// procurado o objeto com este id para ser excluído
	try {
		fileiras.remove(f);
	} catch (const string& e) {
		cerr << e << endl;
	}
}
   
bool Sala::reservarAssento(int idAssento) {
	return false;
}

bool Sala::liberarAssento(int idAssento) {
	return false;
}

/* Sobrecarga do operador == */
bool Sala::operator==(const Sala& s) {

	return (this->numSala == s.numSala);
}

/* Sobrecarga do operador < */
bool Sala::operator<(const Sala& s) {

	return (this->numSala < s.numSala);

}

/* Sobrecarga do operador << */
std::ostream& operator<<(std::ostream& out, const Sala& s) {

	out << std::setw(15) << "Numero Sala: "  << s.numSala << endl;
	out << std::setw(15) << "Capacidade: " << s.capacidade << endl;
	out << std::setw(15) << "Fileiras: " << s.qtdFileira << endl;

	out << std::setw(15) << "Situacao: ";
	
	switch(s.situacao) {
		case REMOVIDA:
			out << std::setw(15) << "Removida";
			break;
		case DISPONIVEL:
			out << std::setw(15) << "Disponivel";
			break;
		case MANUEQUIPAMENTO:
			out << std::setw(15) << "Equipamentos em manutencao";
			break;
		case REFORMA:
			out << std::setw(15) << "Reforma";
			break;
		case MANUGERAL:
			out << std::setw(15) << "Manutencao";
			break;
	}

	out << endl;

	out << std::setw(15) << "Alocacao: ";
	if (s.alocada)
		out << std::setw(15) << "Alocada";
	else
		out << std::setw(15) << "Livre";

	return out;
}

