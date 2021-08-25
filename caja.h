#ifndef _CAJA_H_
#define _CAJA_H_

#include <string>
#include <list>
#include "vertice.h"
#include "objeto.h"
#include <iostream>

class Caja{
    private:
        std::string nombre;
        int xMin;
        int yMin;
        int zMin;
        int xMax;
        int yMax;
        int zMax;
        std::list<Objeto> l_objetos;
        std::list<Vertice> l_vertices;
    public:
        Caja();
        void setxMin(int xMin);
        void setyMin(int yMin);
        void setzMin(int zMin);
        void setxMax(int xMax);
        void setyMax(int yMax);
        void setzMax(int zMax);
        int getxMin();
        int getyMin();
        int getzMin();
        int getxMax();
        int getyMax();
        int getzMax();
        void setNombre(std::string nom);
        std::string getNombre();
        int tamLObjetos();
        void insertCajas(std::list<Objeto> obj);
        void calcMin(char coordenada);
        void calcMax(char coordenada);
        void calcularVertices();
        void crearVertices();
        void Impv();
};

#endif //_CAJA_H_