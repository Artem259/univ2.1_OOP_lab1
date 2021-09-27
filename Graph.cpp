#include <vector>
#include <string>
#include <cassert>
#include "Graph.h"


template <class T_vertices, class T_edges>
VectorGraph<T_vertices, T_edges>::VectorGraph()
{
    verticesN = 0;
    vertices = {};
    edges = {};
}

template <class T_vertices, class T_edges>
VectorGraph<T_vertices, T_edges>::~VectorGraph()
{
    for(auto &row: edges)
    {
        for(auto &col: row)
        {
            delete col;
        }
    }
}

template <class T_vertices, class T_edges>
void VectorGraph<T_vertices, T_edges>::addVertex(T_vertices data)
{
    vertices.push_back(data);
    edges.push_back(std::vector<T_edges*> (edges.size()+1, nullptr));
    for(auto i = edges.begin(); i < edges.end()-1; i++)
    {
        (*i).push_back(nullptr);
    }
    verticesN++;
}

template <class T_vertices, class T_edges>
void VectorGraph<T_vertices, T_edges>::delVertex(unsigned vertex)
{
    assert(vertex<verticesN);
    vertices.erase(vertices.begin()+vertex); //erasing vertex (with data)
    //deleting data in all edges FROM vertex
    for(auto i = edges[vertex].begin(); i < edges[vertex].end(); i++)
    {
        delete (*i);
    }
    edges.erase(edges.begin()+vertex); //erasing row from the connectivity matrix
    //deleting data in all edges TO vertex, erasing column of the connectivity matrix
    for(auto i = edges.begin(); i < edges.end(); i++)
    {
        delete (*i)[vertex];
        (*i).erase((*i).begin()+vertex);
    }
    verticesN--;
}

template <class T_vertices, class T_edges>
void VectorGraph<T_vertices, T_edges>::addEdge(unsigned from, unsigned to, T_edges data)
{
    assert(from<verticesN && to<verticesN);
    assert(!edges[from][to]);
    edges[from][to] = new T_edges(data);
}

template <class T_vertices, class T_edges>
void VectorGraph<T_vertices, T_edges>::delEdge(unsigned from, unsigned to)
{
    assert(from<verticesN && to<verticesN);
    assert(edges[from][to]);
    delete edges[from][to];
    edges[from][to] = nullptr;
}

template <class T_vertices, class T_edges>
std::string VectorGraph<T_vertices, T_edges>::toString()
{
    std::string res;
    for(auto &row: edges)
    {
        for(auto &col: row)
        {
            if(col) res += "1 ";
            else res += "0 ";
        }
        res += "\n";
    }
    return res;
}

template <class T_vertices, class T_edges>
T_vertices& VectorGraph<T_vertices, T_edges>::operator()(unsigned vertex)
{
    assert(vertex<verticesN);
    return vertices[vertex];
}

template <class T_vertices, class T_edges>
T_edges& VectorGraph<T_vertices, T_edges>::operator()(unsigned from, unsigned to)
{
    assert(from<verticesN && to<verticesN);
    assert(edges[from][to]);
    return *edges[from][to];
}


template class VectorGraph<int, int>;
