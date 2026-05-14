#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef pair<pair<char, char>, int> Edge;

struct DSU_Structure {
    map<char, pair<char, char>> names;
    map<char, pair<int, char>> headers;
};

class MinWeight {
public:
    bool operator() (const Edge& a1, const Edge& a2) const {
        return a1.second > a2.second;
    }
};

class Graph {
private:
    vector<char> vertices;
    vector<Edge> edges;
    DSU_Structure dsu;
    priority_queue<Edge, vector<Edge>, MinWeight> sorted_edges;
    vector<Edge> mst_result;

public:
    void addVertex(const char name);
    void addEdge(const char u, const char v, const int weight);
    void initializeDSU();
    void fillQueue();
    char findSet(char v) const;
    void unionSets(const char& compA, const char& compB);
    void runKruskal();

friend ostream& operator<<(ostream& os, const Graph& g);
};

#endif
