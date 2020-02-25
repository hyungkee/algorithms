//
// Created by heuristy on 2020/02/25.
//

#ifndef MODIFIABLE_GRAPH_H
#define MODIFIABLE_GRAPH_H

#include <vector>
#include <list>

using namespace std;

typedef pair<int, int> ii;

class ModifiableGraph {
private:
    int N;
    vector<list<ii>> adjList; // w, v
    vector<vector<list<ii>::iterator >> adjMat;

public:
    ModifiableGraph(int _N) : N(_N) {
        adjList.assign(N, list<ii>());
        adjMat.assign(N, vector<list<ii>::iterator>());
        for (int i = 0; i < N; i++) {
            adjMat[i].assign(N, adjList[i].end());
        }
    }

    int &weight(int i, int j) {
        return (*adjMat[i][j]).first;
    }

    bool existsEdge(int i, int j) {
        return adjMat[i][j] != adjList[i].end();
    }

    void setEdge(int i, int j, int w) {
        if (existsEdge(i, j)) {
            *adjMat[i][j] = ii(w, j);
        } else {
            adjList[i].emplace_back(w, j);
            adjMat[i][j] = --adjList[i].end();
        }
    }

    void deleteEdge(int i, int j) {
        if (existsEdge(i, j)) {
            adjList[i].erase(adjMat[i][j]);
            adjMat[i][j] = adjList[i].end();
        }
    }

    list<ii> &adjusts(int i) { return adjList[i]; }

    int nodeCount() { return N; }
};

#endif //MODIFIABLE_GRAPH_H
