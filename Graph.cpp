#include "Graph.h"

void Graph::addVertex(const char name){
    vertices.push_back(name);
}

void Graph::addEdge(const char u, const char v, const int weight){
    edges.push_back(make_pair(make_pair(u, v), weight));
}

void Graph::initializeDSU(){
for(char v : vertices){
    dsu.names[v] = make_pair(v, '\0');
    dsu.headers[v] = make_pair(1, v);
}
}

void Graph::fillQueue() {
    for (const auto &e : edges){
    sorted_edges.push(e);
    }
}

char Graph::findSet(const char v) const{
    return dsu.names.at(v).first;
}

void Graph::unionSets(const char& compA, const char& compB){
    if (dsu.headers[compA].first > dsu.headers[compB].first){
    char i = dsu.headers[compB].second;
    while (dsu.names[i].second != '\0'){
        dsu.names[i].first = compA;
        i = dsu.names[i].second;
    }
    dsu.names[i].first = compA;
    dsu.names[i].second = dsu.headers[compA].second;
    dsu.headers[compA].second = dsu.headers[compB].second;
    dsu.headers[compA].first += dsu.headers[compB].first;
    } else {
    char i = dsu.headers[compA].second;
    while (dsu.names[i].second != '\0'){
        dsu.names[i].first = compB;
        i = dsu.names[i].second;
    }
    dsu.names[i].first = compB;
    dsu.names[i].second = dsu.headers[compB].second;
    dsu.headers[compB].second = dsu.headers[compA].second;
    dsu.headers[compB].first += dsu.headers[compA].first;
    }
}

void Graph::runKruskal(){
    int components = vertices.size();
    initializeDSU();
    fillQueue();

    while (components > 1 && !sorted_edges.empty()){
        Edge e = sorted_edges.top();
        sorted_edges.pop();

        char u = e.first.first;
        char v = e.first.second;
        char compU = findSet(u);
        char compV = findSet(v);

        if (compU != compV){
            unionSets(compU, compV);
            mst_result.push_back(e);
            components--;
        }
    }
    cout << "\n=========================================" << endl;
    cout << "      MINIMUN SPANNING TREE (KRUSKAL) " << endl;
    cout << "=========================================" << endl;

    int total_cost = 0;
    for (const auto &res : mst_result){
        cout << " " << res.first.first << " <---> " << res.first.second << " [Weight: " << res.second << "]" << endl;
        total_cost += res.second;
    }
    cout << "----------------------------------------" << endl;
    cout << " TOTAL MST COST: " << total_cost << endl;
    cout << "========================================" << endl;
}

ostream& operator<<(ostream& os, const Graph& g){
os << "\n--- INITIAL GRAPH STATE ---\n";
os << "Vertices: ";
for (char v : g.vertices){
    os << "[" << v << "] ";
}
os <<"\nEdges:\n";
for (const auto &e : g.edges){
    os << " " << e.first.first << " --(" << e.second << ")-- " << e.first.second << "\n";
}
os << "-----------------------------------------\n";
return os;
}
