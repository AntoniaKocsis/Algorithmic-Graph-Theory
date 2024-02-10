#include <iostream>
#include "Graph.h"
void printGraph(){
    Graph graph("date.in");
    Node *current = graph.head;
    while (current != nullptr) {
        cout<<current->edge.node1<<" "<<current->edge.node2<<" "<<current->edge.weight<<endl;
        current = current->next;
    }
}
void printNodes(){
    Graph graph("date.in");
    set<string> nodes = graph.nodes;
    for (const auto& str : nodes) {
        cout << str << endl;
    }
}
int main() {
    //printGraph();
    //printNodes();
    Graph graph("date.in");
    graph.shortestPath("Suceava","Sibiu");

    return 0;
}
