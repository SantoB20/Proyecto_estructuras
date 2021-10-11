#ifndef __ARBOLKD_H__
#define __ARBOLKD_H__

#include "NodoKD.h"
#include <queue>

class ArbolKD
{
    protected:
        NodoKD *raiz;
    public:
       ArbolKD();
       ~ArbolKD();
       punto datoRaiz();
       NodoKD *obtenerRaiz();
       void fijarRaiz(NodoKD *n_raiz);
       bool esVacio();
       bool insertar(punto val);
       void preOrden();
       void inOrden();
       void posOrden();
       void nivelOrden();
       NodoKD* cercano(float x, float y, float z);
};

#endif
