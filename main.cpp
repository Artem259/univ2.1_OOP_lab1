#include <iostream>
#include <vector>
#include "Graph.h"

int main()
{
    MatrixGraph<int, int> CLass(11,11,0.5,21,100);

    std::cout<<CLass.getStringMatrix();
    return 0;
}
