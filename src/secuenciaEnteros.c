#include "secuenciaEnteros.h"
#include <stdio.h>
void nuevaSecuencia(tipoSecuencia *sec)
{
    tipoPila nuevapilaIzq, nuevapilaDer;
    nuevaPila(&nuevapilaIzq);
    nuevaPila(&nuevapilaDer);
    sec->pilaDcha = nuevapilaDer;
    sec->pilaIzq = nuevapilaIzq;
}
void insertarDelantePunto(tipoSecuencia *sec, tipoElementoPila elem)
{
    apilar(&(sec->pilaIzq), elem);
}
void insertarEnPunto(tipoSecuencia *sec, tipoElementoPila elem)
{
    apilar(&(sec->pilaDcha), elem);
}
void eliminarEnPunto(tipoSecuencia *sec)
{
    desapilar(&(sec->pilaDcha));
}
tipoElementoPila consultarEnPunto(tipoSecuencia secuen)
{
    if (esNulaPila(secuen.pilaDcha))
    {
        errorPila("No hay ningún elemento en el punto de interes.\n");
    }
    else
    {
        return cima(secuen.pilaDcha);
    }
}
void avanzarPunto(tipoSecuencia *secuenz)
{
    tipoElementoPila auxili;
    tipoSecuencia aux_secuen;
    aux_secuen = *secuenz;
    auxili = consultarEnPunto(aux_secuen);
    insertarDelantePunto(secuenz, auxili);
    eliminarEnPunto(secuenz);
}
void moverPuntoAlPrincipio(tipoSecuencia *sec)
{
    tipoElementoPila auxili;
    tipoSecuencia aux_secuen;
    aux_secuen = *sec;
    while (esNulaPila(sec->pilaIzq) == false)
    {
        auxili = cima(aux_secuen.pilaIzq);
        desapilar(&sec->pilaIzq);
        aux_secuen = *sec;
        insertarEnPunto(sec, auxili);
    }
}
bool esPuntoUltimo(tipoSecuencia sec)
{
    if (esNulaPila(sec.pilaDcha))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool esVaciaSecuencia(tipoSecuencia sec)
{
    if (esNulaPila(sec.pilaDcha) && (esNulaPila(sec.pilaIzq)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printSecuencia(tipoSecuencia sec){
    printf("Pila Izq: ");
    printPila(sec.pilaIzq);
    printf("\n");
    printf("Pila Der: ");
    printPila(sec.pilaDcha);
    printf("\n");
}