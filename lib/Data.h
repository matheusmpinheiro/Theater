/* 
* File:   Data.h
* Author: 
*
* Created on 24 de Junho de 2014
*/

#include <iostream>
#include <fstream>

#ifndef DATA_H
#define DATA_H 

class Data {
private:
	int dia;
	int mes;
	int ano;
	
	void aplicaDataAtual();
      
public:
	Data();
	Data(int d, int m, int a);
		
	void atualizaDia(int d);
	void atualizaMes(int m);
	void atualizaAno(int a);
	int getDia() const;
	int getAno() const;
	int getMes() const;
	bool operator==(const Data& dt);
	bool operator!=(const Data& dt);
	friend std::ostream& operator<<(std::ostream& out, const Data& dt);
	//friend std::ifstream& operator>>(std::ifstream& in, const Data*& dt);
	//friend std::ofstream& operator<<(std::ofstream& out, const Data*& dt);
};

#endif /* DATA_H */
