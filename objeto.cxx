#include "objeto.h"

//constructor
Objeto::Objeto()
{
    nombre="";
}
//fijar nombre
void Objeto::setNombre(std::string nom)
{
    this->nombre=nom;
}
//obtener nombre
std::string Objeto::getNombre()
{
    return nombre;
}