#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void abre_compuertas(){

	printf("Esta funcion nunca se va a ejecutar\n");
	fflush(0);
}

void ejecuta(){

	system("/bin/bash");

}

void funcion(){

	char pass[16]="PasswordCool";
	char userpass[16];
	int cont=3;

	while(cont > 0){

		printf("Dame la password: ");
		fflush(0);
		scanf("%s",userpass);
		if(strcmp(userpass,pass)==0){

			printf("Bienvenido al sistema\n");
			cont=3;

		}else{

			printf("Clave incorrecta\n");
			cont=cont-1;

		}
		fflush(0);

	}

}

void main(int argc, char argv[]){

	funcion();

}
