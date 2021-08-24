#ifndef _SISTEMA_H_
#define _SISTEMA_H_

#include <list>
#include "objeto.h"
#include "caja.h"

class Sistema{
    private:
        std::list<Objeto> l_objetos;
        std::list<Caja> l_cajas;
    public:
        unsigned int tamLObjetos();
        unsigned int tamLCajas();
        void listar();
        bool agregarObjeto(Objeto o);
};

#endif //_SISTEMA_H_