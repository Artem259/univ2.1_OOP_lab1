#include <iostream>
#include <vector>
#include "Graph.h"

int main()
{
    VectorGraph<int, int> CLass;
    CLass.addVertex(10);
    CLass.addVertex(11);
    CLass.addVertex(12);
    CLass.addEdge(0,2,100);
    CLass.addEdge(0,1,200);
    CLass.addEdge(0,0,300);
    CLass.addEdge(1,1,100);
    CLass.addEdge(1,2,100);
    auto resBool = CLass.getMatrix();
    auto resString = CLass.getStringMatrix();
    return 0;
}
