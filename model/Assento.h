/* 
 * File:   Assento.h
 * Author: pc
 *
 * Created on 21 de Junho de 2014
 */

#include <iostream>

#ifndef ASSENTO_H
#define ASSENTO_H

class Assento {
private:
	int idAssento;
	bool disponibilidade;
	char idFileira;
public:
	Assento();
	Assento(int id, char idFileira);
	int getID() const;
	char getFileira() const;
	bool verificaDisponibilidade() const;
	bool reservarAssento();
	bool liberarAssento();
	bool operator<(const Assento& assento);
	bool operator==(const Assento& assento);
	friend std::ostream& operator<<(std::ostream& out, const Assento& assento);
};

#endif /* ASSENTO_H */