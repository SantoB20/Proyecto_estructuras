#ifndef _CAJA_H_
#define _CAJA_H_

#include <string>
#include <list>
#include "vertice.h"
#include "objeto.h"

class Caja{
    private:
        std::string nombre;
        std::list<Objeto> l_objetos;
        std::list<Vertice> l_vertices;
    public:
        Caja();
        void setNombre(std::string nom);
        std::string getNombre();
};

#endif //_CAJA_H_