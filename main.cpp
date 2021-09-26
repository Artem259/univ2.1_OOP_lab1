#include <iostream>
#include <vector>
#include "Graph.h"

int main()
{
    VectorGraph<int, int> CLass;
    CLass.addVertex(4);
    VectorGraph<int, int> CLass2;
    CLass2 = CLass;
    CLass(0)++;
    return 0;
}
