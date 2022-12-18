#include <stdio.h>
#include <stdlib.h>
#include "secuenciaEnteros.h"

void funcion_insegura(){
	system("/bin/bash");
}

int menu() {
	tipoSecuencia sec;
	int opcion;
	tipoElementoPila elem;
	char buffer[12];
	// la pila izquierda hasta el anterior al punto de interes
	// la pila derecha desde el punto de interÃ©s
	nuevaSecuencia(&sec);
	do
	{
		printf("--------MENU-------- \n");
		printf("1 - Insertar un elemento delante del punto de interes\n");
		printf("2 - Insertar un elemento en el punto de interes\n");
		printf("3 - Eliminar un elemento del punto de interes\n");
		printf("4 - Consultar el elemento en el punto de interes.\n");
		printf("5 - Avanzar un elemento el punto de interes\n");
		printf("6 - Mover el punto de interes al principio\n");
		printf("7 - Esta el punto al final?\n");
		printf("8 - Esta vacia la secuencia?\n");
		printf("9 - Imprimir secuencia\n");
		printf("10- Salir\n");
		printf("Escoja una opcion: \n");
		fflush(0);
		scanf("%2d", &opcion);
		switch (opcion)
		{
		case 1:
			printf("Introduce el elemento: ");
			getchar();
			gets(buffer);
			insertarDelantePunto(&sec, buffer);
			break;
		case 2:
			printf("Introduce el entero: ");
			getchar();
			gets(buffer);
			insertarEnPunto(&sec, buffer);
			break;
		case 3:
			eliminarEnPunto(&sec);
			printf("Se ha eliminado un elemento\n");
			fflush(0);
			break;
		case 4:
			elem = consultarEnPunto(sec);
			printf("El elemento en el punto de interes es %s\n", elem);
			fflush(0);
			break;
		case 5:
			avanzarPunto(&sec);
			break;
		case 6:
			moverPuntoAlPrincipio(&sec);
			break;
		case 7:
			if (esPuntoUltimo(sec))
			{
				printf("El punto de interes esta en el ultimo elemento de la secuencia\n");
				fflush(0);
			}
			else
			{
				printf("El punto de interes no esta al final de la secuencia\n");
				fflush(0);
			}
			break;
		case 8:
			if (esVaciaSecuencia(sec))
			{
				printf("La secuencia esta vacia\n");
				fflush(0);
			}
			else
			{
				printf("La secuencia no esta vacia\n");
				fflush(0);
			}
			break;
		case 9:
			printSecuencia(sec);
		}

	} while (opcion < 10);
}

int main(void) {
	menu();
	return 0;
}