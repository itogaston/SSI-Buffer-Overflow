#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void funcionalidad_cool()
{
	printf("Esta funcion es super útil\n");
	fflush(0);
}

void no_ejecuta()
{
	// Esto nunca se ejecuta o no no
	system("/bin/bash");
}

void login()
{
	char pass[16] = "MakeSantiProud!";
	char userpass[16];
	int cont = 0;

	while (cont < 3)
	{
		printf("Dame la password: ");
		fflush(0);
		scanf("%s", userpass);
		if (strcmp(userpass, pass) == 0)
		{
			printf("Bienvenido al sistema\n");
			funcionalidad_cool();
		}
		else
		{
			printf("Clave incorrecta\n");
			cont++;
		}
		fflush(0);
	}
}

int main(int argc, char **argv)
{
	login();
}
