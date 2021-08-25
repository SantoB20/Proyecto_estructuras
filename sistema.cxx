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
    if (l_objetos.size() == 1)
    {
        std::cout << "Hay " << l_objetos.size() << " objeto en memoria" << std::endl;
    }
    else
    {
        std::cout << "Hay " << l_objetos.size() << " objetos en memoria" << std::endl;
    }
    std::list<Objeto>::iterator It;
    for (It = l_objetos.begin(); It != l_objetos.end(); It++)
    {
        std::cout << It->getNombre() << " tiene: ";
        std::cout << It->tamLVertices() << " vertices, ";
        std::cout << It->tamLVertices() / 2 << " aristas y ";
        std::cout << It->tamLCaras() << " caras" << std::endl;
    }
}
//Agrega o a l_objetos
bool Sistema::agregarObjeto(Objeto o)
{
    if (l_objetos.size() > 0)
    {
        std::list<Objeto>::iterator It;
        for (It = l_objetos.begin(); It != l_objetos.end(); It++)
        {
            if (It->getNombre() == o.getNombre())
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
//Crea una caja envolvente, agregando todos los objetos de memoria, y generando los vertices que la forman
bool Sistema::envolvente()
{
    if (l_objetos.size() == 0)
    {
        return false;
    }
    else
    {
        Caja caja;
        caja.insertCajas(l_objetos);
        l_objetos.clear();
        caja.calcularVertices();
        caja.crearVertices();
        std::string nom= "caja_";
        caja.setNombre(nom+std::to_string(l_cajas.size()));
        std::cout << std::endl << caja.tamLObjetos() << " objeto dentro de la caja" << std::endl;
        std::cout << std::endl<< "Vertices: " << std::endl;
        caja.Impv();
        std::cout << std::endl<<"Agregada la caja envolvente " << caja.getNombre() << " exitosamente"<<std::endl;
        l_cajas.push_back(caja);
        return true;
    }
}