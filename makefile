CFLAGS = -g -Wall

main : main.o PileB.o P4.o PileDyn.o IA.o
	gcc $(CFLAGS) -o main main.o PileB.o P4.o PileDyn.o IA.o
	
main.o : main.c PileB.h base.h  P4.h PileDyn.h IA.o
	gcc $(CFLAGS) -c main.c 
	
PileB.o : PileB.h PileB.c base.h
	gcc $(CFLAGS) -c PileB.c
	
P4.o : P4.h P4.c base.h PileB.h PileDyn.h
	gcc $(CFLAGS) -c P4.c
	
PileDyn.o : PileDyn.c PileDyn.h base.h
	gcc $(CFLAGS) -c PileDyn.c

IA.o: IA.h IA.c P4.h base.h
	gcc $(CFLAGS) -c IA.c

archive : 
	tar -f OleemahomedPuissance4.tar.gz -cvz *.c *.h *.txt makefile
	
clean : 
	rm *.o

doc:
	doxygen Doxyfile
