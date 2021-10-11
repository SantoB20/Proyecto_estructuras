#ifndef _CAJA_H_
#define _CAJA_H_

#include <string>
#include <list>
#include "vertice.h"
#include "objeto.h"
#include <iostream>

class Caja
{
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
    std::list<Cara> l_caras;

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
    std::list<Objeto> getObjetos();
    std::list<Vertice> getVertices();
    int tamLVertices();
    int tamLCaras();
    int tamLObjetos();
    void insertObj(Objeto obj);
    void insertObjs(std::list<Objeto> obj);
    void calcMin(char coordenada);
    void calcMax(char coordenada);
    void calcularVertices();
    void crearVertices();
    void crearCaras();
    std::string infoVertice(int pos);
    std::string infoCara(int pos);
};

#endif //_CAJA_H_