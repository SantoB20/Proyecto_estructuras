#include "vertice.h"

//constructor
Vertice::Vertice()
{
    indice = -1;
    px=0;
    py=0;
    pz=0;
}
Vertice::Vertice(unsigned int ind, float x, float y, float z)
{
    this->indice = ind;
    this->px=x;
    this->py=y;
    this->pz=z;
}
//fijar indice
void Vertice::setIndice(unsigned int ind)
{
    indice=ind;
}
//fijar ubicacion en x
void Vertice::setPx(float x)
{
    px=x;
}
//fijar ubicacion en y     
void Vertice::setPy(float y)
{
    py=y;
}
//fijar ubicacion en z    
void Vertice::setPz(float z)
{
    pz=z;
}
//obtener indice
unsigned int Vertice::getIndice(){
    return indice;
}
//obtener ubicacion en x
int Vertice::getPx()
{
    return px;
}
//obtener ubicacion en y
int Vertice::getPy()
{
    return py;
}
//obtener ubicacion en z
int Vertice::getPz()
{
    return pz;
}