all: item.o pilha.o labirinto.o
	gcc item.o pilha.o labirinto.o -o labirinto.exe
item.o: item.c
	gcc -c item.c -o item.o
pilha.o: pilha.c
	gcc -c pilha.c -o pilha.o
labirinto.o : labirinto.c 
	gcc -c labirinto.c -o labirinto.o
run:
	./labirinto.exe