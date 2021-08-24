#include "cara.h"

//constructor
Cara::Cara()
{
    tam=0;
}
//fijar tamaño
void Cara::setTam(unsigned int tam)
{
    this->tam;
}
//obtener tamaño
unsigned int Cara::getTam()
{
    return tam;
}
//agrega un nuevo indice en v_indices
void Cara::agregarIndice(unsigned int ind)
{
    v_indices.push_back(ind);
}
//retorna v_indices
std::vector<unsigned int> Cara::getIndices()
{
    return v_indices;
}