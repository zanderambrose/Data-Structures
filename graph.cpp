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
    bool addEdge(std::string v1, std::string v2)
    {
        if (adjList.count(v1) != 0 && adjList.count(v2) != 0)
        {
            adjList[v1].insert(v2);
            adjList[v2].insert(v1);
            return true;
        }
        return false;
    }
    bool removeEdge(std::string v1, std::string v2)
    {
        if (adjList.count(v1) != 0 && adjList.count(v2) != 0)
        {
            adjList[v1].erase(v2);
            adjList[v2].erase(v1);
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
            std::cout << "]" << std::endl;
        }
    }
};

int main()
{
    Graph *myGraph = new Graph();
    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");

    myGraph->addEdge("A", "B");
    myGraph->addEdge("A", "C");
    myGraph->addEdge("B", "C");
    myGraph->printGraph();

    myGraph->removeEdge("A", "B");
    myGraph->printGraph();
    return 0;
}