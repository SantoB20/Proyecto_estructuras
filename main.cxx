//Autores: Santiago Burbano Puin, Oscar Esteban Vera Marulanda, Miguel Jose Durán López
#include <iostream>
#include <string.h>
#include "sistema.h"

using namespace std;

int main()
{
    Sistema sys;
    char comando[50], opcion[20];
    cout << "------------------" << endl;
    cout << "    Bienvenido" << endl;
    cout << "------------------" << endl;
    //Finaliza la prueba
    while (1)
    {
        char **parametros;
        int cant = 0;
        cout << "$ ";
        cin.getline(comando, 50);
        /*Cuenta la cantidad de parametros*/
        for (int i = 0; i < strlen(comando); i++)
        {
            if (comando[i] != ' ' && comando[i + 1] == ' ')
            {
                cant++;
            }
        }
        /*Extrae los parametros de la linea de comandos*/
        strcpy(opcion, strtok(comando, " "));
        if (cant > 0)
        {
            parametros = new char *[cant];
            for (int i = 0; i < cant; i++)
            {
                parametros[i] = strtok(NULL, " ");
            }
        }
        /*Empieza mirar el comando introducido, y las condiciones para que sea exitoso o no*/
        if (strcmp(opcion, "cargar") == 0)
        {
            if (cant == 1)
            {
                if (atoi(parametros[0]) == 0)
                {
                    string arch = parametros[0];
                   // cout << "Nombre del archivo: " << arch << endl;
                  //  cout << "Comando exitoso" << endl;
                    sys.cargar(arch);
                }
                else
                {
                    cout << "Error: introdujo un numero" << endl;
                }
            }
            else
            {
                cout << "Error: no intridujo ningun nombre de algun archivo" << endl;
            }
        }
        else if (strcmp(opcion, "listado") == 0)
        {
            if (sys.tamLObjetos() == 0)
            {
                cout << endl
                     << "Memoria vacia" << endl;
            }
            else
            {
                sys.listar();
            }
        }
        else if (strcmp(opcion, "envolvente") == 0)
        {
            if (cant == 0)
            {
                if (sys.tamLObjetos() == 0)
                {
                    cout << "Ningun objeto en memoria" << endl;
                }
                else
                {
                    sys.envolvente("Todos");
                }
            }
            if (cant == 1)
            {
                if (atoi(parametros[0]) == 0)
                {
                    string NomObjt = parametros[0];
                    if(!sys.buscarObjeto(NomObjt))
                    {
                        cout << NomObjt << " no esta cargado en memoria" << endl;
                    }
                    else
                    {
                        sys.envolvente(NomObjt);
                    }
                }
                else
                {
                    cout << "Error: no introdujo un nombre valido para el objeto" << endl;
                }
            }
            if (cant > 1)
            {
                cout << "Error: se introdujeron demasiados parametros" << endl;
            }
        }
        else if (strcmp(opcion, "descargar") == 0)
        {
            if (cant == 1)
            {
                if (atoi(parametros[0]) == 0)
                {
                    string NomObjt = parametros[0];
                   // cout << "Nombre del objeto: " << NomObjt << endl;
                   // cout << "Comando exitoso" << endl;
                   sys.descargar(NomObjt);
                }
                else
                {
                    cout << "Error: no introdujo un nombre valido para el objeto" << endl;
                }
            }
            if (cant > 1)
            {
                cout << "Error: se introdujeron demasiados parametros" << endl;
            }
            if (cant < 1)
            {
                cout << "Error: no introdujo ningun parametro" << endl;
            }
        }
        else if (strcmp(opcion, "guardar") == 0)
        {
            if (cant > 2)
            {
                cout << "Error: se introdujeron demasiados parametros" << endl;
            }
            if (cant < 2)
            {
                cout << "Error: se introdujeron muy pocos parametros" << endl;
            }
            else
            {
                if (cant == 2 && atoi(parametros[0]) == 0 && atoi(parametros[1]) == 0)
                {
                    string NomObjt = parametros[0];
                    string NomArch = parametros[1];
                    if (!sys.buscarObjeto(NomObjt))
                    {
                        cout << "El objeto indicado no esta cargado en memoria" << endl;
                    }
                    else
                    {
                        sys.guardar(NomObjt, NomArch);
                        cout << endl
                             << "Comando exitoso" << endl;
                    }
                }
                else
                {
                    cout << "Error: introdujo algun tipo de dato incorretamente" << endl;
                }
            }
        }
        else if (strcmp(opcion, "salir") == 0)
        {
            return 0;
        }

        else if (strcmp(opcion, "v_cercano") == 0)
        {
            if (cant > 4)
            {
                cout << "Error: se introdujeron demasiados parametros" << endl;
            }
            if (cant < 3)
            {
                cout << "Error: se introdujeron muy pocos parametros" << endl;
            }
            else
            {
                if (cant == 4 && atoi(parametros[0]) != 0 && atoi(parametros[1]) != 0 && atoi(parametros[2]) != 0 && atoi(parametros[3]) == 0)
                {
                    int px = atoi(parametros[0]), py = atoi(parametros[1]), pz = atoi(parametros[2]);
                    string nomobjt = parametros[3];
                    cout << "Nombre del objeto: " << nomobjt << endl
                         << "x: " << px << endl
                         << "y: " << py << endl
                         << "z: " << pz << endl;
                    cout << "Comando exitoso" << endl;
                }
                else
                {
                    if (cant == 3 && atoi(parametros[0]) != 0 && atoi(parametros[1]) != 0 && atoi(parametros[2]) != 0)
                    {
                        int px = atoi(parametros[0]), py = atoi(parametros[1]), pz = atoi(parametros[2]);
                        cout << "x: " << px << endl
                             << "y: " << py << endl
                             << "z: " << pz << endl;
                        cout << "Comando exitoso" << endl;
                    }
                    else
                    {
                        cout << "Error: introdujo algun tipo de dato incorretamente" << endl;
                    }
                }
            }
        }
        else if (strcmp(opcion, "v_cercanos_caja") == 0)
        {
            if (cant > 1)
            {
                cout << "Error: se introdujeron demasiados parametros" << endl;
            }
            if (cant < 1)
            {
                cout << "Error: se introdujeron muy pocos parametros" << endl;
            }
            else
            {
                if (cant == 1 && atoi(parametros[0]) == 0)
                {
                    string NomObjt = parametros[0];
                    cout << "Nombre del objeto: " << NomObjt << endl;
                    cout << "Comando exitoso" << endl;
                }
                else
                {
                    cout << "Error: no introdujo un nombre valido para el objeto" << endl;
                }
            }
        }
        else if (strcmp(opcion, "ruta_corta") == 0)
        {
            if (cant > 3)
            {
                cout << "Error: se introdujeron demasiados parametros" << endl;
            }
            if (cant < 3)
            {
                cout << "Error: se introdujeron muy pocos parametros" << endl;
            }
            else
            {
                if (cant == 3 && atoi(parametros[0]) != 0 && atoi(parametros[1]) != 0 && atoi(parametros[2]) == 0)
                {

                    int in1 = atoi(parametros[0]);
                    int in2 = atoi(parametros[1]);
                    string NomObjt = parametros[2];
                    cout << "Nombre del objeto: " << NomObjt << endl;
                    cout << "Indice 1: " << in1 << endl;
                    cout << "Indice 2: " << in2 << endl;
                    cout << "Comando exitoso" << endl;
                }
                else
                {
                    cout << "Error: introdujo algun tipo de dato incorretamente" << endl;
                }
            }
        }
        else if (strcmp(opcion, "ruta_corta_centro") == 0)
        {
            if (cant > 2)
            {
                cout << "Error: se introdujeron demasiados parametros" << endl;
            }
            if (cant < 2)
            {
                cout << "Error: se introdujeron muy pocos parametros" << endl;
            }
            else
            {
                if (cant == 2 && atoi(parametros[0]) != 0 && atoi(parametros[1]) == 0)
                {
                    int in1 = atoi(parametros[0]);
                    string NomObjt = parametros[1];
                    cout << "Nombre del objeto: " << NomObjt << endl;
                    cout << "Indice 1: " << in1 << endl;
                }
                else
                {
                    cout << "Error: introdujo un tipo de dato incorretamente" << endl;
                }
            }
        }
        else if (strcmp(opcion, "ayuda") == 0)
        {
            if (cant == 1 && atoi(parametros[0]) == 0)
            {
                char opcion2[20];

                strcpy(opcion2, parametros[0]);
                if (strcmp(opcion2, "cargar") == 0)
                {
                    cout << "cargar nombre_archivo:    Carga la información del objeto contenido en el archivo " << endl;
                }
                if (strcmp(opcion2, "listado") == 0)
                {
                    cout << "listado:    Muestra los objetos cargados, junto con la información básica de cada uno: cantidad de puntos, de aristas y de caras" << endl;
                }
                if (strcmp(opcion2, "envolvente") == 0)
                {
                    cout << "envolvente:  Calcula la caja envolvente del objeto. Esta caja envolvente se define a partir de dos puntos,pminypmax, los cuales determinan los límites de unaespecie de cuarto donde cabe el objeto completo, es decir, todos los vértices se encuentran dentro de la caja.pminypmaxse calculan como los puntos extremos, en cada dimensión, del conjuntode vértices que define el objeto." << endl
                         << "envolvente nombre_objeto: Calcula la caja envolvente del objeto identificado por nombre_objeto . Esta caja envolvente se define a partir de dos puntos, p min y p max , los cuales determinan los límites de una especie de cuarto donde cabe el objeto completo, es decir, todos los vértices se encuentran dentro de la caja. p min y p max se calculan como los puntos extremos, en cada dimensión, del conjunto de vértices que define el objeto. La caja envolvente se agrega como un nuevo objeto en memoria, asignándole automáticamente un nombre (el cual se informa al usuario) que la distinga de los demás objetos en memoria." << endl;
                }
                if (strcmp(opcion2, "descargar") == 0)
                {
                    cout << "descargar nombre_objeto:  Descarga toda la información básica (vértices, aristas, caras) del objeto." << endl;
                }
                if (strcmp(opcion2, "guardar") == 0)
                {
                    cout << "guardar nombre_objeto nombre_archivo:   Escribe en un archivo de texto, identificado por su nombre y la información básica (vértices y caras del objeto identificado" << endl;
                }
                if (strcmp(opcion2, "v_cercano") == 0)
                {
                    cout << "v_cercano px py pz:   Identifica el vértice del objeto más cercano (en términos de la distancia euclidiana) al punto indicado por las coordenadas px,py y pz. Informa en pantalla el índicedel vértice, los valores actuales de sus coordenadas, y la distancia a la cual se encuentra del punto dado" << endl
                         << "v_cercano px py pz nombre_ objeto:  Identifica los vértices del objetonombre_objetomás cercanos (en términos de ladistancia euclidiana) a los puntos (vértices) que definen la respectiva caja envolvente del objeto" << endl;
                }
                if (strcmp(opcion2, "v_cercanos_caja") == 0)
                {
                    cout << "v_cercanos_caja nombre_objeto:   dentifica los vértices del objetonombre_objetomás cercanos (en términos de ladistancia euclidiana) a los puntos (vértices) que definen la respectiva caja envolvente del obje" << endl;
                }
                if (strcmp(opcion2, "ruta_corta") == 0)
                {
                    cout << "ruta_corta i1 nombre_objeto: Identifica los índices de los vértices que conforman la ruta más corta entre los vérticesdados para el objeto. La distancia entre los vértices está medida en términos de la distancia euclidiana. Informa, además, la distancia total de la ruta calculada." << endl;
                }
                if (strcmp(opcion2, "ruta_corta_centro") == 0)
                {
                    cout << "ruta_corta_centro i1 nombre_objeto: Identifica los índices de los vértices que conforman la ruta más corta entre el vérticedado y el centro del objeto. El vértice centro del objeto se identifica calculando primero el centroide (coordenadas promedio) de todos los vértices del objeto, y buscando luego el vértice más cercano a ese centroide. La distancia entre los vértices está medida en términos de la distancia euclidiana. Informa, además, la distancia total de la ruta calculada" << endl;
                }
            }
            else
            {
                cout << "Lista de comandos: " << endl
                     << "    cargar" << endl
                     << "    listado" << endl
                     << "    envolvente" << endl
                     << "    descargar" << endl
                     << "    guardar" << endl
                     << "    v_cercano" << endl
                     << "    v_cercano_caja" << endl
                     << "    ruta_corta" << endl
                     << "    ruta_corta_centro" << endl
                     << "    ayuda comando" << endl
                     << "    salir" << endl;
            }
        }
        else
        {
            cout << "Comando no permitido" << endl;
        }
    }
}
