/* 
 * File:   Cabeca.h
 *
 * Created on 22 de Junho de 2014
 */

#include "No.h"

#ifndef CABECA_H
#define CABECA_H

/* Nó Cabeça */
template <class T>
class Cabeca {
private:
	int info;
	No<T>* prox;
public:
 	Cabeca();
 	int getInfo() const;
 	void incrementa();
 	void decrementa();
 	void setProx(No<T> *p);
	No<T>* getProx() const;
};

/* Inicializa para 0 a quantidade de nós na lista */
template <class T>
Cabeca<T>::Cabeca() : info(0), prox(NULL) {}

template <class T>
int Cabeca<T>::getInfo() const {
	return info;
}

/* Incrementa a quantidade de nós na lista */
template <class T>
void Cabeca<T>::incrementa() {
	info++;
}

/* Decrementa a quantidade de nós na lista */
template <class T>
void Cabeca<T>::decrementa() {
	if (info > 0)
		info--;
}

template <class T>
void Cabeca<T>::setProx(No<T> *p) {
	prox = p;
}

template <class T>
No<T>* Cabeca<T>::getProx() const {
	return prox;
}

#endif /* CABECA_H */

/* Fim da implementação do Nó Cabeça */
