/* 
 * File:   SalaDAO.h
 * Author: pc
 *
 * Created on 23 de Junho de 2014
 */

#include "Sala.h"
#include "../lib/Lista.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using std::string;


#ifndef SALADAO_H
#define SALADAO_H

class SalaDAO {
private:
	std::fstream stream;

public:
	SalaDAO();
	virtual ~SalaDAO();
	void incluir(const Sala& s);
	//void remover(const Sala& s);
	//void alterar(const Sala& s);
	void consultar(int numSala);
	//Lista<Sala>& consultar();
};

#endif /* SALADAO_H */