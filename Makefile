dodgson: dodgson.o functions.o pref.o
	g++ -O2 -o dodgson dodgson.o functions.o pref.o

clean: 
	rm -f dodgson.o dodgson functions.o pref.o
