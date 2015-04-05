
#ifndef HORA_H
#define HORA_H

class horario{
private:
	int hora;
	int minutos;

public:
	int atualizaHora(int h= 01);
	int atualizaMin(int m= 01);
};

#endif /* HORA_H */