/*
  FICHERO: secuenciaEnteros.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por ArÃ¡nzazu JurÃ­o MunÃ¡rriz el 09/09/19.
  
  Este fichero se crea sÃ³lo con intenciones de coordinaciÃ³n docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusiÃ³n, copia
  o exhibiciÃ³n pÃºblica (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en IngenierÃ­a InformÃ¡tica de la UPNA).
*/

#include "pilaEnterosDinamica.h"

 typedef struct sec{
	 tipoPila pilaIzq;
	 tipoPila pilaDcha;
 } tipoSecuencia; 

void nuevaSecuencia(tipoSecuencia*);

void insertarDelantePunto(tipoSecuencia*, tipoElementoPila);

void insertarEnPunto(tipoSecuencia*, tipoElementoPila);

void eliminarEnPunto(tipoSecuencia*);

tipoElementoPila consultarEnPunto(tipoSecuencia);

void avanzarPunto (tipoSecuencia*);

void moverPuntoAlPrincipio (tipoSecuencia*);

bool esPuntoUltimo(tipoSecuencia);

bool esVaciaSecuencia(tipoSecuencia);