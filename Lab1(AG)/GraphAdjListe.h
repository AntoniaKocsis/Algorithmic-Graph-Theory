#include <vector>

using namespace std;

class GraphAdjListe {
private:

    int n;
    int m;
    vector<int> adj_liste[100];

public:

    GraphAdjListe();

    void add_edge(int x, int y);

    bool is_edge(int x, int y);

    void printGraph();

    int max_grad();

    int min_grad();


};