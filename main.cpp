#include <iostream>
#include <vector>
#include "Graph.h"

void Test(unsigned iter)
{
    MatrixGraph<double, double> matrixGraph;
    ListGraph<double, double> listGraph;
    for(unsigned i=0; i<iter; i++)
    {
        std::cout<<"Test "<<i<<": ";
        switch(i%2)
        {
            case 0:
            {
                matrixGraph.randomGraph(2,10,0.33,0,0);
                listGraph = matrixGraph;
                break;
            }
            case 1:
            {
                listGraph.randomGraph(2,10,0.33,0,0);
                matrixGraph = listGraph;
                break;
            }
        }
        if(matrixGraph.size() != listGraph.size())
        {
            std::cout<<"FAILED [size]\n";
            return;
        }
        if(matrixGraph.checkEdge(0, matrixGraph.size()-1) != listGraph.checkEdge(0, matrixGraph.size()-1))
        {
            std::cout<<"FAILED [checkEdge]\n";
            return;
        }
        if(matrixGraph.getRouteLength(0, matrixGraph.size()-1) != listGraph.getRouteLength(0, listGraph.size()-1))
        {
            std::cout<<"FAILED [getRouteLength]\n";
            return;
        }
        if(matrixGraph.getRouteVertices(0, matrixGraph.size()-1) != listGraph.getRouteVertices(0, listGraph.size()-1))
        {
            std::cout<<"FAILED [getRouteVertices]\n";
            return;
        }
        if(matrixGraph.weaklyConnected() != listGraph.weaklyConnected())
        {
            std::cout<<"FAILED [weaklyConnected]\n";
            return;
        }
        if(matrixGraph.stronglyConnected() != listGraph.stronglyConnected())
        {
            std::cout<<"FAILED [stronglyConnected]\n";
            return;
        }
        std::cout<<"Completed.\n";
    }
}


int main()
{
    Test(100);
    return 0;
}
