//
// Created by heuristy on 2020/02/23.
//

#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include "DirectedGraph.h"

class UndirectedGraph : public DirectedGraph {
public:
    UndirectedGraph(int _N) : DirectedGraph(_N) {}

    void link(int i, int j) override {
        DirectedGraph::link(i, j);
        DirectedGraph::link(j, i);
    }
};

#endif //UNDIRECTED_GRAPH_H
