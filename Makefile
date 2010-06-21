dodgson: dodgson.o functions.o functions.h nodo.o nodo.h busqueda.o busqueda.h
	g++ -O3 -o dodgson dodgson.o functions.o nodo.o busqueda.o

nodo.o: nodo.cpp nodo.h
	g++ -O3 -c nodo.cpp


functions.o: functions.cpp functions.h
	g++ -O3 -c functions.cpp

busqueda.o : busqueda.cpp busqueda.h
	g++ -O3 -c busqueda.cpp


dodgson.o: dodgson.cpp
	g++ -O3 -c dodgson.cpp

clean: 
	rm -f dodgson.o dodgson functions.o nodo.o ida_estrella.o bfs.o
