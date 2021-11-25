#include "Graph.h"
template <class T, class C>
std::vector<T> Graph<T, C>::getVertices()
{
    return this->vertices;
}
template <class T, class C>
std::vector<std::vector<C>> Graph<T, C>::getmatrizcostoo()
{
    return this->matrizcostoo;
}
template <class T, class C>
int Graph<T, C>::contarVertices()
{
    return this->vertices.size();
}
template <class T, class C>
int Graph<T, C>::contarAristas()
{
    int cont = 0;
    for (int i = 0; i < this->contarVertices(); i++)
    {
        for (int j = 0; j < this->contarVertices(); j++)
        {
            if (this->matrizcostoo[i][j] != 0)
                cont += this->matrizcostoo[i][j];
        }
    }
    return cont;
}
template <class T, class C>
bool Graph<T, C>::insertarVertice(T vertice)
{
    if (!this->buscarVertice(vertice))
    {
        this->vertices.push_back(vertice);
        std::vector<C> col;
        for (int i = 0; i < this->contarVertices(); i++)
            col.push_back(0);
        this->matrizcostoo.push_back(col);
        for (int i = 0; i < this->contarVertices(); i++)
        {
            if (this->matrizcostoo[i].size() < this->contarVertices())
                for (int j = contarVertices() - 1; j < this->contarVertices(); ++j)
                    this->matrizcostoo[i].push_back(0);
        }
        return true;
    }
    return false;
}
template <class T, class C>
bool Graph<T, C>::buscarVertice(T vertice)
{
    typename std::vector<T>::iterator it;
    for (it = this->vertices.begin(); it != this->vertices.end(); it++)
    {
        if (*it == vertice)
            return true;
    }
    return false;
}
template <class T, class C>
T Graph<T, C>::getVerticePorPosicion(long pos)
{
    for (int i = 0; i < this->contarVertices(); i++)
    {
        if (i == pos)
            return this->vertices[i];
    }
    return -1;
}
template <class T, class C>
int Graph<T, C>::getPosicionVertice(T vertice)
{
    for (int i = 0; i < this->contarVertices(); i++)
    {
        if (this->vertices[i] == vertice)
            return i;
    }
    return -1;
}
template <class T, class C>
bool Graph<T, C>::buscarArista(T origen, T destino)
{
    if (this->buscarVertice(origen) && this->buscarVertice(destino))
    {
        int i = this->getPosicionVertice(origen);
        int j = this->getPosicionVertice(destino);
        if (this->matrizcostoo[i][j] != 0)
            return true;
    }
    return false;
}
template <class T, class C>
C Graph<T, C>::getCostoArista(T origen, T destino)
{
    if (this->buscarArista(origen, destino))
    {
        int i = this->getPosicionVertice(origen);
        int j = this->getPosicionVertice(destino);
        return this->matrizcostoo[i][j];
    }
    return 0;
}
template <class T, class C>
bool Graph<T, C>::insertarArista(T origen, T destino, C costo)
{
    if (this->buscarVertice(origen) && this->buscarVertice(destino))
    {
        int i = this->getPosicionVertice(origen);
        int j = this->getPosicionVertice(destino);
        if (this->matrizcostoo[i][j] == 0)
        {
            this->matrizcostoo[i][j] = costo;
            return true;
        }
        else
            return false;
    }
    return false;
}
template <class T, class C>
void Graph<T, C>::print_matrizcostoo()
{
    std::cout << std::endl;
    for (int i = 0; i < this->matrizcostoo.size(); i++)
    {
        for (int j = 0; j < this->matrizcostoo[i].size(); j++)
            std::cout << "\t" << this->matrizcostoo[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
template <class T, class C>
bool Graph<T, C>::eliminarVertice(T vertice)
{
    int pos = this->getPosicionVertice(vertice);
    if (pos != -1)
    {
        this->matrizcostoo.erase(this->matrizcostoo.begin() + pos);
        for (int i = 0; i < this->matrizcostoo.size(); i++)
            this->matrizcostoo[i].erase(this->matrizcostoo[i].begin() + pos);
        this->vertices.erase(this->vertices.begin() + pos);
        return true;
    }
    return false;
}
template <class T, class C>
bool Graph<T, C>::eliminarArista(T origen, T destino)
{
    if (buscarArista(origen, destino))
    {
        int i = this->getPosicionVertice(origen);
        int j = this->getPosicionVertice(destino);
        this->matrizcostoo[i][j] = 0;
        return true;
    }
    return false;
}
template <class T, class C>
void Graph<T, C>::recorridoPlano()
{
    for (int j = 0; j < this->contarVertices() - 1; j++)
        std::cout << this->vertices[j] << ",";
    std::cout << this->vertices[this->contarVertices() - 1] << std::endl;
}
template <class T, class C>
int Graph<T, C>::gradoPorVertice(T vertice)
{
    int pos = this->getPosicionVertice(vertice), rt = 0;
    if (pos != -1)
    {
        for (int i = 0; i < this->contarVertices(); i++)
            if (this->matrizcostoo[pos][i] != 0)
                rt++;
    }
    else
        rt = -1;
    return rt;
}
template <class T, class C>
void Graph<T, C>::DFShelper(T v, bool *visitado)
{
    std::cout << v << " ";
    visitado[this->getPosicionVertice(v)] = true;
    for (int i = 0; i < this->contarVertices(); i++)
    {
        if (this->buscarArista(v, this->vertices[i]) && !visitado[i])
            this->DFShelper(this->vertices[i], visitado);
    }
}
template <class T, class C>
void Graph<T, C>::DFS(T begin)
{
    if (this->buscarVertice(begin))
    {
        bool visitado[this->contarVertices()];
        for (int i = 0; i < this->contarVertices(); i++)
            visitado[i] = 0;
        this->DFShelper(begin, visitado);
    }
    else
        std::cout << "vertice not found" << std::endl;
    std::cout << std::endl;
}
template <class T, class C>
void Graph<T, C>::BFS(T vec)
{

    if (this->buscarVertice(vec))
    {
        bool visitado[this->contarVertices()];
        for (int i = 0; i < this->contarVertices(); i++)
            visitado[i] = 0;
        std::queue<T> q;
        q.push(vec);
        while (!q.empty())
        {
            T v = q.front();
            q.pop();
            if (!visitado[this->getPosicionVertice(v)])
            {
                visitado[this->getPosicionVertice(v)] = true;
                std::cout << v << " ";
                for (int i = 0; i < this->contarVertices(); i++)
                    if (this->buscarArista(v, this->vertices[i]) && !visitado[i])
                        q.push(this->vertices[i]);
            }
        }
    }
    else
        std::cout << "vertice no encontrado" << std::endl;
    std::cout << std::endl;
}
template <class T, class C>
std::vector<std::pair<T, C>> Graph<T, C>::getAdyacentePorVertice(T vertice)
{
    std::vector<std::pair<T, C>> rt;
    if (this->buscarVertice(vertice))
    {
        for (int j = 0; j < this->contarVertices(); j++)
        {
            if (this->matrizcostoo[getPosicionVertice(vertice)][j] != 0)
            {
                std::pair<T, C> pair = std::make_pair(this->vertices[j], getCostoArista(vertice, this->vertices[j]));
                rt.push_back(pair);
            }
        }
    }
    return rt;
}
template <class T, class C>
C Graph<T, C>::prim(T origen, T destino)
{
    
    C costoo[this->contarAristas()];
    bool visitado[this->contarAristas()];
    std::priority_queue<std::pair<C, T>, std::vector<std::pair<C, T>>, std::greater<std::pair<C, T>>> pq;
    if (this->buscarVertice(origen))
    for (int i = 0; i < this->contarAristas(); i++)
        {
            costoo[i] = INF;
            visitado[i] = false;
        }
    costoo[this->contarAristas()] = 0;
    pq.push(std::make_pair(costoo[get(origen)], origen));
    int min = 9999;
    while (!pq.empty())
    {
        std::pair<C, T> p = pq.top();
        T u = p.second;
        pq.pop();
        for (int i = 0; i < this->contarVertices(); i++) 
        {
            if(this->buscarVertice(origen) && (costoo[this->contarAristas()] < ))
            {
                costoo[i]= min;
                visitado[i] = i;
            }
        }   
    }
    return costoo[this->getCostoArista(destino)]
}
template <class T, class C>
C Graph<T, C>::dijkstra(T origen, T dest)
{
    C dist[this->contarVertices()];
    bool visitado[this->contarVertices()];
    std::priority_queue<std::pair<C, T>, std::vector<std::pair<C, T>>, std::greater<std::pair<C, T>>> pq;
    if (this->buscarVertice(origen))
    {
        for (int i = 0; i < this->contarVertices(); i++)
        {
            dist[i] = INF;
            visitado[i] = false;
        }
        dist[getPosicionVertice(origen)] = 0;
        pq.push(std::make_pair(dist[getPosicionVertice(origen)], origen));
        //std::cout << dist[getPosicionVertice(origen)] << std::endl;
        while (!pq.empty())
        {
            std::pair<C, T> p = pq.top();
            T u = p.second;
            pq.pop();
            if (visitado[getPosicionVertice(u)] == false)
            {
                visitado[getPosicionVertice(u)] == true;
                typename std::vector<std::pair<T, C>>::iterator it;
                for (it = this->getAdyacentePorVertice(u).begin(); it != this->getAdyacentePorVertice(u).end(); it++)
                {
                    T v = it->first;
                    C costo = it->second;
                    if (dist[getPosicionVertice(v)] > (dist[getPosicionVertice(u)] + costo))
                    {
                        std::cout << v << "-> ";
                        dist[getPosicionVertice(v)] = dist[getPosicionVertice(u)] + costo;
                        pq.push(std::make_pair(dist[getPosicionVertice(v)], v));
                    }
                }
                std::cout << std::endl;
            }
        }
    }
    std::cout << dist[this->getPosicionVertice(dest)] << std::endl;
    return dist[this->getPosicionVertice(dest)];
}