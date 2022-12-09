all:
	gcc -c src/pilaEnterosDinamica.c -o bin/pilaEnterosDinamica.o
	gcc -c src/secuenciaEnteros.c bin/pilaEnterosDinamica.o -o bin/secuenciaEnteros.o
	gcc src/ejecutarSecuenciaEnteros.c bin/pilaEnterosDinamica.o bin/secuenciaEnteros.o -o bin/program
	
serve: all
	socat TCP-listen:54470,reuseaddr,fork EXEC:./bin/program

local:
	nc localhost 54470