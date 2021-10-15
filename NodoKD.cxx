#include "NodoKD.h"

NodoKD::NodoKD()
{
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}
NodoKD::NodoKD(punto val)
{
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
    this->dato = val;
}
NodoKD::~NodoKD()
{
    if (this->hijoIzq != NULL)
    {
        delete this->hijoIzq;
        this->hijoIzq = NULL;
    }
    if (this->hijoDer != NULL)
    {
        delete this->hijoDer;
        this->hijoDer = NULL;
    }
}
bool NodoKD::esHoja()
{
    return (this->hijoIzq == NULL && this->hijoDer == NULL);
}
punto NodoKD::obtenerDato()
{
    return this->dato;
}
void NodoKD::fijarDato(punto val)
{
    this->dato = val;
}
NodoKD *NodoKD::obtenerHijoIzq()
{
    return this->hijoIzq;
}
NodoKD *NodoKD::obtenerHijoDer()
{
    return this->hijoDer;
}
void NodoKD::fijarHijoIzq(NodoKD *izq)
{
    this->hijoIzq = izq;
}
void NodoKD::fijarHijoDer(NodoKD *der)
{
    this->hijoDer = der;
}
void NodoKD::preOrden()
{
    std::cout << this->dato << " ";
     if(this->hijoIzq != NULL)
    {
        (this->hijoIzq)->preOrden();
    }
    if(this->hijoDer != NULL)
    {
        (this->hijoDer)->preOrden();
    }  
}
void NodoKD::inOrden()
{
    if(this->hijoIzq != NULL)
    {
        (this->hijoIzq)->inOrden();
    }
    std::cout << this->dato << " ";
    if(this->hijoDer != NULL)
    {
        (this->hijoDer)->inOrden();
    }  
}
void NodoKD::posOrden()
{
    if(this->hijoIzq != NULL)
    {
        (this->hijoIzq)->posOrden();
    }
    if(this->hijoDer != NULL)
    {
        (this->hijoDer)->posOrden();
    } 
    std::cout << this->dato << " ";
}
NodoKD* NodoKD::cercano(float x, float y, float z)
{
    float distanciaRaiz = sqrt(pow(this->dato.x - x, 2) + pow(this->dato.y - y, 2) + pow(this->dato.z - z, 2));
    float distanciaIzq = -1, distanciaDer = -1;
    NodoKD *hijo1, *hijo2;
    if (this->hijoIzq != NULL)
    {
        hijo1 = ((this->hijoIzq))->cercano(x, y, z);
        distanciaIzq = sqrt(pow(hijo1->obtenerDato().x - x, 2) + pow(hijo1->obtenerDato().y - y, 2) + pow(hijo1->obtenerDato().z - z, 2));
    }
    if (this->hijoDer != NULL)
    {
        hijo2 = ((this->hijoDer))->cercano(x, y, z);
        distanciaDer = sqrt(pow(hijo2->obtenerDato().x - x, 2) + pow(hijo2->obtenerDato().y - y, 2) + pow(hijo2->obtenerDato().z - z, 2));
    }
    if (distanciaIzq != -1 && distanciaDer != -1)
    {
        if (distanciaIzq < distanciaDer && distanciaIzq < distanciaRaiz)
            return hijo1;
        if (distanciaDer < distanciaIzq && distanciaDer < distanciaRaiz)
            return hijo2;
        else
            return this;
    }
    else
    {
        if (distanciaIzq != -1)
        {
            if (distanciaIzq < distanciaRaiz)
                return hijo1;
            else
                return this;
        }
        else
        {
            if (distanciaDer != -1)
            {
                if (distanciaDer < distanciaRaiz)
                    return hijo2;
                else
                    return this;
            }
            else
                this;
        }
    }
    return this;
}