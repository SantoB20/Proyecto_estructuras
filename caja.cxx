#include "caja.h"

//constructor
Caja::Caja()
{
}
//fija punto x minimo de la caja
void Caja::setxMin(int xMin)
{
    this->xMin = xMin;
}
//fija punto y minimo de la caja
void Caja::setyMin(int yMin)
{
    this->yMin = yMin;
}
//fija punto z minimo de la caja
void Caja::setzMin(int zMin)
{
    this->zMin = zMin;
}
//fija punto x maximo de la caja
void Caja::setxMax(int xMax)
{
    this->xMax = xMax;
}
//fija punto y maximo de la caja
void Caja::setyMax(int yMax)
{
    this->yMax = yMax;
}
//fija punto z maximo de la caja
void Caja::setzMax(int zMax)
{
    this->zMax = zMax;
}
//obtiene punto x minimo de la caja
int Caja::getxMin()
{
    return xMin;
}
//obtiene punto y minimo de la caja
int Caja::getyMin()
{
    return yMin;
}
//obtiene punto z minimo de la caja
int Caja::getzMin()
{
    return zMin;
}
//obtiene punto x maximo de la caja
int Caja::getxMax()
{
    return xMax;
}
//obtiene punto y maximo de la caja
int Caja::getyMax()
{
    return yMax;
}
//obtiene punto z maximo de la caja
int Caja::getzMax()
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
//retorna el la cantidad deobjetos dentro de la caja
int Caja::tamLObjetos()
{
    return l_objetos.size();
}
//Inserta los objetos de memoria en l_objetos
void Caja::insertCajas(std::list<Objeto> obj)
{
    l_objetos.insert(l_objetos.end(), obj.begin(), obj.end());
}
void Caja::calcMin(char coordenada)
{
    int min=0;
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
                    yMin=It->Min('y');
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
    int max=0;
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
    l_vertices.push_back(Vertice(0,xMin,yMin,zMin));
    l_vertices.push_back(Vertice(1,xMax,yMin,zMin));
    l_vertices.push_back(Vertice(2,xMin,yMax,zMin));
    l_vertices.push_back(Vertice(3,xMax,yMax,zMin));
    l_vertices.push_back(Vertice(4,xMin,yMin,zMax));
    l_vertices.push_back(Vertice(5,xMax,yMin,zMax));
    l_vertices.push_back(Vertice(6,xMin,yMax,zMax));
    l_vertices.push_back(Vertice(7,xMax,yMax,zMax));
}
void Caja::Impv()
{
    std::list<Vertice>::iterator It;
    for(It=l_vertices.begin();It!=l_vertices.end();It++)
    {
        std::cout << It->getIndice() << " x: " << It->getPx() << " y: " << It->getPy() << " z: " << It->getPz() << std::endl;
    }
}