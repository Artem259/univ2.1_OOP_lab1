#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <cassert>
#include <stack>
#include <ctime>
#include <queue>
#include "Graph.h"

template <class T_vertices, class T_edges>
bool MatrixGraph<T_vertices, T_edges>::DFS(unsigned start, const std::vector<std::vector<bool>> &matrix)
{
    auto visited = new bool[verticesN]{false};
    std::stack<unsigned> stack;
    stack.push(start);
    unsigned curr;
    while(!stack.empty())
    {
        curr = stack.top();
        stack.pop();
        if(!visited[curr])
        {
            visited[curr] = true;
            for(unsigned i=0; i<verticesN; i++)
            {
                if(matrix[curr][i]) stack.push(i);
            }
        }
    }
    for(unsigned i=0; i<verticesN; i++)
    {
        if(!visited[i])
        {
            delete []visited;
            return false;
        }
    }
    delete []visited;
    return true;
}

template <class T_vertices, class T_edges>
std::vector<unsigned*> MatrixGraph<T_vertices, T_edges>::BFS(unsigned start, unsigned end, const std::vector<std::vector<bool>> &matrix)
{
    std::vector<unsigned*> prev{verticesN,nullptr};
    auto visited = new bool[verticesN]{false};
    std::queue<unsigned> queue;
    visited[start] = true;
    queue.push(start);
    unsigned curr;
    while(!queue.empty())
    {
        curr = queue.front();
        queue.pop();
        for(unsigned i=0; i<verticesN; i++)
        {
            if(matrix[curr][i] && !visited[i])
            {
                visited[i] = true;
                queue.push(i);
                prev[i] = new unsigned{curr};
                if(i==end) return prev;
            }
        }
    }
    return prev;
}

template <class T_vertices, class T_edges>
MatrixGraph<T_vertices, T_edges>::MatrixGraph()
{
    verticesN = 0;
    vertices = {};
    edges = {};
}

template <class T_vertices, class T_edges>
MatrixGraph<T_vertices, T_edges>::~MatrixGraph()
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
void MatrixGraph<T_vertices, T_edges>::randomGraph(unsigned minVertices, unsigned maxVertices,
                                                   double edgeProb, T_vertices verticesData, T_edges edgesData)
{
    assert(minVertices<=maxVertices);
    assert(edgeProb>=0 && edgeProb<=1);
    this->clear();
    std::mt19937 mt(time(nullptr)*1);
    std::uniform_int_distribution<unsigned> randInt(minVertices, maxVertices);
    std::uniform_real_distribution<double> randDouble(0, 1);
    unsigned n = randInt(mt);
    double isEdge;
    for(unsigned i=0; i<n; i++)
    {
        addVertex(verticesData);
    }
    for(unsigned i=0; i<verticesN; i++)
    {
        for(unsigned j=0; j<verticesN; j++)
        {
            isEdge = randDouble(mt);
            if(isEdge<edgeProb)
            {
                addEdge(i, j, edgesData);
            }
        }
    }
}

template <class T_vertices, class T_edges>
void MatrixGraph<T_vertices, T_edges>::addVertex(T_vertices data)
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
void MatrixGraph<T_vertices, T_edges>::delVertex(unsigned vertex)
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
void MatrixGraph<T_vertices, T_edges>::addEdge(unsigned from, unsigned to, T_edges data)
{
    assert(from<verticesN && to<verticesN);
    assert(!edges[from][to]);
    edges[from][to] = new T_edges(data);
}

template <class T_vertices, class T_edges>
void MatrixGraph<T_vertices, T_edges>::delEdge(unsigned from, unsigned to)
{
    assert(from<verticesN && to<verticesN);
    assert(edges[from][to]);
    delete edges[from][to];
    edges[from][to] = nullptr;
}

template <class T_vertices, class T_edges>
void MatrixGraph<T_vertices, T_edges>::clear()
{
    while(verticesN>0)
    {
        this->delVertex(verticesN-1);
    }
}

template <class T_vertices, class T_edges>
bool MatrixGraph<T_vertices, T_edges>::checkEdge(unsigned from, unsigned to)
{
    assert(from<verticesN && to<verticesN);
    if(edges[from][to]) return true;
    return false;
}

template <class T_vertices, class T_edges>
unsigned MatrixGraph<T_vertices, T_edges>::size()
{
    return verticesN;
}

template <class T_vertices, class T_edges>
std::vector<std::vector<bool>> MatrixGraph<T_vertices, T_edges>::getMatrix()
{
    std::vector<std::vector<bool>> res;
    for(auto &row: edges)
    {
        res.emplace_back();
        for(auto &col: row)
        {
            if(col) res.back().push_back(true);
            else res.back().push_back(false);
        }
    }
    return res;
}

template <class T_vertices, class T_edges>
std::string MatrixGraph<T_vertices, T_edges>::getStringMatrix()
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
bool MatrixGraph<T_vertices, T_edges>::stronglyConnected()
{
    assert(verticesN>0);
    auto matrix = this->getMatrix();
    if(!DFS(0, matrix)) return false;
    for(unsigned i=0; i<verticesN; i++)
    {
        for(unsigned  j=i+1; j<verticesN; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    if(!DFS(0, matrix)) return false;
    return true;
}

template <class T_vertices, class T_edges>
bool MatrixGraph<T_vertices, T_edges>::weaklyConnected()
{
    assert(verticesN>0);
    auto matrix = this->getMatrix();
    for(unsigned i=0; i<verticesN; i++)
    {
        for(unsigned  j=i+1; j<verticesN; j++)
        {
            matrix[i][j] = matrix[i][j] || matrix[j][i];
            matrix[j][i] = matrix[i][j];
        }
    }
    if(!DFS(0, matrix)) return false;
    return true;
}

template <class T_vertices, class T_edges>
std::vector<unsigned> MatrixGraph<T_vertices, T_edges>::getRouteVertices(unsigned from, unsigned to)
{
    assert(from!=to);
    std::vector<unsigned> route;
    std::vector<unsigned*> prev = this->BFS(from, to, this->getMatrix());
    unsigned curr;
    if(prev[to])
    {
        route.push_back(to);
        curr = *prev[to];
        while(curr!=from)
        {
            route.push_back(curr);
            curr = *prev[curr];
        }
        route.push_back(from);
    }
    for(auto &i: prev) delete i;
    std::reverse(route.begin(), route.end());
    return route;
}

template <class T_vertices, class T_edges>
unsigned MatrixGraph<T_vertices, T_edges>::getRouteLength(unsigned from, unsigned to)
{
    unsigned length = (this->getRouteVertices(from,to)).size();
    if(length==0) return 0;
    return length-1;
}

template <class T_vertices, class T_edges>
T_vertices& MatrixGraph<T_vertices, T_edges>::operator()(unsigned vertex)
{
    assert(vertex<verticesN);
    return vertices[vertex];
}

template <class T_vertices, class T_edges>
T_edges& MatrixGraph<T_vertices, T_edges>::operator()(unsigned from, unsigned to)
{
    assert(from<verticesN && to<verticesN);
    assert(edges[from][to]);
    return *edges[from][to];
}


template class MatrixGraph<int, int>;
template class ListGraph<int, int>;
