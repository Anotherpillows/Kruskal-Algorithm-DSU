#include "Graph.h"

int main(){
    Graph myGraph;
    char u, v;
    int weight;

    cout << "--- VERTEX LOADING ---" << endl;
    cout << "Enter vertex names (one char), Enter (*) to stop: " << endl;
    while (cin >> u && u != '*'){
        myGraph.addVertex(u);
    }

    cout << "--- EDGE LOADING ---" << endl;
    cout << "Enter Origin, Destination and Weight (e.g., A B 10). Enter (*) to stop: " << endl;
    while (cin >> u && u != '*'){
        cin >> v >> weight;
        myGraph.addEdge(u, v, weight);
    }

    cout << myGraph << endl;

    myGraph.runKruskal();

    return 0;
}
