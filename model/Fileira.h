/* 
 * File:   Fileira.h
 * Author: pc
 *
 * Created on 21 de Junho de 2014
 */

#include "Assento.h"
#include "../lib/Lista.h"

#include <iostream>

#ifndef FILEIRA_H
#define FILEIRA_H

class Fileira {
private:
	char idFileira;
	int qtdAssentos;
	bool assentoDisponivel; // Para atualizar cada vez que um assento for modificado
	Lista<Assento> assentos;

public:
	Fileira();
	Fileira(char id);
	Fileira(char id, int qtdAssentos);
	Fileira(const Fileira& fila);
	virtual ~Fileira() {};
	bool verificaDisponibilidade() const;
	void adicionarAssento(int idAssento);
	void removerAssento(int idAssento);
	bool operator==(const Fileira& fila);
	bool operator<(const Fileira& fila);
	friend std::ostream& operator<<(std::ostream& out, const Fileira& fila);
};

#endif /* FILEIRA_H */