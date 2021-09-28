#include <iostream>
#include <vector>
#include "Graph.h"

int main()
{
    MatrixGraph<int, int> CLass;
    //CLass.randomGraph(5,5,0.25,100500,100500);
    CLass.addVertex(5);
    CLass.addVertex(5);
    CLass.addVertex(5);
    CLass.addVertex(5);
    CLass.addVertex(5);
    CLass.addEdge(0,1,5);
    CLass.addEdge(1,2,5);
    CLass.addEdge(2,3,5);
    CLass.addEdge(3,4,5);
    CLass.addEdge(0,3,5);
    std::cout<<CLass.getStringMatrix()<<std::endl;
    //CLass.addEdge(1,1,1);
    std::vector<unsigned> res = CLass.getRouteVertices(0,4);
    return 0;
}
