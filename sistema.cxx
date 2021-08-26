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
        std::cout << It->tamLVertices() + It->tamLCaras() / 2 << " aristas y ";
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

//Carga el objeto del archivo en la memoria
void Sistema::cargar(std::string arch)
{
   
   std::ifstream archivo(arch, std::ios::in);
   int tamC,tamV;
   int val = 0;
   Objeto obj;
   Vertice ver;
   Cara car;
   std::string nomM;
   int cont=1;

   if(!archivo.is_open())
   {
       std::cout<<"El archivo no existe o es ilegible."<< std::endl;
   }
   else
   {
     archivo >> nomM >>tamV;
      if(buscarObjeto(nomM))
        {
           std::cout<< "El objeto ya existe"<<std::endl;
           archivo.close();
        }
        else
            {
             obj.setNombre(nomM);
             for (int j = 0; j <  tamV ; j++)
               {
                
                ver.setIndice(j);
                
                ver.setPx(val);
                archivo>>val;
                
                ver.setPy(val);
                archivo>>val; 
                
                ver.setPz(val);
                archivo>>val;
                
                obj.agregarVertice(ver);
                
              
               }
                  
               archivo>>val;                   
               while(val != -1)
                {
                  tamC=val;
                  car.setTam(cont);

                  for(int i = 0 ; i<tamC; i++)
                  {
                      car.agregarIndice(ver.getIndice());
                      archivo>>val;

                  }
                  obj.agregarCara(car);
                  archivo>>val;
                  cont++;
                 }
                
              agregarObjeto(obj);
       }
              std::cout<<"El objeto "<< obj.getNombre()<< " ha sido cargado exitosamente del archivo "<< arch<< std::endl;
      
               archivo.close();
   } 
}
//Crea una caja envolvente, agregando todos los objetos de memoria, y generando los vertices que la forman
void Sistema::envolvente(std::string nom)
{
    Caja caja;
    if(nom == "Todos")
    {
        caja.insertObjs(l_objetos);
        l_objetos.clear();
    }
    else
    {
        Objeto aux;
        std::list<Objeto>::iterator It;
        std::list<Objeto>::iterator aux2;
        for(It=l_objetos.begin();It!=l_objetos.end();It++)
        {
            if(It->getNombre()==nom)
            {
                aux= *It;
                aux2 = It;
            }
        }
        caja.insertObj(aux);
        l_objetos.erase(aux2);
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
                std::cout<<"El objeto "<< obj.getNombre()<< " ha sido eliminado de la memoria de trabajo "<< std::endl;
                return true;
            }
        }
        std::cout<<"El objeto "<< nom<< " no ha sido cargado en memoria"<<std::endl;
        return false;
        
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
