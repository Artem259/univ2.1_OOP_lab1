#include <iostream>
#include <vector>
#include "Graph.h"

int main()
{
    MatrixGraph<int, int> CLass(10,10,0.75,100500,100500);
    std::cout<<CLass.getStringMatrix();
    return 0;
}
