/*
  FICHERO: pilaEnterosDinamica.c
  VERSION: 1.0.0
  HISTORICO:
  Creado por ArÃ¡nzazu JurÃ­o MunÃ¡rriz el 09/09/19.
  
  Este fichero se crea sÃ³lo con intenciones de coordinaciÃ³n docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusiÃ³n, copia
  o exhibiciÃ³n pÃºblica (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en IngenierÃ­a InformÃ¡tica de la UPNA).
*/


#include "pilaEnterosDinamica.h"
#include <stdio.h>
#include <stdlib.h>


void nuevaPila(tipoPila *p){
	*p=NULL;
}

void errorPila(char s[]){
	printf("\n\n\nERROR en el modulo pilas: %s \n", s);
}

void apilar(tipoPila *p, tipoElementoPila elemento){
	celdaPila *nuevo;
	nuevo=(celdaPila*)malloc(sizeof(celdaPila));
	nuevo->elem=elemento;
	nuevo->sig=*p;
	*p=nuevo;
}

void desapilar(tipoPila *p){
	if (esNulaPila(*p))
		errorPila("No se puede desapilar en una pila vacia.");
	else{
		celdaPila *aux;
		aux=*p;
		*p=(*p)->sig;
		free(aux);
	}
}

tipoElementoPila cima(tipoPila p){
	if (esNulaPila(p)){
		errorPila("No se puede obtener la cima en una pila vacia.");
    }  
	else
	{
        return p->elem;
    }
}

bool esNulaPila(tipoPila p){
	return p==NULL;
}
