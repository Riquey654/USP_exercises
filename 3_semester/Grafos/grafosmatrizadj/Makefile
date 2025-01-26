all: item.o graph.o main.o
	gcc item.o graph.o main.o -o graph -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

graph.o:
	gcc -c graph.c -o graph.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm *.o graph

run:
	./graph