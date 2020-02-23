//
// Created by heuristy on 2020/02/23.
//

#ifndef WEIGHT_DIRECTED_GRAPH_H
#define WEIGHT_DIRECTED_GRAPH_H

#include <vector>

using namespace std;

typedef pair<int, int> ii;

class WeightDirectedGraph {
protected:
    int N;
    vector<vector<ii>> adjList; // node#, weight
public:
    WeightDirectedGraph(int _N) : N(_N), adjList(_N) {}

    virtual void link(int i, int j, int weight) {
        adjList[i].push_back(make_pair(j, weight));
    }

    virtual inline const vector<ii> &adjusts(int i) const {
        return adjList[i];
    }

    virtual inline int nodeCount() const {
        return N;
    }
};

#endif //WEIGHT_DIRECTED_GRAPH_H
