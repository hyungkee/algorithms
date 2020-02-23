//
// Created by heuristy on 2020/02/23.
//

#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <vector>

using namespace std;

class DirectedGraph {
private:
    int N;
    vector<vector<int>> adjList; // node#
public:
    DirectedGraph(int _N) : N(_N), adjList(_N) {}

    virtual void link(int i, int j) {
        adjList[i].push_back(j);
    }

    virtual inline const vector<int> &adjusts(int i) const {
        return adjList[i];
    }

    virtual inline int nodeCount() const {
        return N;
    }
};

#endif //DIRECTED_GRAPH_H
