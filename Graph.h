#ifndef VECTOR_GRAPH_H
#define VECTOR_GRAPH_H

template <class T_vertices, class T_edges>
class MatrixGraph
{
private:
    unsigned verticesN;
    std::vector<T_vertices> vertices; //data in vertices
    std::vector<std::vector<T_edges*>> edges; //!connectivity matrix!
public:
    MatrixGraph(); //constructor
    ~MatrixGraph(); //destructor
    void addVertex(T_vertices data); //add a new vertex
    void delVertex(unsigned vertex); //delete a vertex
    void addEdge(unsigned from, unsigned to, T_edges data); //add a new edge
    void delEdge(unsigned from, unsigned to); //delete an edge
    bool checkEdge(unsigned from, unsigned to); //checks if there's an edge in the graph
    unsigned size(); //returns the number of vertices in the graph
    std::vector<std::vector<bool>> getMatrix(); //returns a bool representation of adjacency matrix
    std::string getStringMatrix(); //return a string representation of adjacency matrix

    T_vertices& operator()(unsigned vertex); //get a reference to vertex
    T_edges& operator()(unsigned from, unsigned to); //get a reference to edge
};

#endif
