#ifndef VECTOR_GRAPH_H
#define VECTOR_GRAPH_H

template <class T_vertices, class T_edges>
class VectorGraph
{
private:
    unsigned verticesN;
    std::vector<T_vertices> vertices; //data in vertices
    std::vector<std::vector<T_edges*>> edges; //!connectivity matrix!
public:
    VectorGraph(); //constructor
    ~VectorGraph(); //destructor
    void addVertex(T_vertices data); //add a new vertex
    void delVertex(unsigned vertex); //delete a vertex
    void addEdge(unsigned from, unsigned to, T_edges data); //add a new edge
    void delEdge(unsigned from, unsigned to); //delete an edge
    std::string toString(); //get a string representation (connectivity matrix)

    T_vertices& operator()(unsigned vertex); //get a reference to vertex
    T_edges& operator()(unsigned from, unsigned to); //get a reference to edge
    //T_vertices& operator =(unsigned vertex);
};

#endif
