#include "BaseView.h"

#include <iostream>
#include <limits>
#include <string>
using namespace std;

#include <cstdlib>
#include <cstdio>

BaseView::BaseView() {
    header = "SEM TITULO DEFINIDO";
    menuOpts = 0;
    menuTitle = "Sem titulo de menu definido";
    menu = NULL;
}

BaseView::BaseView(const string& header) :
    header(header) {
        menuOpts = 0;
        menu = NULL;
}

BaseView::~BaseView() {
    if (menu != NULL) {
        delete [] menu;
    }
}

//stackoverflow.com/questions/14861018/center-text-in-fixed-width-field-with-stream-manipulators-in-c
/*
 Métodos públicos
 */
void BaseView::show() {
    clearScreen();
}

/*void BaseView::printHeader(const string& title) const {
    int lineSize = title.length();
    
    cout << endl;
    
    printElem('#', lineSize + 4); // dois espaços cada lado
    
    cout << endl << "# ";
    cout << title << " #" ;
    cout << endl;
    
    printElem('#', lineSize + 4); // dois espaços cada lado
    
    cout << endl;
}*/

void BaseView::setHeader(const string& header) {
    this->header = header;
}

void BaseView::printHeaderE() const{
    printHeader(this->header);
}

void BaseView::printHeader(const string& title) const {
    int lineSize = title.length();
    
    cout << endl;
    
    printElem(205, lineSize + 4); // dois espaços cada lado
    
    cout << endl << (char) 186 << " " << title << " " << (char) 186 << endl;
    
    printElem(205, lineSize + 4); // dois espaços cada lado
    
    cout << endl;
}

void BaseView::setMenu(const string menu[], int numOpts, const string& menuTitle) {
    
    //Exclui o menu antigo, se houver
    if (this->menu != NULL)
        delete [] menu;

    try {
        this->menu = new string[numOpts];
        this->menuOpts = numOpts;
        this->menuTitle = menuTitle;

        for(int i = 0; i < menuOpts; i++) {
            this->menu[i] = menu[i];
        }

    } catch(bad_alloc &ba) {
        cerr << "Impossivel alocar o menu " << menuTitle << " com esta quantidade de opcoes";
        cerr << endl;
        exit(1);
    }

}

void BaseView::printMenuE() const {
    printMenu(this->menu, menuOpts, menuTitle);
}

void BaseView::printMenu(const string menuItems[], const int numOpts, 
        const string& menuTitle) const {

    //Deixa o menu com o mesmo tamanho da moldura do Cabeçalho(header)
    int menuSize = header.length() + 4;
     
    printElem('-', menuSize);
    cout << endl << menuTitle << endl;
    printElem('-', menuSize);
    cout << endl;
    
    for(int i = 0; i < numOpts; i++) {
        cout << i+1 << ". " << menuItems[i] << endl; 
    }
    
    printElem('-', menuSize);
    
    cout << endl;
}

void BaseView::clearScreen() const {
    #ifdef __linux__
        // Escape sequence para limpar a tela 
        printf("\33[H\33[2J");
    #else
        system("cls");
    #endif
}

int BaseView::readMenuOpt(int start, int end) const {
    int opt = 0;

    // Imprime titulo e menu da view, configurados por setMenu()
    // e setHeader()
    printHeaderE();
    printMenuE();
    //Exibe um prompt para entrada dos dados
    cout << "> ";

    do {
        cin >> opt;
        if (cin.fail() || opt < start || opt > end) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            clearScreen();
            printHeaderE();
            printMenuE();
            cout << "Por favor digite uma opcao entre " << start << " e " << end; //end mesmo
            cout << endl;
            cout << "> ";
            continue;
        }
    } while(opt < start || opt > end);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return opt;
}

void BaseView::printElem(char elem, int times) const {
    for(int i = 0; i < times; i++)
        cout << elem;
}

int BaseView::lerIntMaiorQue(const int base, const string& msg, const string& err) {
    int num;

    do {
        cout << msg << endl;
        if (cin >> num) {
            if (num < base)
                cout << err << endl;
        } else {
            cerr << "Informe apenas números" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (num < base);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return num;
}

int BaseView::lerIntEntre(int base, int fim, const string& msg, const string& err) {
    int num;

    do {
        cout << msg << endl;
        cin >> num;
        if (! cin.fail()) {
            if ( num < base || num > fim)
                cout << err << endl;
        } else {
            cerr << "Informe apenas números" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue ;
        }
    } while (num < base || num > fim);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return num;
}
