//
// Created by heuristy on 2020/02/23.
//

#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <vector>

using namespace std;
typedef pair<int, int> ii;

class DirectedGraph {
protected:
    int N;
    vector<vector<int>> adjList; // v
    vector<ii> edgeList; // v1, v2
public:
    DirectedGraph(int _N) : N(_N), adjList(_N) {}

    virtual void link(int i, int j) {
        edgeList.emplace_back(i, j);
        adjList[i].push_back(j);
    }

    virtual inline vector<int> &adjusts(int i) {
        return adjList[i];
    }

    virtual inline vector<ii> &edges() {
        return edgeList;
    }

    virtual inline int nodeCount() const {
        return N;
    }
};

#endif //DIRECTED_GRAPH_H
