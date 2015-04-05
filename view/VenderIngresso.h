#include <string>
#include "BaseView.h"
#include <iostream>
#include "../model/Venda.h"
using std::string;
using std::bad_alloc;

#ifndef VENDERINGRESSO_H
#define	VENDERINGRESSO_H

class VenderIngresso : public BaseView{
	private:
		static const string menuItens[5];
        int opt;
        Ingresso ing[5];
	public:
		VenderIngresso();
		void show();
		void subMenus(int opt);
};
#endif	/* VENDERINGRESSO_H */
