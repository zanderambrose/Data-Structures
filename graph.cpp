#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Graph
{
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList;

public:
    bool addVertex(std::string vertex)
    {
        if (adjList.count(vertex) == 0)
        {
            adjList[vertex];
            return true;
        }
        return false;
    }
    void printGraph()
    {
        for (auto [vertex, edges] : adjList)
        {
            std::cout << vertex << ": [";
            for (auto edge : edges)
            {
                std::cout << edge << ", ";
            }
            std::cout << " ]" << std::endl;
        }
    }
};

int main()
{
    Graph *myGraph = new Graph();
    myGraph->addVertex("A");
    myGraph->printGraph();
    return 0;
}