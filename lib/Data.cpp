/* 
* File:   Data.cpp
*
* Created on 24 de Junho de 2014
*/

#include "Data.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;
 
/*
* Construtor que aplica a data atual do sistema
*/
Data::Data() {
	aplicaDataAtual();	
}

/*
* Construtor que recebe dia, mes e ano como parâmetros. Se houver algum item da data
* incorreto, aplica a data atual do sistema
*/
Data::Data(int d, int m, int a) {
	
	if ( (d > 0 && d <= 31) && (m > 0 && m <= 12) && (a > 0) ) {
		this->dia = d;
		this->mes = m;
		this->ano = a;
	} else {
		std::string s = "Formato de hora invalida";
		throw s;
	}
}

/*
* Aplica a data local atual ao objeto
* Referência da biblioteca ctime:
* struct tm: http://www.cplusplus.com/reference/ctime/tm/
*/
void Data::aplicaDataAtual() {
	
	time_t tempo;
	struct tm *tempoLocal;
	
	time(&tempo);
	tempoLocal = localtime(&tempo);
	
	dia = tempoLocal->tm_mday;
	mes = tempoLocal->tm_mon;
	//tm_year : anos passados desde 1900
	ano = 1900 + tempoLocal->tm_year;
}

void Data::atualizaDia(int d) {
	if ( d > 0 && d <= 31 ) 
		dia = d;
}

void Data::atualizaMes(int m) {
	
	if ( m > 0 && m <= 12 ) 
		mes = m;
}

void Data::atualizaAno(int a) {
	
	if ( a >= 0 )
		ano = a;
}

int Data::getDia() const {
	
	return dia;
}

int Data::getMes() const {
	
	return mes;
}

int Data::getAno() const {
	
	return ano;
}

bool Data::operator==(const Data& dt) {
	if (this->ano != dt.ano)
		return false;
	if (this->mes != dt.mes)
		return false;
	if (this->dia != dt.dia)
		return false;

	return true;
}

bool Data::operator!=(const Data& dt) {
	return !(*this == dt);
}

std::ostream& operator<<(std::ostream& out, const Data& dt) {
	out << dt.dia << "/" << dt.mes << "/" << dt.ano;

	return out;
}

/*std::ifstream& operator>>(std::ifstream& in, const Data*& dt) {
	in.read( reinterpret_cast< char * >( dt ), sizeof( Data ) );
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const Data*& dt) {
	out.write( reinterpret_cast< const char * >( dt ), sizeof( Data ) );
	return out;
}*/
