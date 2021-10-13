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
    if (l_objetos.size() + l_cajas.size() == 1)
    {
        std::cout << std::endl
                  << "Hay " << l_objetos.size() << " objeto en memoria" << std::endl;
    }
    else
    {
        std::cout << std::endl
                  << "Hay " << l_objetos.size() + l_cajas.size() << " objetos en memoria" << std::endl;
    }
    std::list<Objeto>::iterator It;
    for (It = l_objetos.begin(); It != l_objetos.end(); It++)
    {
        std::cout << std::endl
                  << It->getNombre() << " tiene: ";
        std::cout << It->tamLVertices() << " vertices, ";
        std::cout << It->tamLVertices() + It->tamLCaras() - 2 << " aristas y ";
        std::cout << It->tamLCaras() << " caras" << std::endl;
    }
    std::list<Caja>::iterator It2;
    for (It2 = l_cajas.begin(); It2 != l_cajas.end(); It2++)
    {
        std::cout << std::endl
                  << It2->getNombre() << " tiene: ";
        std::cout << It2->tamLVertices() << " vertices, ";
        std::cout << It2->tamLVertices() + It2->tamLCaras() - 2 << " aristas y ";
        std::cout << It2->tamLCaras() << " caras" << std::endl;
    }
    std::cout << std::endl;
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
//Revisa si existe el objeto con nombre nom, en l_objetos
bool Sistema::buscarObjeto(std::string nom)
{
    std::list<Objeto>::iterator It;
    for (It = l_objetos.begin(); It != l_objetos.end(); It++)
    {
        if (It->getNombre() == nom)
        {
            return true;
        }
    }
    std::list<Caja>::iterator It2;
    for (It2 = l_cajas.begin(); It2 != l_cajas.end(); It2++)
    {
        if (It2->getNombre() == nom)
        {
            return true;
        }
    }
    return false;
}
//Carga el objeto del archivo arch, en la memoria
void Sistema::cargar(std::string arch)
{

    std::ifstream archivo(arch, std::ios::in);
    int tamV;
    int val = 0;
    Objeto obj;
    Vertice ver;
    std::string nomM;

    if (!archivo.is_open())
    {
        std::cout << "El archivo no existe o es ilegible." << std::endl;
    }
    else
    {
        archivo >> nomM >> tamV;
        if (buscarObjeto(nomM))
        {
            std::cout << "El objeto ya existe" << std::endl;
            archivo.close();
        }
        else
        {
            obj.setNombre(nomM);
            for (int j = 0; j < tamV; j++)
            {

                ver.setIndice(j);

                archivo >> val;
                ver.setPx(val);

                archivo >> val;
                ver.setPy(val);

                archivo >> val;
                ver.setPz(val);

                obj.agregarVertice(ver);
            }

            archivo >> val;
            while (val != -1)
            {
                Cara car;
                car.setTam(val);
                for (int i = 0; i < car.getTam(); i++)
                {
                    archivo >> val;
                    car.agregarIndice(val);
                }
                obj.agregarCara(car);
                archivo >> val;
            }

            agregarObjeto(obj);
        }
        std::cout << "El objeto " << obj.getNombre() << " ha sido cargado exitosamente del archivo " << arch << std::endl;

        archivo.close();
    }
}
//Crea una caja envolvente, agregando todos los objetos de memoria, y generando los vertices que la forman
void Sistema::envolvente(std::string nom)
{
    Caja caja;
    if (nom == "Todos")
    {
        caja.insertObjs(l_objetos);
    }
    else
    {
        Objeto aux;
        std::list<Objeto>::iterator It;
        std::list<Objeto>::iterator aux2;
        for (It = l_objetos.begin(); It != l_objetos.end(); It++)
        {
            if (It->getNombre() == nom)
            {
                aux = *It;
                aux2 = It;
            }
        }
        caja.insertObj(aux);
    }
    caja.calcularVertices();
    caja.crearVertices();
    caja.crearCaras();
    caja.setNombre("caja_" + std::to_string(l_cajas.size()));
    std::cout << std::endl
              << "Agregada la caja envolvente " << caja.getNombre() << " exitosamente" << std::endl;
    l_cajas.push_back(caja);
    std::cout << std::endl;
}
// Decarga el objeto de la memoria
bool Sistema::descargar(std::string nom)
{
    Objeto obj;
    std::list<Objeto>::iterator It;
    for (It = l_objetos.begin(); It != l_objetos.end(); It++)
    {
        if (It->getNombre() == nom)
        {
            l_objetos.erase(It);
            std::cout << "El objeto " << obj.getNombre() << " ha sido eliminado de la memoria de trabajo " << std::endl;
            return true;
        }
    }
    std::cout << "El objeto " << nom << " no ha sido cargado en memoria" << std::endl;
    return false;
}
//El objeto con nombre nom es guardado en e larchivo arch
void Sistema::guardar(std::string nom, std::string arch)
{
    bool encontrado = false;
    std::fstream file(arch, std::ios::app);
    if (!file.is_open())
    {
        std::cout << "El archivo indicado no existe o es erroneo el nombre" << std::endl;
    }
    else
    {
        Objeto obj;
        std::list<Objeto>::iterator It;
        for (It = l_objetos.begin(); It != l_objetos.end(); It++)
        {
            if (It->getNombre() == nom)
            {
                obj = *It;
                encontrado = true;
            }
        }
        if (encontrado)
        {
            file << obj.getNombre() << std::endl;
            file << obj.tamLVertices() << std::endl;
            for (int i = 0; i < obj.tamLVertices(); i++)
            {
                file << obj.infoVertice(i) << std::endl;
            }
            for (int i = 0; i < obj.tamLCaras(); i++)
            {
                file << obj.infoCara(i) << std::endl;
            }
            file << "-1" << std::endl;
            file.close();
        }
        else
        {
            Caja caj;
            std::list<Caja>::iterator It2;
            for (It2 = l_cajas.begin(); It2 != l_cajas.end(); It2++)
            {
                if (It2->getNombre() == nom)
                {
                    caj = *It2;
                }
            }
            file << caj.getNombre() << std::endl;
            file << caj.tamLVertices() << std::endl;
            for (int i = 0; i < caj.tamLVertices(); i++)
            {
                file << caj.infoVertice(i) << std::endl;
            }
            for (int i = 0; i < caj.tamLCaras(); i++)
            {
                file << caj.infoCara(i) << std::endl;
            }
            file << "-1" << std::endl;
            file.close();
        }
    }
}
void Sistema::v_cercano(std::string nom, float x, float y, float z)
{
    if (nom == "todos")
    {
        std::list<Objeto>::iterator It;
        float distancia, menor = 1000;
        punto mas_cercano;
        for (It = l_objetos.begin(); It != l_objetos.end(); It++)
        {
            NodoKD *cercano;
            ArbolKD arbol;
            std::list<Vertice> vertices = It->getVertices();
            std::list<Vertice>::iterator vert;
            for (vert = vertices.begin(); vert != vertices.end(); vert++)
            {
                punto nodo;
                nodo.indice = vert->getIndice();
                nodo.x = vert->getPx();
                nodo.y = vert->getPy();
                nodo.z = vert->getPz();
                arbol.insertar(nodo);
            }
            cercano = arbol.cercano(x, y, z);
            distancia = sqrt(pow(cercano->obtenerDato().x - x, 2) + pow(cercano->obtenerDato().y - y, 2) + pow(cercano->obtenerDato().z - z, 2));
            if (distancia < menor)
            {
                menor = distancia;
                mas_cercano = cercano->obtenerDato();
                nom = It->getNombre();
            }
        }
        std::list<Caja>::iterator It2;
        for (It2 = l_cajas.begin(); It2 != l_cajas.end(); It2++)
        {
            NodoKD *cercano;
            ArbolKD arbol;
            std::list<Vertice> vertices = It2->getVertices();
            std::list<Vertice>::iterator vert;
            for (vert = vertices.begin(); vert != vertices.end(); vert++)
            {
                punto nodo;
                nodo.indice = vert->getIndice();
                nodo.x = vert->getPx();
                nodo.y = vert->getPy();
                nodo.z = vert->getPz();
                arbol.insertar(nodo);
            }
            cercano = arbol.cercano(x, y, z);
            distancia = sqrt(pow(cercano->obtenerDato().x - x, 2) + pow(cercano->obtenerDato().y - y, 2) + pow(cercano->obtenerDato().z - z, 2));
            if (distancia < menor)
            {
                menor = distancia;
                mas_cercano = cercano->obtenerDato();
                nom = It2->getNombre();
            }
        }
        std::cout << "El vertice " << mas_cercano.indice << " " << mas_cercano << " del objeto " << nom << " es el mas cercano al punto (" << x << "," << y << "," << z << "), a una distancia de " << menor << std::endl;
    }
    else
    {
        bool encontradoObj = false, encontradoCaj = false;
        Objeto obj;
        Caja caj;
        std::list<Objeto>::iterator It;
        for (It = l_objetos.begin(); It != l_objetos.end(); It++)
        {
            if (It->getNombre() == nom)
            {
                obj = *It;
                encontradoObj = true;
            }
        }
        std::list<Caja>::iterator It2;
        for (It2 = l_cajas.begin(); It2 != l_cajas.end(); It2++)
        {
            if (It2->getNombre() == nom)
            {
                caj = *It2;
                encontradoCaj = true;
            }
        }
        ArbolKD arbol;
        std::list<Vertice> vertices;
        std::list<Vertice>::iterator vert;
        if (encontradoObj)
        {
            vertices = obj.getVertices();
        }
        if (encontradoCaj)
        {
            vertices = caj.getVertices();
        }
        for (vert = vertices.begin(); vert != vertices.end(); vert++)
        {
            punto nodo;
            nodo.indice = vert->getIndice();
            nodo.x = vert->getPx();
            nodo.y = vert->getPy();
            nodo.z = vert->getPz();
            arbol.insertar(nodo);
        }
        NodoKD *cercano;
        cercano = arbol.cercano(x, y, z);
        float c1 = cercano->obtenerDato().x - x, c2 = cercano->obtenerDato().y - y, c3 = cercano->obtenerDato().z - z;
        float distancia = sqrt(pow(c1, 2) + pow(c2, 2) + pow(c3, 2));
        std::cout << "El vertice " << cercano->obtenerDato().indice << " " << cercano->obtenerDato() << " del objeto " << nom << " es el mas cercano al punto (" << x << "," << y << "," << z << "), a una distancia de " << distancia << std::endl;
    }
}