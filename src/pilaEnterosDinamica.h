#include <string.h>
#include <stdbool.h>

typedef char* tipoElementoPila;
typedef struct celdaP{
  tipoElementoPila elem;
  struct celdaP *sig;
} celdaPila; 
typedef celdaPila* tipoPila;

void nuevaPila(tipoPila *);

void errorPila(char *);

void apilar(tipoPila *, tipoElementoPila);

void desapilar(tipoPila *);

tipoElementoPila cima(tipoPila);

bool esNulaPila(tipoPila);

void printPila(tipoPila);
