/* 
 * File:	Sessao.h
 *
 * Created on 21 de Junho de 2014
 */

#include "../lib/Hora.h"
#include "Sala.h"

#include <iostream>
using std::string;

#ifndef SESSAO_H
#define SESSAO_H

class Sessao {
private:
	static const int MAX = 5;
	Hora *hrs;
	int encerrada;
	int numVendido;
	string filme;
	int qtdHoras;
	Sala *s;

public:
	Sessao();
	//Sessao(nomeFilme, int status);
	Sessao(const Sessao& obj);
	~Sessao();
	void setStatus(int status);
	int getStatus();
	Hora* getHorario();
	void setHorario(int qtd, Hora* horarios);
	bool getDisponivel();
	void setNumVendido(int numVend);
	string getFilme();
	void setFilme(string nomeFilme);
	int quantidadeIngressos();
	Sessao& operator=(const Sessao& obj);
	bool operator==(const Sessao& obj);
    bool operator<(const Sessao& obj);
    friend std::ostream& operator<<(std::ostream& out, const Sessao& obj);
};

#endif /* SESSAO_H */