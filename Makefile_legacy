bin: 
	mkdir bin
compile:
	gcc -o bin/program src/main.c --static -m32 -no-pie
clean:
	rm bin/*
all: bin compile
	./bin/program