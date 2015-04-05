/*
* Arquivo: Lista.h
* 
* Implementação de lista em vetor estático com template
*/

/*
******************************************************************************
* INTERFACE:
* ****************************************************************************
* Lista()				: Inicializa a lista com o tamanho padrão 200;
* Lista(int )			: Inicializa com um valor estipulado;
* Lista(const Lista&)	: Construtor de cópia;
* ~Lista()				: Desaloca elementos alocados dinamicamente;
* ****************************************************************************
* elementoEm()	: Encontra um elemento na posição <pos>
* 				e o retorna ou lança exceção do tipo string.
*
* localiza()	: Tenta encontrar um elemento igual ao elemento
* 				passado como parâmetro e retorna sua posição ou -1,
*				caso contrário.
*
* tamanho()		: Retorna a quantidade de elementos na lista.
*
* vazia()		: Retorna true se a lista está vazia, false, caso contrário.
*
* insere()		: Insere um elemento do tipo sobrecarregado no template(T). 
* 				Retorna exceção do tipo string se atingiu o limite de 
*				elementos da Lista.
*
* ordena()		: Faz a ordenação da lista pelo método selection sort.
*				A cada inserção o atributo ordenado é definido false, caso
*				haja necessidade de uma busca, o método localiza, ordenará
*				a lista antes.
* remove()		: Remove o elemento passado como parâmetro, caso não o
*				encontre, retorna uma exceção do tipo string.
*
* mostra()		: Imprime os elementos da lista.			
* ****************************************************************************
*/

#include <iostream>
using std::cout;
using std::endl;

#ifndef LISTA_H
#define LISTA_H

template <class T>
class Lista {
private:
	const int MAX;
	int tam;
	T **elementos;
	bool ordenado;

public:
	Lista();
	Lista(const int& tamanho);
	Lista(const Lista& l);
	~Lista();

	T elementoEm(const int& pos) const;
	int localiza(const T& elemento);
	int tamanho() const;
	bool vazia() const;
	void insere(const T& elemento);
	void ordena();
	void remove(const T& elemento);
	void mostra();
};


/* Implementação */

/* Construtor padrão */
template <class T>
Lista<T>::Lista() : MAX(200) {
	ordenado = false;
	elementos = new T*[MAX];
	for (int i = 0; i < MAX; i++)
		elementos[i] = NULL;
	tam = 0;
}

/* Construtor, recebe o tamanho da lista. Se for maior lança exceção */
template <class T>
Lista<T>::Lista(const int& tamanho) : MAX(500) {
	ordenado = false;
	if (tamanho < MAX) {
		elementos = new T*[tamanho];
		for (int i = 0; i < tamanho; i++)
			elementos[i] = NULL;
		tam = 0;
	}
}

/* Construtor de cópia */
template <class T>
Lista<T>::Lista(const Lista& l) : MAX(l.MAX) {
	ordenado = l.ordenado;
	tam = l.tam;
	elementos = new T*[tam];
	for(int i = 0; i < tam; i++) {
		T* aux = new T(*(l.elementos[i]));
		elementos[i] = aux;
	}
}

/* 
* Destrutor: Faz delete nos elementos alocados dinamicamente e no 
* ponteiro para o vetor 
*/
template <class T>
Lista<T>::~Lista() {
	for (int i = 0; i < tam; i++) {
		if (elementos[i] != NULL) {
			delete elementos[i];
			elementos[i] = NULL;
		}
	}
	
	delete [] elementos;
	elementos = NULL;
}

/* Retorna o elemento na posição <pos> */
template <class T>
T Lista<T>::elementoEm(const int& pos) const {
	if (pos < tam)
		return *elementos[pos];
	else
		throw "Bad index";
}

/* 
* Localiza: Se o vetor estiver desordenado, ordena antes e procura
* o elemento em <elemento>. Retorna -1 se não encontrar 
*/
template <class T>
int Lista<T>::localiza(const T& elemento) {
	
	if (ordenado == false) {
		ordena();
		// Se não tiver elementos, isto faz sentido?!
		ordenado = true;
	}

	//Busca binária
   	int e, m, d;
   	e = 0; 
   	d = tam-1;
   	while (e <= d) {
   		m = (e + d)/2; 
      	if (*elementos[m] == elemento) 
      		return m;
      	
      	if (*elementos[m] < elemento) 
      		e = m + 1;
      	else 
      		d = m - 1;
   	}

   	return -1;
}

/* Retorna o tamanho da lista */
template <class T>
int Lista<T>::tamanho() const {
	return tam;
}

/* Verifica se a lista está vazia, retorna true ou false */
template <class T>
bool Lista<T>::vazia() const {
	return (tam == 0);
}

/* 
* Insere <elemento> se o tamanho máximo não foi atingido,
* lança excecão caso contrário
*/
template <class T>
void Lista<T>::insere(const T& elemento) {
	T* aux = new T(elemento);

	if (tam < MAX)
		elementos[tam++] = aux;
	else
		throw "Nao foi possivel adicionar. O limite de itens foi atingido!";

}

/* Ordena a lista utilizando o algoritmo selection sort */
template <class T>
void Lista<T>::ordena() {

	if (vazia()) return;

	int min;
	
	for (int i = 0; i < tam - 1; i++) {
		min = i;
		
		for (int j = i + 1; j < tam; j++) {
			if ( *elementos[j] < *elementos[min] ) {
				min = j;
			}
		}
		
		T* aux = elementos[min];
		elementos[min] = elementos[i];
		elementos[i] = aux;
	}

}

/* 
* Remove o elemento <elemento> se ele estiver na lista, lança 
* exceção caso contrário.
*/
template <class T>
void Lista<T>::remove(const T& elemento) {
	int pos;
	if ( (pos = localiza(elemento)) >= 0) {
		delete elementos[pos];
		elementos[pos] = NULL;

		// Compacta vetor
		for (int i = pos; i < tam-1; i++) {
			elementos[i] = elementos[i+1];
		}

		delete elementos[tam];
		elementos[tam] = NULL;

		tam--;
	} else {
		throw "Nao foi possivel remover. Elemento nao encontrado.";
	}
}

/* Imprime os elementos da lista */
template <class T>
void Lista<T>::mostra() {	
	for(int i = 0; i < tam; i++) {
		cout << *elementos[i] << " ";
	}
}

/* Fim Implementação */

#endif /* LISTA_H */
