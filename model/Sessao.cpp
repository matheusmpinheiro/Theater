/* 
 * File:	Sessao.cpp
 *
 * Created on 21 de Junho de 2014
 */

#include "Sessao.h"

#include <iostream>
#include <string>
using namespace std;

Sessao::Sessao() {
	hrs = new Hora[MAX];
	qtdHoras = 0;
	encerrada = 0;
	numVendido = 0;
	filme = "";
}

/*Sessao::Sessao(string nomeFilme, int status) {
	this->encerrada = status;
	filme = nomeFilme;
	hrs = new Hora[MAX];
	qtdHoras = 0;
	numVendido = 0;
}*/

Sessao::Sessao(const Sessao& obj) { 
	qtdHoras = obj.qtdHoras;
	encerrada = obj.encerrada;
	numVendido = obj.numVendido;
	filme = obj.filme;

	hrs = new Hora[qtdHoras];
	for(int i = 0; i < obj.qtdHoras; i++){
		hrs[i] = obj.hrs[i];
	}
}

Sessao::~Sessao() {
	delete [] hrs;
}

void Sessao::setStatus(int status){
	encerrada = status;
}

int Sessao::getStatus(){
	return encerrada;
}

Hora* Sessao::getHorario(){
	return hrs;
}

void Sessao::setHorario(int qtd, Hora* horarios) {//recebe vetor de horário

	qtdHoras = qtd;

	hrs = new Hora[qtdHoras];
	for (int i = 0; i < qtd; i++)
		hrs[i] = horarios[i];
}

bool Sessao::getDisponivel() {
	return (numVendido < s->getCapacidade());
}

void Sessao::setNumVendido(int numVendidos) {
	if ((this->numVendido + numVendidos) <= s->getCapacidade()) {
		this->numVendido += numVendidos;
	} else {
		throw "Esta quantidade de ingressos excede a capacidade da sessão";
	}
}

void Sessao::setFilme(string nomeFilme) {
	filme = nomeFilme;
}

string Sessao::getFilme() {
	return filme;
}

int Sessao::quantidadeIngressos() {
	return s->getCapacidade();
}

Sessao& Sessao::operator=(const Sessao& obj) {
    if (! (*this == obj)) {
    	qtdHoras = obj.qtdHoras;
    	encerrada = obj.encerrada;
    	numVendido = obj.numVendido;
    	filme = obj.filme;
    	delete [] hrs;
        for (int i = 0; i < qtdHoras; i++)
        	hrs[i] = obj.hrs[i];
    }

    return *this;
}

bool Sessao::operator==(const Sessao& obj){
	return ((this->encerrada == obj.encerrada) && (this->filme.compare(obj.filme) == 0));
}

bool Sessao::operator<(const Sessao& obj){
	return (this->filme == obj.filme && this->encerrada < obj.encerrada);
}

std::ostream& operator<<(std::ostream& out, const Sessao& obj){

	out << left << "Filme: " << obj.filme << endl;
	if (obj.encerrada == 1) {
		out << "Status: Encerrada." << endl;
	} else {
		out << "Horários:" << endl;
		for(int i = 0; i < obj.qtdHoras; i++) {
			out << obj.hrs[i] << endl;
		}
	}

	out << "Ingressos vendidos: " << obj.numVendido;

	return out;
}
