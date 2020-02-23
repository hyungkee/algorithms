//
// Created by heuristy on 2020/02/23.
//

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../../disjoint-set/UnionFind.h"
#include "../WeightUndirectedGraph.h"
#include <vector>

using namespace std;

class Kruskal {
private:
    const WeightUndirectedGraph &graph;
public:
    Kruskal(const WeightUndirectedGraph &_graph) : graph(_graph) {}

    // O(ElogV)
    int minCost() {
        vector<iii> edges(graph.edges());
        sort(edges.begin(), edges.end());

        int mstCost = 0;
        UnionFind uf(graph.nodeCount());
        for (auto edge: edges) {
            if (!uf.isSameSet(edge.second.first, edge.second.second)) {
                mstCost += edge.first;
                uf.unionSet(edge.second.first, edge.second.second);
            }
        }
        return mstCost;
    }

};

#endif //KRUSKAL_H

/* Examples

#include <iostream>

#include "graph/WeightUndirectedGraph.h"
#include "graph/spanning-tree/Kruskal.h"

int main() {
    WeightUndirectedGraph graph(5);
    graph.link(0, 1, 4);
    graph.link(0, 2, 4);
    graph.link(0, 3, 6);
    graph.link(0, 4, 6);
    graph.link(1, 2, 2);
    graph.link(2, 3, 8);
    graph.link(3, 4, 9);

    cout << Kruskal(graph).minCost() << endl; // 18
    return 0;
}
 */