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
    vector<vector<ii>> adjList; // v, weight
    vector<iii> edgeList; // w, v1, v2
public:
    WeightDirectedGraph(int _N) : N(_N), adjList(_N) {}

    virtual void link(int i, int j, int w) {
        edgeList.emplace_back(w, ii(i, j));
        adjList[i].push_back(make_pair(j, w));
    }

    virtual inline const vector<ii> &adjusts(int i) const {
        return adjList[i];
    }

    virtual inline const vector<iii> &edges() const {
        return edgeList;
    }

    virtual inline int nodeCount() const {
        return N;
    }
};

#endif //WEIGHT_DIRECTED_GRAPH_H
