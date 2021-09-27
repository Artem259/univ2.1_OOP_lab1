#include <iostream>
#include <vector>
#include "Graph.h"

int main()
{
    MatrixGraph<int, int> CLass;
    CLass.addVertex(0);
    CLass.addVertex(0);
    CLass.addVertex(0);
    CLass.addVertex(0);
    CLass.addVertex(0);
    CLass.addVertex(0);
    CLass.addVertex(0);
    CLass.addEdge(0,1,0);
    CLass.addEdge(1,2,0);
    CLass.addEdge(2,3,0);
    CLass.addEdge(3,4,0);
    CLass.addEdge(4,5,0);
    CLass.addEdge(5,6,0);
    CLass.addEdge(6,3,0);
    std::cout<<CLass.DFS(0, CLass.getMatrix());
    return 0;
}
