#include <iostream>
#include "sistema.h"

//Retorna el tamaño de l_objetos
unsigned int Sistema::tamLObjetos()
{
    return l_objetos.size();
}
//Retorna el tamaño de l_cajas
unsigned int Sistema::tamLCajas()
{
    return l_cajas.size();
}
//Imprime la informacion de todos los objetos en memoria
void Sistema::listar()
{
    std::list<Objeto>::iterator It;
    for (It = l_objetos.begin(); It != l_objetos.end(); It++)
    {
        std::cout<< It->getNombre() << "tiene: ";
        std::cout << It->tamLVertices() << " vertices, ";
        std::cout<< It->tamLVertices()/2<< " aristas y ";
        std::cout << It->tamLCaras()<< " caras"<< std::endl;
    }
}
//Agrega o a l_objetos
bool Sistema::agregarObjeto(Objeto o)
{
    if(l_objetos.size() > 0)
    {
        std::list<Objeto>::iterator It;
        for(It=l_objetos.begin();It!=l_objetos.end();It++)
        {
            if(It->getNombre()==o.getNombre())
            {
                return false;
            }
        }
        l_objetos.push_back(o);
        return true;
    }
    else
    {
        l_objetos.push_back(o);
        return true;
    }
}