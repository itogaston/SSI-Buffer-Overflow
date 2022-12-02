#include <stdio.h>
int cont=3;

void funcion(){

	char nombre[16];

	printf("Dame  tu nombre: ");
	fflush(0);
	gets(nombre);
	printf("Bienvenido ");
	printf(nombre);
	printf("\n\n");
	printf("El valor de cont es %d\n",cont);

}

int main(int argc, char *argv[]){

	funcion();

}
