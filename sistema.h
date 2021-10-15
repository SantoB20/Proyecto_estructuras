#ifndef _SISTEMA_H_
#define _SISTEMA_H_

#include <iostream>
#include <list>
#include "objeto.h"
#include "caja.h"
#include <fstream>
#include "ArbolKD.h"

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
        void cargar(std::string arch);
        void envolvente(std::string nom);
        bool descargar(std::string nom);
        void guardar(std::string nom, std::string arch);
        void v_cercano(std::string nom, float x, float y, float z);
        void v_cercanos_caja(std::string nom);
};

#endif //_SISTEMA_H_
