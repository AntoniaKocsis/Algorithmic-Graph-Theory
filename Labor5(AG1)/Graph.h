#include <iostream>
#include <vector>
#include <set>

using namespace std;
struct Edge {
    string node1;
    string node2;
    int weight;

};
struct Node {
    Edge edge;
    Node *next;

};

class Graph {
public:
    Node *head;
    set<string> nodes;
public:
    Graph(string filename);

    int nrNodes();

    int nrEdges() const;

    set<string> nodesList();

    void shortestPath(const string &startNode, const string &endNode);

    int getEdgeWeight(string n1, string n2);
    ~Graph();
};