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
    CLass(0,2)++;
    CLass(0,2)=CLass(0,0)-CLass(0,1)+CLass(0,2)+CLass(2);
    std::cout<< CLass(0,2);
    return 0;
}
