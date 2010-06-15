dodgson: dodgson.o functions.o functions.h nodo.o nodo.h
	g++ -O3 -o dodgson dodgson.o functions.o nodo.o

nodo.o: nodo.cpp nodo.h
	g++ -O3 -c nodo.cpp

clean: 
	rm -f dodgson.o dodgson functions.o nodo.o
