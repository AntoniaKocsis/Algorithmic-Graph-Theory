#include "Adjazenz_liste.h"
#include "Kanten_liste.h"
using namespace std;

int main() {
    AdjazenzListe graph("adjazenz_liste.txt");
    graph.print_graph();

}