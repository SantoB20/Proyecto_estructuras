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
};

#endif //_SISTEMA_H_