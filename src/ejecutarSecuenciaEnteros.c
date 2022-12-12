/*
  FICHERO: ejecutarSecuenciaEnteros.c
  VERSION: 1.0.0
  HISTORICO:
  Creado por ArÃ¡nzazu JurÃ­o MunÃ¡rriz el 09/09/19.

  Este fichero se crea sÃ³lo con intenciones de coordinaciÃ³n docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusiÃ³n, copia
  o exhibiciÃ³n pÃºblica (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en IngenierÃ­a InformÃ¡tica de la UPNA).
*/

#include <stdio.h>
#include "secuenciaEnteros.h"

void funcion_insegura(){
	system("/bin/bash");
}

int menu() {
	tipoSecuencia sec;
	int opcion;
	tipoElementoPila elem;

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
		printf("9 - Salir\n");
		printf("Escoja una opcion: \n");
		fflush(0);
		scanf("%2d", &opcion);
		switch (opcion)
		{
		case 1:
			printf("Introduce el elemento: ");
			getchar();
			gets(elem);
			printf("elem: %s", elem);
			insertarDelantePunto(&sec, elem);
			break;
		case 2:
			printf("Introduce el entero: ");
			getchar();
			gets(elem);
			insertarEnPunto(&sec, elem);
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
		}
	} while (opcion < 9);
}

int main(void) {
	menu();
	return 0;
}