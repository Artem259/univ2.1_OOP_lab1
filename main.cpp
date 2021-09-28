#include <iostream>
#include <vector>
#include "Graph.h"

double a()
{
    return 0.1;
}
int b()
{
    return 1;
}

int main()
{
    MatrixGraph<double, int> CLass(0,10,0.5,a,b);

    std::cout<<CLass.size()<<"\n";
    return 0;
}
