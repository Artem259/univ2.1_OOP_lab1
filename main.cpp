#include <iostream>
#include <vector>
#include "Graph.h"

void Test(unsigned iter)
{
    int seed=0;
    std::vector<std::vector<unsigned>> matrixGraphEdges;
    std::vector<std::vector<unsigned>> listGraphEdges;
    MatrixGraph<double, double> matrixGraph;
    ListGraph<double, double> listGraph;
    for(unsigned i=0; i<iter; i++)
    {
        std::cout<<"Test "<<i<<": ";
        switch(i%2)
        {
            case 0:
            {
                matrixGraph.randomGraph(3,10,0.5,0,0,seed);
                listGraph = matrixGraph;
                break;
            }
            case 1:
            {
                listGraph.randomGraph(3,10,0.5,0,0,seed);
                matrixGraph = listGraph;
                break;
            }
        }
        for(int j=0; j<2; j++)
        {
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
            matrixGraph.delVertex(0);
            listGraph.delVertex(0);
            matrixGraphEdges = matrixGraph.getEdges();
            listGraphEdges = listGraph.getEdges();
            if(matrixGraphEdges != listGraphEdges)
            {
                std::cout<<"FAILED [getEdges]\n";
                return;
            }
            if(!matrixGraphEdges.empty() && !listGraphEdges.empty())
            {
                matrixGraph.delEdge(matrixGraphEdges[0][0],matrixGraphEdges[0][1]);
                listGraph.delEdge(listGraphEdges[0][0],listGraphEdges[0][1]);
            }
        }
        seed++;
        matrixGraph.clear();
        listGraph.clear();
        std::cout<<"Completed.\n";
    }
    std::cout<<"\nTesting passed.\n";
}


int main()
{
    Test(10000);
    return 0;
}
