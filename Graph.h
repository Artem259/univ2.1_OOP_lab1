#ifndef VECTOR_GRAPH_H
#define VECTOR_GRAPH_H

template <class T_vertices, class T_edges>
class MatrixGraph
{
private:
    unsigned verticesN;
    std::vector<T_vertices> vertices; //data in vertices
    std::vector<std::vector<T_edges*>> edges; //!connectivity matrix!

    bool DFS(unsigned start, const std::vector<std::vector<bool>> &matrix);
public:
    MatrixGraph(); //empty constructor
    ~MatrixGraph(); //destructor
    void randomGraph(unsigned minVertices, unsigned maxVertices, double edgeProb, T_vertices verticesData, T_edges edgesData);
            //fill graph with random number of vertices and random edges
    void addVertex(T_vertices data); //add a new vertex
    void delVertex(unsigned vertex); //delete a vertex
    void addEdge(unsigned from, unsigned to, T_edges data); //add a new edge
    void delEdge(unsigned from, unsigned to); //delete an edge
    void clear(); //cleans the graph
    bool checkEdge(unsigned from, unsigned to); //checks if there's an edge in the graph
    unsigned size(); //returns the number of vertices in the graph
    std::vector<std::vector<bool>> getMatrix(); //returns a bool representation of adjacency matrix
    std::string getStringMatrix(); //return a string representation of adjacency matrix
    bool stronglyConnected(); //checks if the graph is strongly connected
    bool weaklyConnected(); //checks if the graph is weakly connected

    T_vertices& operator()(unsigned vertex); //get a reference to vertex
    T_edges& operator()(unsigned from, unsigned to); //get a reference to edge
};


template <class T_vertices, class T_edges>
class ListGraph
{
private:


public:


};

#endif
