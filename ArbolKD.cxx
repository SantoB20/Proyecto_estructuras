#include "ArbolKD.h"

ArbolKD::ArbolKD()
{
    this->raiz = NULL;
}
ArbolKD::~ArbolKD()
{
    if (this->raiz != NULL)
    {
        delete this->raiz;
        this->raiz = NULL;
    }
}
punto ArbolKD::datoRaiz()
{
    return (this->raiz)->obtenerDato();
}
NodoKD *ArbolKD::obtenerRaiz()
{
    return this->raiz;
}
void ArbolKD::fijarRaiz(NodoKD *n_raiz)
{
    this->raiz = n_raiz;
}
bool ArbolKD::esVacio()
{
    return this->raiz == NULL;
}
bool ArbolKD::insertar(punto val)
{
    NodoKD *padre = this->raiz, *nodo = this->raiz;
    bool insertado = false, duplicado = false;
    char coordenada = 'z';
    if (this->esVacio())
    {
        NodoKD *nuevo = new NodoKD(val);
        this->raiz = nuevo;
        return true;
    }
    while (nodo != NULL)
    {
        padre = nodo;
        switch (coordenada)
        {
        case 'x':
            coordenada = 'y';
            break;
        case 'y':
            coordenada = 'z';
            break;
        case 'z':
            coordenada = 'x';
            break;
        }
        switch (coordenada)
        {
        case 'x':
            if (val.x >= (nodo->obtenerDato()).x)
            {
                nodo = nodo->obtenerHijoDer();
            }
            else
            {
                if (val.x < (nodo->obtenerDato()).x)
                {
                    nodo = nodo->obtenerHijoIzq();
                }
            }
            break;
        case 'y':
            if (val.y >= (nodo->obtenerDato()).y)
            {
                nodo = nodo->obtenerHijoDer();
            }
            else
            {
                if (val.y < (nodo->obtenerDato()).y)
                {
                    nodo = nodo->obtenerHijoIzq();
                }
            }
            break;
        case 'z':
            if (val.z >= (nodo->obtenerDato()).z)
            {
                nodo = nodo->obtenerHijoDer();
            }
            else
            {
                if (val.z < (nodo->obtenerDato()).z)
                {
                    nodo = nodo->obtenerHijoIzq();
                }
            }
            break;
        }
    }
    if (!duplicado)
    {
        NodoKD *nuevo = new NodoKD(val);
        if (nuevo != NULL)
        {
            switch (coordenada)
            {
            case 'x':
                if (val.x >= (padre->obtenerDato()).x)
                {
                    padre->fijarHijoDer(nuevo);
                }
                else
                {
                    if (val.x < (padre->obtenerDato()).x)
                    {
                        padre->fijarHijoIzq(nuevo);
                    }
                }
                break;
            case 'y':
                if (val.y >= (padre->obtenerDato()).y)
                {
                    padre->fijarHijoDer(nuevo);
                }
                else
                {
                    if (val.y < (padre->obtenerDato()).y)
                    {
                        padre->fijarHijoIzq(nuevo);
                    }
                }
                break;
            case 'z':
                if (val.z >= (padre->obtenerDato()).z)
                {
                    padre->fijarHijoDer(nuevo);
                }
                else
                {
                    if (val.z < (padre->obtenerDato()).z)
                    {
                        padre->fijarHijoIzq(nuevo);
                    }
                }
                break;
            }
        }
        insertado = true;
    }
    return insertado;
}
void ArbolKD::preOrden()
{
    if (!esVacio())
    {
        (this->raiz)->preOrden();
    }
}
void ArbolKD::inOrden()
{
    if (!esVacio())
    {
        (this->raiz)->inOrden();
    }
}
void ArbolKD::posOrden()
{
    if (!esVacio())
    {
        (this->raiz)->posOrden();
    }
}
void ArbolKD::nivelOrden()
{
    if (!this->esVacio())
    {
        std::queue<NodoKD *> cola;
        cola.push(this->raiz);
        NodoKD *nodo;
        while (!cola.empty())
        {
            nodo = cola.front();
            cola.pop();
            std::cout << nodo->obtenerDato() << " ";
            if (nodo->obtenerHijoIzq() != NULL)
            {
                cola.push(nodo->obtenerHijoIzq());
            }
            if (nodo->obtenerHijoDer() != NULL)
            {
                cola.push(nodo->obtenerHijoDer());
            }
        }
    }
}
NodoKD *ArbolKD::cercano(float x, float y, float z)
{
    float distanciaRaiz = sqrt(pow(((this->raiz))->obtenerDato().x - x, 2) + pow(((this->raiz))->obtenerDato().y - y, 2) + pow(((this->raiz))->obtenerDato().z - z, 2));
    float distanciaIzq = -1, distanciaDer = -1;
    NodoKD *hijo1, *hijo2, *menor;
    if ((this->raiz)->obtenerHijoIzq() != NULL)
    {
        hijo1 = ((this->raiz)->obtenerHijoIzq())->cercano(x, y, z);
        distanciaIzq = sqrt(pow(hijo1->obtenerDato().x - x, 2) + pow(hijo1->obtenerDato().y - y, 2) + pow(hijo1->obtenerDato().z - z, 2));
    }
    if ((this->raiz)->obtenerHijoDer() != NULL)
    {
        hijo2 = ((this->raiz)->obtenerHijoDer())->cercano(x, y, z);
        distanciaDer = sqrt(pow(hijo2->obtenerDato().x - x, 2) + pow(hijo2->obtenerDato().y - y, 2) + pow(hijo2->obtenerDato().z - z, 2));
    }
    if (distanciaIzq != -1 && distanciaDer != -1)
    {
        if (distanciaIzq < distanciaDer && distanciaIzq < distanciaRaiz)
            return hijo1;
        if (distanciaDer < distanciaIzq && distanciaDer < distanciaRaiz)
            return hijo2;
        else
            return this->raiz;
    }
    else
    {
        if (distanciaIzq != -1)
        {
            if (distanciaIzq < distanciaRaiz)
                return hijo1;
            else
                return this->raiz;
        }
        else
        {
            if (distanciaDer != -1)
            {
                if (distanciaDer < distanciaRaiz)
                    return hijo2;
                else
                    return this->raiz;
            }
            else
                this->raiz;
        }
    }
    return this->raiz;
}
