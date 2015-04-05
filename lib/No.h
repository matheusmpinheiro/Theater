/*
 * no.h
 *
 *  Created on: 10/11/2008
 *      Author: katti
 */

#ifndef NO_H
#define NO_H

/* Classe Nó */
template <class T>
class No {
private:
	T info;
	No<T>* prox;
public:
	No(const T& informacao);
	T getInfo() const;
	void setProx(No<T> *p);
	No<T>* getProx() const;
};

template <class T>
No<T>::No(const T& informacao) : info(informacao), prox(NULL) {}

template <class T>
T No<T>::getInfo() const {
	return info;
}

template <class T>
void No<T>::setProx(No<T> *p) {
	prox = p;
}

template <class T>
No<T>* No<T>::getProx() const {
	return prox;
}

/* Fim da implementação da classe Nó */

#endif /* NO_H */
