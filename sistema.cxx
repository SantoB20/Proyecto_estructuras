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
        std::cout << std::endl
                  << "Hay " << l_objetos.size() << " objeto en memoria" << std::endl;
    }
    else
    {
        std::cout << std::endl
                  << "Hay " << l_objetos.size() << " objetos en memoria" << std::endl;
    }
    std::list<Objeto>::iterator It;
    for (It = l_objetos.begin(); It != l_objetos.end(); It++)
    {
        std::cout << std::endl
                  << It->getNombre() << " tiene: ";
        std::cout << It->tamLVertices() << " vertices, ";
        std::cout << It->tamLVertices() / 2 << " aristas y ";
        std::cout << It->tamLCaras() << " caras" << std::endl;
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
//Revisa si existe el objeto en l_objetos, mediante el nombre indicado nom
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
    return false;
}
//Crea una caja envolvente, agregando todos los objetos de memoria, y generando los vertices que la forman
void Sistema::envolvente()
{
    Caja caja;
    caja.insertCajas(l_objetos);
    l_objetos.clear();
    caja.calcularVertices();
    caja.crearVertices();
    caja.setNombre("caja_" + std::to_string(l_cajas.size()));
    std::cout << std::endl
              << caja.tamLObjetos() << " objeto dentro de la caja" << std::endl;
    std::cout << std::endl
              << "Vertices: " << std::endl;
    caja.Impv();
    std::cout << std::endl
              << "Agregada la caja envolvente " << caja.getNombre() << " exitosamente" << std::endl;
    l_cajas.push_back(caja);
    std::cout << std::endl;
}
void Sistema::guardar(std::string nom, std::string arch)
{
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
            }
        }
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
}