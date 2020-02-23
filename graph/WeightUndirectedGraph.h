//
// Created by heuristy on 2020/02/23.
//

#ifndef WEIGHT_UNDIRECTED_GRAPH_H
#define WEIGHT_UNDIRECTED_GRAPH_H

#include "WeightDirectedGraph.h"

class WeightUndirectedGraph : public WeightDirectedGraph {
public:
    WeightUndirectedGraph(int _N) : WeightDirectedGraph(_N) {}

    void link(int i, int j, int w) override {
        WeightDirectedGraph::link(i, j, w);
        WeightDirectedGraph::link(j, i, w);
    }
};

#endif //WEIGHT_UNDIRECTED_GRAPH_H
