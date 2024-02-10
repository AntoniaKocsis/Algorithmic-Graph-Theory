#include "Graph.h"
#include <fstream>
#include <sstream>
#include <limits>
#include <map>
#include <deque>

Graph::Graph(string filename) {
    ifstream file(filename);
    head = nullptr;
    Edge edge;

    while (file >> edge.node1 >> edge.node2 >> edge.weight) {
        nodes.insert(edge.node1);
        nodes.insert(edge.node2);
        Node *newNode = new Node;
        newNode->edge = edge;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *current = head;
            Node *previous = nullptr;
            while (current != nullptr) {
                previous = current;
                current = current->next;
            }
            previous->next = newNode;
        }
    }
    file.close();
}

int Graph::nrEdges() const {
    if (head == nullptr)
        return 0;
    Node *current = head;
    int size = 0;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}

int Graph::nrNodes() {
    return nodes.size();
}

set<string> Graph::nodesList() {
    return nodes;
}

int Graph::getEdgeWeight(string n1, string n2) {
    Node *current = head;
    while (current != nullptr) {
        if (current->edge.node1 == n1 && current->edge.node2 == n2)
            return current->edge.weight;
        else if (current->edge.node2 == n1 && current->edge.node1 == n2)
            return current->edge.weight;
        current = current->next;
    }
    return -999;
}

void Graph::shortestPath(const string &city1, const string &city2) {


    std::map<string, int> shortestDistance;
    std::map<string, string> previousCity;
    // Initialize the distances and previous
    Node *currentNode = head;
    while (currentNode != nullptr) {
        Edge edge = currentNode->edge;
        shortestDistance[edge.node1] = INT_MAX;
        shortestDistance[edge.node2] = INT_MAX;
        previousCity[edge.node1] = "";
        previousCity[edge.node2] = "";
        currentNode = currentNode->next;
    }

    // Set the distance of the starting node to 0
    shortestDistance[city1] = 0;

    // Relax edges repeatedly
    //A simple shortest path from source to any other node can have at most nrNodes - 1 edges
    for (int i = 0; i < nodes.size() - 1; i++) {
        currentNode = head;
        while (currentNode != nullptr) {
            const Edge &edge = currentNode->edge;
            int u = shortestDistance[edge.node1];
            int v = shortestDistance[edge.node2];
            int weight = edge.weight;
            if (u != INT_MAX && u + weight < v) {
                shortestDistance[edge.node2] = u + weight;
                previousCity[edge.node2] = edge.node1;
            }
            if (v != INT_MAX && v + weight < u) {
                shortestDistance[edge.node1] = v + weight;
                previousCity[edge.node1] = edge.node2;
            }
            currentNode = currentNode->next;
        }
    }

    // Check for negative cycles
    currentNode = head;
    while (currentNode != nullptr) {
        const Edge &edge = currentNode->edge;
        int u = shortestDistance[edge.node1];
        int v = shortestDistance[edge.node2];
        int weight = edge.weight;
        if (u != INT_MAX && u + weight < v) {
            cout << "Graph contains negative cycle" << endl;
            return;
        }
        if (v != INT_MAX && v + weight < u) {
            cout << "Graph contains negative cycle" << endl;
            return;
        }
        currentNode = currentNode->next;
    }

    // Check if a path exists between the two cities
    if (previousCity[city2].empty()) {
        cout << "No path exists between " << city1 << " and " << city2 << endl;
        return;
    }

    // Find all the nodes that create the path
    deque<string> path;
    string currentCity = city2;
    int totalWeight = 0;
    while (!currentCity.empty()) {
        path.push_front(currentCity);
        if(!previousCity[currentCity].empty())
        totalWeight+= getEdgeWeight(currentCity,previousCity[currentCity]);
        currentCity = previousCity[currentCity];
    }

    cout << "Shortest path from " << city1 << " to " << city2 << ": ";
    for (const auto &city: path) {
        cout << city << " ";
    }
    cout << '\n';
    cout << totalWeight;

}
Graph::~Graph() {
    Node *current = head;
    Node *next = nullptr;
    while(current != nullptr){
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}