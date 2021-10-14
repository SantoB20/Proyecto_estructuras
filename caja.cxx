#include "caja.h"

//constructor
Caja::Caja()
{
}
//fija punto x minimo de la caja
void Caja::setxMin(float xMin)
{
    this->xMin = xMin;
}
//fija punto y minimo de la caja
void Caja::setyMin(float yMin)
{
    this->yMin = yMin;
}
//fija punto z minimo de la caja
void Caja::setzMin(float zMin)
{
    this->zMin = zMin;
}
//fija punto x maximo de la caja
void Caja::setxMax(float xMax)
{
    this->xMax = xMax;
}
//fija punto y maximo de la caja
void Caja::setyMax(float yMax)
{
    this->yMax = yMax;
}
//fija punto z maximo de la caja
void Caja::setzMax(float zMax)
{
    this->zMax = zMax;
}
//obtiene punto x minimo de la caja
float Caja::getxMin()
{
    return xMin;
}
//obtiene punto y minimo de la caja
float Caja::getyMin()
{
    return yMin;
}
//obtiene punto z minimo de la caja
float Caja::getzMin()
{
    return zMin;
}
//obtiene punto x maximo de la caja
float Caja::getxMax()
{
    return xMax;
}
//obtiene punto y maximo de la caja
float Caja::getyMax()
{
    return yMax;
}
//obtiene punto z maximo de la caja
float Caja::getzMax()
{
    return zMax;
}
//fijar nombre
void Caja::setNombre(std::string nom)
{
    this->nombre = nom;
}
//obtener nombre
std::string Caja::getNombre()
{
    return nombre;
}
//retorna la lista de objetos en la caja
std::list<Objeto> Caja::getObjetos()
{
    return l_objetos;
}
//retorna la lista de vertices de la caja
std::list<Vertice> Caja::getVertices()
{
    return l_vertices;
}
//retorna la cantidad de vertices de la caja
int Caja::tamLVertices()
{
    return l_vertices.size();
}
//retorn la cantidad de caras de la caja
int Caja::tamLCaras()
{
    return l_caras.size();
}
//retorna la cantidad de objetos dentro de la caja
int Caja::tamLObjetos()
{
    return l_objetos.size();
}
//Inserta el objeto obj en l_objetos
void Caja::insertObj(Objeto obj)
{
    l_objetos.push_back(obj);
}
//Inserta los objetos de memoria en l_objetos
void Caja::insertObjs(std::list<Objeto> obj)
{
    l_objetos.insert(l_objetos.end(), obj.begin(), obj.end());
}
void Caja::calcMin(char coordenada)
{
    float min = 0;
    std::list<Objeto>::iterator It;
    for (It = l_objetos.begin(); It != l_objetos.end(); It++)
    {
        switch (coordenada)
        {
        case 'x':
            if (It->Min('x') <= min)
            {
                xMin = It->Min('x');
                min = It->Min('x');
            }
            break;
        case 'y':
            if (It->Min('y') <= min)
            {
                yMin = It->Min('y');
                min = It->Min('y');
            }
            break;
        case 'z':
            if (It->Min('z') <= min)
            {
                zMin = It->Min('z');
                min = It->Min('z');
            }
            break;
        }
    }
}
void Caja::calcMax(char coordenada)
{
    float max = 0;
    std::list<Objeto>::iterator It;
    for (It = l_objetos.begin(); It != l_objetos.end(); It++)
    {
        switch (coordenada)
        {
        case 'x':
            if (It->Max('x') >= max)
            {
                xMax = It->Max('x');
                max = It->Max('x');
            }
            break;
        case 'y':
            if (It->Max('y') >= max)
            {
                yMax = It->Max('y');
                max = It->Max('y');
            }
            break;
        case 'z':
            if (It->Max('z') >= max)
            {
                zMax = It->Max('z');
                max = It->Max('z');
            }
            break;
        }
    }
}
//Invoca todas las funciones que calculan los minimos y maximos de la caja
void Caja::calcularVertices()
{
    calcMin('x');
    calcMin('y');
    calcMin('z');
    calcMax('x');
    calcMax('y');
    calcMax('z');
}
//crea los vertices que forman la caja envolvente, a partir de xMin, yMin, zMin, xMax, yMax y zMax
void Caja::crearVertices()
{
    l_vertices.push_back(Vertice(0, xMin, yMin, zMin));
    l_vertices.push_back(Vertice(1, xMax, yMin, zMin));
    l_vertices.push_back(Vertice(2, xMin, yMax, zMin));
    l_vertices.push_back(Vertice(3, xMax, yMax, zMin));
    l_vertices.push_back(Vertice(4, xMin, yMin, zMax));
    l_vertices.push_back(Vertice(5, xMax, yMin, zMax));
    l_vertices.push_back(Vertice(6, xMin, yMax, zMax));
    l_vertices.push_back(Vertice(7, xMax, yMax, zMax));
}
//crea las caras que forman la caja envolvente, a partir de los vertices ya creados
void Caja::crearCaras()
{
    std::list<Vertice>::iterator It;
    for (int i = 0; i < 6; i++)
    {
        Cara aux;
        for (It = l_vertices.begin(); It != l_vertices.end(); It++)
        {
            switch (i)
            {
            case 0:
                if (It->getIndice() == 0 || It->getIndice() == 1 || It->getIndice() == 2 || It->getIndice() == 3)
                {
                    aux.agregarIndice(It->getIndice());
                }
                break;
            case 1:
                if (It->getIndice() == 4 || It->getIndice() == 5 || It->getIndice() == 6 || It->getIndice() == 7)
                {
                    aux.agregarIndice(It->getIndice());
                }
                break;
            case 2:
                if (It->getIndice() == 0 || It->getIndice() == 1 || It->getIndice() == 4 || It->getIndice() == 5)
                {
                    aux.agregarIndice(It->getIndice());
                }
                break;
            case 3:
                if (It->getIndice() == 1 || It->getIndice() == 3 || It->getIndice() == 5 || It->getIndice() == 7)
                {
                    aux.agregarIndice(It->getIndice());
                }
                break;
            case 4:
                if (It->getIndice() == 2 || It->getIndice() == 3 || It->getIndice() == 6 || It->getIndice() == 7)
                {
                    aux.agregarIndice(It->getIndice());
                }
                break;
            case 5:
                if (It->getIndice() == 0 || It->getIndice() == 2 || It->getIndice() == 4 || It->getIndice() == 6)
                {
                    aux.agregarIndice(It->getIndice());
                }
                break;
            }
        }
        aux.setTam(4);
        l_caras.push_back(aux);
    }
}
//retorna en una linea de string de px, py, pz del vertice en la posicion pos, en l_vertices
std::string Caja::infoVertice(int pos)
{
    std::string linea;
    std::list<Vertice>::iterator It = l_vertices.begin();
    for (int i = 0; i < pos; i++)
    {
        It++;
    }
    linea = std::to_string(It->getPx()) + " " + std::to_string(It->getPy()) + " " + std::to_string(It->getPz());
    return linea;
}
//retorna una linea de string de el tamaño y los indices de la cara en la posicion pos, en l_caras
std::string Caja::infoCara(int pos)
{
    std::string linea;
    std::list<Cara>::iterator It = l_caras.begin();
    for (int i = 0; i < pos; i++)
    {
        It++;
    }
    linea = std::to_string(It->getTam());
    std::vector<unsigned int> indices = It->getIndices();
    for (int i = 0; i < indices.size(); i++)
    {
        linea.append(" " + std::to_string(indices[i]));
    }
    return linea;
}
