#include <iostream>
#include <vector>
#include "Graph.h"
#include "Geometry.h"

bool TestRandomGraph(unsigned iter)
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
                return false;
            }
            if(matrixGraph.checkEdge(0, matrixGraph.size()-1) != listGraph.checkEdge(0, matrixGraph.size()-1))
            {
                std::cout<<"FAILED [checkEdge]\n";
                return false;
            }
            if(matrixGraph.getRouteLength(0, matrixGraph.size()-1) != listGraph.getRouteLength(0, listGraph.size()-1))
            {
                std::cout<<"FAILED [getRouteLength]\n";
                return false;
            }
            if(matrixGraph.getRouteVertices(0, matrixGraph.size()-1) != listGraph.getRouteVertices(0, listGraph.size()-1))
            {
                std::cout<<"FAILED [getRouteVertices]\n";
                return false;
            }
            if(matrixGraph.weaklyConnected() != listGraph.weaklyConnected())
            {
                std::cout<<"FAILED [weaklyConnected]\n";
                return false;
            }
            if(matrixGraph.stronglyConnected() != listGraph.stronglyConnected())
            {
                std::cout<<"FAILED [stronglyConnected]\n";
                return false;
            }
            matrixGraph.delVertex(0);
            listGraph.delVertex(0);
            matrixGraphEdges = matrixGraph.getEdges();
            listGraphEdges = listGraph.getEdges();
            if(matrixGraphEdges != listGraphEdges)
            {
                std::cout<<"FAILED [getEdges]\n";
                return false;
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
        std::cout<<"Passed.\n";
    }
    std::cout<<"\nSection: Passed.\n";
    return true;
}
bool LineAndLine()
{
    std::vector<Line> l1, l2;
    std::vector<Point> res;

    l1.emplace_back(2,3,-5);
    l2.emplace_back(3,5,-4);
    res.push_back({13,-7});

    l1.emplace_back(-6,2,5);
    l2.emplace_back(3,5,-4);
    res.push_back({0.917,0.25});

    l1.emplace_back(0,2,5);
    l2.emplace_back(3,0,-4);
    res.push_back({1.333,-2.5});

    l1.emplace_back(-1,-1,5);
    l2.emplace_back(6.5,-4,50);
    res.push_back({-2.857,7.857});

    l1.emplace_back(0,1,0);
    l2.emplace_back(1,0,5);
    res.push_back({-5,0});

    l1.emplace_back(-60,1,58);
    l2.emplace_back(60,1,-59);
    res.push_back({0.975, 0.5});

    l1.emplace_back(-1,1,0);
    l2.emplace_back(1,1,0);
    res.push_back({0, 0});

    Point currRes;
    size_t len = res.size();
    for(size_t i=0; i<len; i++)
    {
        std::cout<<"Test "<<i<<": ";
        currRes = l1[i] && l2[i];
        if(!(round(currRes.x*1000)/1000==res[i].x && round(currRes.y*1000)/1000==res[i].y))
        {
            std::cout<<"FAILED\n";
            return false;
        }
        std::cout<<"Passed.\n";
    }
    std::cout<<"\nSection: Passed.\n";
    return true;
}
bool LineAndCircle()
{
    std::vector<Line> l;
    std::vector<Circle> c;

    std::vector<std::vector<Point>> res;
    l.emplace_back(-60,1,58);
    c.push_back({{4,3},5});
    res.push_back({{1.084,7.062}, {0.951,-0.962}});

    bool isFound;
    std::vector<Point> currRes;
    size_t len = res.size();
    for(size_t i=0; i<len; i++)
    {
        std::cout<<"Test "<<i<<": ";
        currRes = l[i] && c[i];
        if(res[i].size()!=currRes.size())
        {
            std::cout<<"FAILED [size]\n";
            return false;
        }
        for(auto &currResI: currRes)
        {
            isFound = false;
            for(auto &resI: res[i])
            {
                if(round(currResI.x*1000)/1000==resI.x && round(currResI.y*1000)/1000==resI.y)
                {
                    isFound = true;
                    break;
                }
            }
            if(!isFound)
            {
                std::cout<<"FAILED [value]\n";
                return false;
            }
        }
        std::cout<<"Passed.\n";
    }
    std::cout<<"\nSection: Passed.\n";
    return true;
}


void Test()
{
    std::cout<<"\n--------------------------------\n";
    std::cout<<"Section 1 [RandomGraphs]:\n\n";
    if(!TestRandomGraph(10)) return;
    std::cout<<"--------------------------------\n";
    std::cout<<"Section 2 [Line && Line]:\n\n";
    if(!LineAndLine()) return;
    std::cout<<"--------------------------------\n";
    std::cout<<"Section 2 [Line && Circle]:\n\n";
    if(!LineAndCircle()) return;
    std::cout<<"--------------------------------\n";
}


int main()
{
    Test();
    return 0;
}
