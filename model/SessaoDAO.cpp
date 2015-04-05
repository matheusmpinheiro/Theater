/* 
 * File:   SessaoDAO.cpp
 * Author: pc
 *
 * Created on 23 de Junho de 2014
 */

#include "SessaoDAO.h"
#include "Sessao.h"
#include "../lib/Lista.h"

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

SessaoDAO::SessaoDAO() {
	//Parâmetros: (nome do arquivo, modo)
	//O modo é um enum de bits, então ligamos várias opções fazendo um |, OR bit-a-bit
	stream.open("Dados/Sessoes.dat", ios::in | ios::out | ios::app | ios::binary);
	if (stream == NULL) {
		cerr << "impossivel abrir arquivo";
	}
}

SessaoDAO::~SessaoDAO() {
	stream.close();
}

void SessaoDAO::incluir(const Lista<Sessao>* s) {
	if (stream.is_open())
		for (int i = 0; i < s->tamanho(); i++) {
			Sessao salva(s->elementoEm(i));
			cout << "Salvando:" << endl;
			cout << salva << endl;
			stream.write( reinterpret_cast< const char * >( &salva ), sizeof( Sessao ) );
		}
	else
		cerr << "O arquivo nao esta aberto. Impossivel gravar";
}

Sessao SessaoDAO::consultar(int numSessao) {
	Sessao s;
	ifstream in("Dados/Sessoes.dat", ios::in | ios::binary);
	if (in.is_open()) {
		cerr << "Entra no open";
		in.read( reinterpret_cast< char * >( &s ), sizeof( Sessao ) );
	} else
		cerr << "O arquivo nao esta aberto. Impossivel gravar";
	in.close();

	cout << s << endl;

	return s;
}