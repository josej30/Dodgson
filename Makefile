dodgson: dodgson.o functions.o functions.h
	g++ -O2 -o dodgson dodgson.o functions.o

clean: 
	rm -f dodgson.o dodgson functions.o
