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
    float xMin;
    float yMin;
    float zMin;
    float xMax;
    float yMax;
    float zMax;
    std::list<Objeto> l_objetos;
    std::list<Vertice> l_vertices;
    std::list<Cara> l_caras;

public:
    Caja();
    void setxMin(float xMin);
    void setyMin(float yMin);
    void setzMin(float zMin);
    void setxMax(float xMax);
    void setyMax(float yMax);
    void setzMax(float zMax);
    float getxMin();
    float getyMin();
    float getzMin();
    float getxMax();
    float getyMax();
    float getzMax();
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
