all:
	gcc -c src/pilaEnterosDinamica.c -o bin/pilaEnterosDinamica.o
	gcc -c src/secuenciaEnteros.c bin/pilaEnterosDinamica.o -o bin/secuenciaEnteros.o
	gcc src/ejecutarSecuenciaEnteros.c bin/pilaEnterosDinamica.o bin/secuenciaEnteros.o -o bin/program
	./bin/program