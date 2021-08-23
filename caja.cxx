#include "caja.h"

//constructor
Caja::Caja()
{

}
//fijar nombre
void Caja::setNombre(std::string nom)
{
    this->nombre=nom;
}
//obtener nombre
std::string Caja::getNombre()
{
    return nombre;
} 