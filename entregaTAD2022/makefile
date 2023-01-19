# Oscar Hernandez Hernandez
# https://github.com/oscaarrhernandez

all: pruebaRadixSort limpiar

pruebaRadixSort: pruebaRadixSort.c listas/lista.h listas/lista.o radixSort.o
	gcc pruebaRadixSort.c radixSort.o listas/lista.o -o pruebaRadixSort -lm

radixSort.o: radixSort.c radixSort.h listas/lista.h 
	gcc -c radixSort.c 

listas/lista.o: listas/lista.c listas/lista.h 
	gcc -c listas/lista.c -o listas/lista.o 
	
limpiar:
	rm *.o listas/lista.o
