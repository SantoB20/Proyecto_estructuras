#ifndef _SISTEMA_H_
#define _SISTEMA_H_

#include <iostream>
#include <list>
#include "objeto.h"
#include "caja.h"
#include <fstream>

class Sistema{
    private:
        std::list<Objeto> l_objetos;
        std::list<Caja> l_cajas;
    public:
        unsigned int tamLObjetos();
        unsigned int tamLCajas();
        void listar();
        bool agregarObjeto(Objeto o);
        bool buscarObjeto(std::string nom);
        void envolvente(std::string nom);
        void guardar(std::string nom, std::string arch);
};

#endif //_SISTEMA_H_