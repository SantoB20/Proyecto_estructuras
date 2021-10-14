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
//retorna la lista de verices del objeto
std::list<Vertice> Objeto::getVertices()
{
    return l_vertices;
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
    if (l_caras.size() > 0)
    {
        std::list<Cara>::iterator It;
        //revisa si c existe o no en el objeto
        for (It = l_caras.begin(); It != l_caras.end(); It++)
        {
            if (It->getIndices() == c.getIndices())
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
// obtiene el punto mínimo de x, y o z, segun el indicado por coordenada
float Objeto::Min(char coordenada)
{
    float min = 0;
    std::list<Vertice>::iterator It;
    for (It = l_vertices.begin(); It != l_vertices.end(); It++)
    {
        switch (coordenada)
        {
        case 'x':
            if (It->getPx() <= min)
            {
                min = It->getPx();
            }
            break;
        case 'y':
            if (It->getPy() <= min)
            {
                min = It->getPy();
            }
            break;
        case 'z':
            if (It->getPz() <= min)
            {
                min = It->getPz();
            }
            break;
        }
    }
    return min;
}

// obtiene el punto máximo de x, y o z, segun el indicado por coordenada
float Objeto::Max(char p)
{
    float max = 0;
    std::list<Vertice>::iterator It;
    for (It = l_vertices.begin(); It != l_vertices.end(); It++)
    {
        switch (p)
        {
        case 'x':
            if (It->getPx() >= max)
            {
                max = It->getPx();
            }
            break;
        case 'y':
            if (It->getPy() >= max)
            {
                max = It->getPy();
            }
            break;
        case 'z':
            if (It->getPz() >= max)
            {
                max = It->getPz();
            }
            break;
        }
    }
    return max;
}
//retorna en una linea de string de px, py, pz del vertice en la posicion pos, en l_vertices
std::string Objeto::infoVertice(int pos)
{
    std::string linea;
    std::list<Vertice>::iterator It = l_vertices.begin();
    for (int i = 0; i < pos; i++)
    {
        It++;
    }
    linea= std::to_string(It->getPx()) + " " + std::to_string(It->getPy()) + " " + std::to_string(It->getPz());
    return linea;
}
//retorna una linea de string de el tamaño y los indices de la cara en la posicion pos, en l_caras
std::string Objeto::infoCara(int pos)
{
    std::string linea;
    std::list<Cara>::iterator It = l_caras.begin();
    for (int i = 0; i < pos; i++)
    {
        It++;
    }
    linea= std::to_string(It->getTam());
    std::vector<unsigned int> indices = It->getIndices();
    for (int i = 0; i < indices.size(); i++)
    {
        linea.append(" " + std::to_string(indices[i]));
    }
    return linea;
}
