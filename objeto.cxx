#include "objeto.h"

//constructor
Objeto::Objeto()
{
    nombre = "";
}
//fijar nombre
void Objeto::setNombre(std::string nom)
{
    this->nombre = nom;
}
//obtener nombre
std::string Objeto::getNombre()
{
    return nombre;
}
//retorna el tamaño de l_vertices
unsigned int Objeto::tamLVertices()
{
    return l_vertices.size();
}
//retorna el tamaño de l_caras
unsigned int Objeto::tamLCaras()
{
    return l_caras.size();
}
//agrega un vertice a l_vertices
bool Objeto::agregarVertice(Vertice v)
{
    if (l_vertices.size() > 0)
    {
        std::list<Vertice>::iterator It;
        //verifica si v ya existe o no en el objeto
        for (It = l_vertices.begin(); It != l_vertices.end(); It++)
        {
            if (It->getIndice() == v.getIndice())
            {
                return false;
            }
        }
        l_vertices.push_back(v);
        return true;
    }
    else
    {
        l_vertices.push_back(v);
        return true;
    }
}
//agrega una cara a l_caras
bool Objeto::agregarCara(Cara c)
{
    if(l_caras.size()>0)
    {
        std::list<Cara>::iterator It;
        //revisa si c existe o no en el objeto
        for(It=l_caras.begin();It!=l_caras.end();It++)
        {
            if(It->getIndices()==c.getIndices())
            {
                return false;
            }
        }
        l_caras.push_back(c);
        return true;
    }
    else
    {
        l_caras.push_back(c);
        return true;
    }
}