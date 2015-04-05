/* 
 * File:   SalaDAO.h
 * Author: pc
 *
 * Created on 23 de Junho de 2014
 */

#include "Sessao.h"
#include "../lib/Lista.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using std::string;


#ifndef SESSAODAO_H
#define SESSAODAO_H

class SessaoDAO {
private:
	std::fstream stream;

public:
	SessaoDAO();
	virtual ~SessaoDAO();
	void incluir(const Lista<Sessao>* s);
	//void remover(const Sala& s);
	//void alterar(const Sala& s);
	Sessao consultar(int numSala);
	//Lista<Sala>& consultar();
};

#endif /* SESSAODAO_H */