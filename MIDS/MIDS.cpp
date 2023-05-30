#include <iostream>
#include "Graph.h"

int main()
{
    // Just testing some functions for now
    std::string const path = "Datasets/DIMACS/johnson8-2-4.mis";
    Graph * const graph = new Graph(path);
    graph->removeVertex(2);
    graph->printGraphInfo();
    std::cout << graph->getMaxDegreeVertex() << std::endl;
    return 0;
}