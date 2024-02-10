#include "Graph.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "GraphAdjListe.h"

using namespace std;

GraphAdjListe::GraphAdjListe() {

    ifstream f;
    f.open("data.in");
    f >> n;
    f >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        f >> x >> y;
        add_edge(x, y);


    }

}

void GraphAdjListe::add_edge(int x, int y) {
    adj_liste[x].push_back(y);
    adj_liste[y].push_back(x);
}

bool GraphAdjListe::is_edge(int x, int y) {
    for (int i = 0; i <= adj_liste[x].size(); i++)
        if (adj_liste[x][i] == y)
            return true;
    return false;


}

void GraphAdjListe::printGraph() {
    for (int i = 0; i < n; i++) {
        cout << "Nod: " << i << " Lista vecini: ";
        for (int j = 0; j < adj_liste[i].size(); j++) {
            cout << adj_liste[i][j] << " ";
        }
        cout << endl;
    }
}

int GraphAdjListe::max_grad() {
    int maxi = 0;
    for (int i = 0; i < n; i++)
        if (adj_liste[i].size() > maxi)
            maxi = adj_liste[i].size();


    return maxi;
}

int GraphAdjListe::min_grad() {
    int min = 999999;
    for (int i = 0; i < n; i++)
        if (adj_liste[i].size() < min)
            min = adj_liste[i].size();

    return min;
}