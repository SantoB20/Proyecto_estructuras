#ifndef _OBJETO_H_
#define _OBJETO_H_

#include <list>
#include <string>
#include "vertice.h"
#include "cara.h"

class Objeto{
    private:
        std::string nombre;
        std::list<Vertice> l_vertices;
        std::list<Cara> l_caras;
    public:
        Objeto();
        void setNombre(std::string nom);
        std::string getNombre();
        unsigned int tamLVertices();
        unsigned int tamLCaras();
        bool agregarVertice(Vertice v);
        bool agregarCara(Cara c);
};

#endif //_OBJETO_H_