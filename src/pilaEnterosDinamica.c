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
	nuevo->elem=strdup(elemento);
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

void printPila(tipoPila p) {
	if (esNulaPila(p)){
		return ;
	}
	int count = 0;
	tipoPila tmp = p;
	while (tmp != NULL)
	{
		printf("%s ", tmp->elem);
		tmp = tmp->sig;
		count++;		
	}
}