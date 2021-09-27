#include <iostream>
#include <vector>
#include "Graph.h"

int main()
{
    MatrixGraph<int, int> CLass;
    CLass.addVertex(10);
    CLass.addVertex(11);
    CLass.addVertex(12);
    CLass.addEdge(0,2,100);
    CLass.addEdge(0,1,200);
    CLass.addEdge(0,0,300);
    CLass.addEdge(1,1,100);
    std::cout<< CLass.checkEdge(0,2)<<std::endl;
    std::cout<< CLass.checkEdge(0,1)<<std::endl;
    std::cout<< CLass.checkEdge(0,0)<<std::endl;
    std::cout<< CLass.checkEdge(1,1)<<std::endl;
    std::cout<< CLass.checkEdge(1,2)<<std::endl;
    std::cout<< CLass.size();
    return 0;
}
