#include "vertice.h"

//constructor
Vertice::Vertice()
{
    indice = -1;
    px=0;
    py=0;
    pz=0;
}
//fijar indice
void Vertice::setIndice(unsigned int ind)
{
    this->indice=ind;
}
//fijar ubicacion en x
void Vertice::setPx(int x)
{
    this->px;
}
//fijar ubicacion en y     
void Vertice::setPy(int y)
{
    this->py
}
//fijar ubicacion en z    
void Vertice::setPz(int z)
{
    this->pz;
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