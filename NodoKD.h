#ifndef __NODOKD_H__
#define __NODOKD_H__

#include "Punto.h"
#include <math.h>

class NodoKD
{
    protected:
        punto dato;
        NodoKD *hijoIzq;
        NodoKD *hijoDer;
    public:
        NodoKD();
        NodoKD(punto val);
        ~NodoKD();
        bool esHoja();
        punto obtenerDato();
        void fijarDato(punto val);
        NodoKD *obtenerHijoIzq();
        NodoKD *obtenerHijoDer();
        void fijarHijoIzq(NodoKD *izq);
        void fijarHijoDer(NodoKD *der);
        void preOrden();
        void inOrden();
        void posOrden();
        NodoKD* cercano(float x, float y, float z);
};

#endif