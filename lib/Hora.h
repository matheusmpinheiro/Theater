/* 
 * File:   Hora.cpp
 * Author: 
 * 
 * Created on 20 de Junho de 2014
 */

#ifndef HORA_H
#define HORA_H

#include <iostream>

class Hora {
private:
	int hora;
	int min;

public:
	Hora();
	Hora(int h, int m);
	void setHorario(int h, int m);
	int getHora() const;
	int getMin() const;
	bool operator==(const Hora& hr);
	bool operator<(const Hora& hr);
	friend std::ostream& operator<<(std::ostream& out, const Hora& hr);
	//friend ifstream& operator>>(ifstream& in, const Hora& hr);
	//friend ofstream& operator<<(ofstream& out, const Hora& hr);
};

#endif /* HORA_H */