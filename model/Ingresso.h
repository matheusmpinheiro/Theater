/* 
* File:   Ingresso.h
* Author: pc
*
* Created on 24 de Junho de 2014
*/

#include "../lib/Data.h"
#include <iostream>

#ifndef INGRESSO_H
#define INGRESSO_H

enum Tipo {INTEIRO, MEIA};

class Ingresso {
private:
	Data dtIngresso;
	double valor;
	Tipo tipo;
	int idAssento;

public:
	Ingresso();
	Data getDtIngresso() const;
	double getValor() const;
	Tipo getTipo() const;
	void setDtIngresso(Data& data);
	void setValor(double valor);
	void setTipo(Tipo tipoIngresso);
	//bool operator==(const Ingresso& i);
	//bool operator<(const Ingresso& i);
	friend std::ostream& operator<<(std::ostream& out, const Ingresso& t); 
};

#endif /* INGRESSO_H */
