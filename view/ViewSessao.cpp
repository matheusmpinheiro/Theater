#include "ViewSessao.h"
#include "../lib/Hora.h"


#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
using std::string;

const string ViewSessao :: menuItems[5] = {"Incluir", "Consultar", "Alterar", "Remover", "Voltar"};
enum Operacao {INCLUIR = 1, CONSULTAR, ALTERAR, REMOVER, VOLTAR};

ViewSessao::ViewSessao(): BaseView("BEM VINDO AO GERENCIAMENTO DE SESSOES") {
}

ViewSessao::~ViewSessao() {
}

void ViewSessao::show() {

 	printHeaderE();
 	setHeader("CADASTRO DE SESSOES");
 	setMenu(menuItems, 5, "OPERACOES");
 	op = readMenuOpt(1, 5);

	while(op!=5) {
	 	switch(op) {
			case 1:
				incluir();
				break;
			case 2:
				consultar();
				break;
			case 3:
				alterar();
				break;
			case 4:
				remover();
				break;
		}
		op = readMenuOpt(1, 5);
	}
}

void ViewSessao::setSessoes(Lista<Sessao>* ls) {
	this->vetSessao = ls;
}

Lista<Sessao>* ViewSessao::getSessoes() {
	return this->vetSessao;
}

void ViewSessao::incluir() {
	
 	int status, qtdHoras;
 	string filme;
 	int hora, min;
 	Sessao s;
 	Hora hr[5];//quantidade máxima de sessoes para um filme

 	filme = lerFilme();
 	status = lerStatus();

 	s.setStatus(status);
 	s.setFilme(filme);

 	qtdHoras = lerIntEntre(1, 5, "Quantos horários deseja para a sessão(Max. 5):",
 		"Informe apenas quantidades entre 1 e 5");

	for(int i = 0; i < qtdHoras; i++) {
 		hora = lerIntEntre(0, 23, "Informe a hora da sessão: ", "Apenas entre 0 e 23");
 		min = lerIntEntre(0, 59, "Informe os minutos do horário da sessão: ", "Apenas entre 0 e 59");
 		hr[i].setHorario(hora, min);
 	}

 	s.setHorario(qtdHoras, hr);

 	try {
		vetSessao->insere(s);
		cout << "Sessão inserida com sucesso." << endl;
		cout << "___________________________________" << endl;
		cout << s << endl;;
	} catch(const string& s) {
		cerr << s << endl;
	}
}

void ViewSessao::consultar() {
 	string filme;
 	Sessao s;
 	int status, pos;

 	filme = lerFilme();
	status = lerStatus();

	s.setFilme(filme);
	s.setStatus(status);

	//retorna -1 se não encontra
	pos = vetSessao->localiza(s);

	if(pos != -1){
		cout << "As sessoes para este filme sao: " << endl;
		cout << "___________________________________" << endl;
		cout << vetSessao->elementoEm(pos) << endl;
	} else {
		cout << "Sessão para este filme não foi encontrada!" << endl;
	}

 }

void ViewSessao::alterar(){
 	string filme;
 	int status;
 	Sessao s;

 	filme = lerFilme();
	status = lerStatus();

	s.setFilme(filme);
	s.setStatus(status);

	int pos = vetSessao->localiza(s);

	if(pos != -1){
        s = vetSessao->elementoEm(pos);
        try {
            vetSessao->remove(s);
            cout << "Alteração da sessão do filme: " << filme << endl;
            incluir();
        } catch(const string& s) {
            cerr << "Desculpe! Não foi possível realizar a operação" << endl;
        }
    } else {
        cout << "A sessão do filme " << filme << " não foi encontrada!" << endl;
    }
}

void ViewSessao::remover(){
	Sessao s;
	string filme;
	int pos, status;

 	filme = lerFilme();
 	status = lerStatus();

	s.setFilme(filme);
	s.setStatus(status);

	pos = vetSessao->localiza(s);

	if (pos != -1) {
		s = vetSessao->elementoEm(pos);
		try {
			vetSessao->remove(s);
			cout << "Sessão removida com sucesso." << endl;
			cout << "___________________________________" << endl;
			cout << s << endl;
		} catch(const string& s) {
			cerr << s << endl;
		}
	} else {
		cout << "A sessão informada não foi encontrada" << endl;
	}
}

int ViewSessao::lerStatus() {

	int encerrada = lerIntEntre(0, 1, "A sessao esta encerrada? (0 = NÃO 1 = SIM): ",
		"Por favor informe somente 0 ou 1!");

	return encerrada;
}

string ViewSessao::lerFilme() {
	string filme;

	do {
		cout << "Informe o nome do filme:" << endl;
 		getline(cin, filme);
 		if (filme.compare("") == 0)
 			cout << "O nome do filme nao pode estar vazio" << endl;
	} while (filme.compare("") == 0);

	return filme;
}

