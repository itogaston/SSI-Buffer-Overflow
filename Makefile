compile:
	gcc -o bin/program src/main.c --static -m32 -no-pie
all: compile
	./bin/program