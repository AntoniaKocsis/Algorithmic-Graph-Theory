#include "Graph.h"
#include "GraphAdjListe.h"
#include<iostream>
#include<fstream>

using namespace std;

int main() {

//    Graph g;
//    cout<<g.isEdge(0,1)<<endl;
//    g.printGraph();
    GraphAdjListe g;
    cout << g.is_edge(0, 1) << endl;
    g.printGraph();
    cout << "Min grad " << g.min_grad() << endl;
    cout << "Max gard " << g.max_grad() << endl;


}