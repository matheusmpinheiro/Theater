/* 
 * File:   Hora.cpp
 * Author: 
 * 
 * Created on 20 de Junho de 2014
 */

#include "Hora.h"

#include <iostream>
#include <string>
using namespace std;

Hora::Hora() {
	this->hora = 0;
	this->min = 0;
}

Hora::Hora(int h, int m) {
	try {
		setHorario(h, m);
	} catch(const string& s) {
		throw;
	}
}

void Hora::setHorario(int h, int m) {
	if ((h >= 0 && h < 24) && (m >= 0 && m < 60)) {
		this->hora = h;
		this->min = m;
	} else {
		throw "Hora com formato incorreto.";
	}
}

int Hora::getHora() const {
	return hora;
}

int Hora::getMin() const {
	return min;
}

bool Hora::operator==(const Hora& hr) {
	return (this->hora == hr.hora && this->min == hr.min);
}

bool Hora::operator<(const Hora& hr) {
	if (this->hora == hr.hora) {
		return (this->min < hr.min);
	} else {
		if (this->hora < hr.hora)
			return true;
	}
	
	return false;
}

std::ostream& operator<<(std::ostream& out, const Hora& hr) {
	out << hr.hora << ":" << hr.min;
	return out;
}

/*ifstream& operator>>(ifstream& in, const Hora& hr) {
	in.read( reinterpret_cast< char * >( &hr ), sizeof( Hora ) );
	return in;
}

ofstream& operator<<(ofstream& out, const Hora& hr) {
	out.write( reinterpret_cast< const char * >( &hr ), sizeof( Hora ) );
	return out;
}*/
