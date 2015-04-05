#(http://mrbook.org/tutorials/make/)
CC=g++
CFLAGS=-c -Wall
LDFLAGS=
GERAL=main.cpp view/BaseView.cpp lib/Data.cpp lib/Hora.cpp
SALA=model/Assento.cpp model/Fileira.cpp model/Sala.cpp model/SalaDAO.cpp view/viewSala.cpp control/GerenciarSala.cpp
SESSAO=model/Sessao.cpp model/SessaoDAO.cpp view/ViewSessao.cpp control/GerenciarSessao.cpp
VENDA=model/Ingresso.cpp model/Venda.cpp view/ViewVenda.cpp
SOURCES=$(GERAL) $(SALA) $(SESSAO) $(VENDA)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=projeto.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXECUTABLE); rm -r model/*.o control/*.o view/*.o lib/*.o