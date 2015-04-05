#include "Ingresso.h"
#include "../lib/Data.h"

#include <iostream>

#ifndef VENDA_H
#define VENDA_H

enum FormaPgto {CARTAO, DINHEIRO};

class Venda {
private:
	static const int MAX = 20;
	Data dtVenda;
	double valorTotal;
	int qtdIngresso;
	FormaPgto pagamento;
	Ingresso bilhetes[MAX]; //add ao diagrama
	int localizaIngresso(Ingresso& bilhete);
public:
	Venda();
	Venda(Data dt, FormaPgto forma);
	Venda(const Venda& v);
	virtual ~Venda();
	void setData(Data& dt);//alterei aqui
	Data getData();//alterei aqui
	double calcularValorTotal();
	void emitirIngresso();//É mostrar na tela?
	void addIngresso(Ingresso& bilhete);//colocar como parâmetro referencia à classe Ingresso (acresentar quantidade)
	void removeIngresso(Ingresso& bilhete);//colocar como parâmetro referencia à classe Ingresso (diminuir quantidade)
	bool operator<(const Venda& v);
	bool operator==(const Venda& v);
	friend std::ostream& operator<<(std::ostream& out, Venda& v);
};

#endif /* VENDA_H */
