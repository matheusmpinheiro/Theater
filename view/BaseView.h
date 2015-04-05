/* 
 * File:   BaseView.h
 * Author: pc
 *
 * Created on 18 de Junho de 2014, 12:33
 */

#include <string>
#include <iostream>
using std::string;
using std::bad_alloc;

#ifndef BASEVIEW_H
#define	BASEVIEW_H

class BaseView {
protected:
    string header;
    string *menu;
    string menuTitle;
    int menuOpts;

    void printElem(char elem, int times) const;
    int lerIntMaiorQue(int base, const string& msg, const string& err);
    int lerIntEntre(int base, int fim, const string& msg, const string& err);

public:
    BaseView();
    BaseView(const string& header);
    virtual ~BaseView();
    virtual void show();
    void setHeader(const string& header);
    void setMenu(const string menu[], int numOpts, const string& menuTitle);
    void printHeaderE() const;
    void printHeader(const string& title) const;
    void printMenuE() const;
    void printMenu(const string menuItems[], const int numOpts,
        const string& menuTitle) const;
    void clearScreen() const;
    int readMenuOpt(int start, int end) const;
};

#endif	/* BASEVIEW_H */

