parametrosCompilacao=-Wall #-Wshadow
nomePrograma=20210575-20211775

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o
	gcc -o $(nomePrograma) main.o ordenacao.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
