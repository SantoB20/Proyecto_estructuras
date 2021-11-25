#ifndef _GRAPH_H_
#define _GRAPH_H_
#define INF 10000000
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <utility>
#include <list>
#include <map>
template <class T, class C>
class Graph
{
private:
    std::vector<T> vertices;
    std::vector<std::vector<C>> matrizcostoo;

protected:
    ;
    void DFShelper(T, bool *);
    void relajacion(T, T, C);

public:
    std::vector<T>getVertices();
    std::vector<std::pair<T, C>> getAdyacentePorVertice(T);
    std::vector<std::vector<C>> getmatrizcostoo();
    int contarVertices();
    int contarAristas();
    bool insertarVertice(T);
    bool buscarVertice(T);
    bool buscarArista(T, T);
    bool eliminarArista(T, T);
    C getCostoArista(T, T);
    T getVerticePorPosicion(long);
    int getPosicionVertice(T);
    bool insertarArista(T, T, C);
    bool eliminarVertice(T);
    int gradoPorVertice(T);
    void DFS(T);
    void BFS(T);
    void recorridoPlano();
    void print_matrizcostoo();
    //TODO prim
    //*prim get the minimum possible value
    //Shortes way in the graph
    C prim(T, T);
    C dijkstra(T, T);
};
#include "Graph.hxx"
#endif