/* 
 * File:   Sala.h
 * Author: pc
 *
 * Created on 18 de Junho de 2014, 20:54
 */

#include "../lib/Lista.h"
#include "Fileira.h"

#ifndef SALA_H
#define	SALA_H

enum Situacao {REMOVIDA, DISPONIVEL, MANUEQUIPAMENTO, REFORMA, MANUGERAL};

class Sala {
    private:
    int numSala;
    int capacidade;
    int qtdFileira;
    bool alocada;
    Situacao situacao;
    Lista<Fileira> fileiras;
public:
    Sala();
    Sala(int num, Situacao situacao, int capacidade, int qtdFileiras);
    Sala(const Sala& orig);
    virtual ~Sala() {};
    
    bool getAlocacao() const;
    int getNumSala() const;
    int getCapacidade() const;
    Situacao getSituacao() const;
    bool alocarSala();
    bool desalocarSala();
    void setNumSala(int num);
    void setCapacidade(int capacidade);
    void setSituacao(Situacao situacao);
    void adicionarFileira(char idFileira, int qtdAssentos);
    void removerFileira(char idFileira);
    bool reservarAssento(int idAssento);
    bool liberarAssento(int idAssento);
    bool operator==(const Sala& s);
    bool operator<(const Sala& s);
    friend std::ostream& operator<<(std::ostream& out, const Sala& s);
};

#endif	/* SALA_H */

