//
// Created by heuristy on 2020/02/23.
//

#ifndef WEIGHT_DIRECTED_GRAPH_H
#define WEIGHT_DIRECTED_GRAPH_H

#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

class WeightDirectedGraph {
protected:
    int N;
    vector<vector<ii>> adjList; // w, v
    vector<iii> edgeList; // w, v1, v2
public:
    WeightDirectedGraph(int _N) : N(_N), adjList(_N) {}

    virtual void link(int i, int j, int w) {
        edgeList.emplace_back(w, ii(i, j));
        adjList[i].push_back(ii(w, j));
    }

    // w, j
    virtual inline vector<ii> &adjusts(int i) {
        return adjList[i];
    }

    // w, (i, j)
    virtual inline vector<iii> &edges() {
        return edgeList;
    }

    virtual inline int nodeCount() const {
        return N;
    }
};

#endif //WEIGHT_DIRECTED_GRAPH_H
