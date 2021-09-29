#ifndef VECTOR_GRAPH_H
#define VECTOR_GRAPH_H


template <class T_vertices, class T_edges>
class MatrixGraph;
template <class T_vertices, class T_edges>
class ListGraph;


template <class T_vertices, class T_edges>
class MatrixGraph
{
private:
    unsigned verticesN;
    std::vector<T_vertices> vertices; //data in vertices
    std::vector<std::vector<T_edges*>> edges; //!connectivity matrix!

    std::vector<std::vector<bool>> getMatrix(); //returns copy of adjacency matrix (to change)
    bool DFS(unsigned start, const std::vector<std::vector<bool>> &matrix);
    std::vector<unsigned*> BFS(unsigned start, unsigned end);
public:
    MatrixGraph(); //empty constructor
    explicit MatrixGraph(ListGraph<T_vertices, T_edges> &toCopy); //copy constructor
    ~MatrixGraph(); //destructor
    void addVertex(T_vertices data); //add a new vertex
    void delVertex(unsigned vertex); //delete a vertex
    void addEdge(unsigned from, unsigned to, T_edges data); //add a new edge
    void delEdge(unsigned from, unsigned to); //delete an edge
    void clear(); //cleans the graph
    bool checkEdge(unsigned from, unsigned to); //checks if there's an edge in the graph
    unsigned size(); //returns the number of vertices in the graph
    std::vector<std::vector<unsigned>> getEdges(); //return all edges in graph
    std::string getString(); //return a string representation of adjacency matrix
    void randomGraph(unsigned minVertices, unsigned maxVertices, double edgeProb, T_vertices verticesData, T_edges edgesData);
            //fill graph with random number of vertices and random edges
    bool stronglyConnected(); //checks if the graph is strongly connected
    bool weaklyConnected(); //checks if the graph is weakly connected
    std::vector<unsigned> getRouteVertices(unsigned from, unsigned to); //returns vertices chain between 2 vertices [from-->to]
    unsigned getRouteLength(unsigned from, unsigned to); //returns number of edges between 2 vertices (or 0, if disconnected)

    T_vertices& operator()(unsigned vertex); //get a reference to vertex
    T_edges& operator()(unsigned from, unsigned to); //get a reference to edge
    MatrixGraph& operator=(ListGraph<T_vertices, T_edges> &toCopy);
};

template <class T_vertices, class T_edges>
class ListGraph
{
private:
    struct edge
    {
        unsigned vertex;
        T_edges* data;
    };
    unsigned verticesN;
    std::vector<T_vertices> vertices; //data in vertices
    std::vector<std::vector<edge>> edges; //!connectivity list!

    std::vector<std::vector<unsigned>> getList(); //returns copy of adjacency list (to change)
    bool DFS(unsigned start, const std::vector<std::vector<unsigned>> &list);
    std::vector<unsigned*> BFS(unsigned start,  unsigned end);
public:
    ListGraph(); //empty constructor
    explicit ListGraph(MatrixGraph<T_vertices, T_edges> &toCopy); //copy constructor
    ~ListGraph(); //destructor
    void addVertex(T_vertices data); //add a new vertex
    void delVertex(unsigned vertex); //delete a vertex
    void addEdge(unsigned from, unsigned to, T_edges data); //add a new edge
    void delEdge(unsigned from, unsigned to); //delete an edge
    void clear(); //cleans the graph
    bool checkEdge(unsigned from, unsigned to); //checks if there's an edge in the graph
    unsigned size(); //returns the number of vertices in the graph
    std::vector<std::vector<unsigned>> getEdges(); //return all edges in graph
    std::string getString(); //return a string representation of adjacency list
    void randomGraph(unsigned minVertices, unsigned maxVertices, double edgeProb, T_vertices verticesData, T_edges edgesData);
            //fill graph with random number of vertices and random edges
    bool stronglyConnected(); //checks if the graph is strongly connected
    bool weaklyConnected(); //checks if the graph is weakly connected
    std::vector<unsigned> getRouteVertices(unsigned from, unsigned to); //returns vertices chain between 2 vertices [from-->to]
    unsigned getRouteLength(unsigned from, unsigned to); //returns number of edges between 2 vertices (or 0, if disconnected)

    T_vertices& operator()(unsigned vertex); //get a reference to vertex
    T_edges& operator()(unsigned from, unsigned to); //get a reference to edge
    ListGraph& operator=(MatrixGraph<T_vertices, T_edges> &toCopy);
};


#endif
