/* 
 * File:   SalaDAO.cpp
 * Author: pc
 *
 * Created on 23 de Junho de 2014
 */

#include "SalaDAO.h"
#include "Sala.h"
#include "../lib/Lista.h"

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

SalaDAO::SalaDAO() {
	//Parâmetros: (nome do arquivo, modo)
	//O modo é um enum de bits, então ligamos várias opções fazendo um |, OR bit-a-bit
	stream.open("Dados/Salas.dat", ios::in | ios::out | ios::app | ios::binary);
	if (stream == NULL) {
		cerr << "impossivel abrir arquivo";
	}
}

SalaDAO::~SalaDAO() {
	stream.close();
}

void SalaDAO::incluir(const Sala& s) {
	if (stream.is_open())
		stream.write( reinterpret_cast< const char * >( &s ), sizeof( Sala ) );
	else
		cerr << "O arquivo nao esta aberto. Impossivel gravar";
}

void SalaDAO::consultar(int numSala) {
	Sala s;
	ifstream in("Dados/Salas.dat", ios::in | ios::binary);
	if (in.is_open()) {
		cerr << "Entra no open";
		in.read( reinterpret_cast< char * >( &s ), sizeof( Sala ) );
	} else
		cerr << "O arquivo nao esta aberto. Impossivel gravar";

	cout << s.getNumSala();
	cout << s.getCapacidade();
	cout << s.getAlocacao();

	in.close();

	//return s;
}