//
// Created by heuristy on 2020/02/26.
//

#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "../WeightDirectedGraph.h"
#include <vector>

#define min(x, y) ((x)>(y)?(y):(x))

using namespace std;

class BellmanFord {
private:
    const int INF = 0x7FFFFFFF;
    vector<int> dist;
    WeightDirectedGraph &graph;
    int source;
    bool negativeCycle = false;
public:
    BellmanFord(WeightDirectedGraph &_graph, int _source)
            : graph(_graph), dist(_graph.nodeCount(), INF), source(_source) {
        dist[source] = 0;
    }

    // O(VE)
    void calcShortestPaths() {
        // N - 1 times Relax
        for (int i = 0; i < graph.nodeCount() - 1; i++)
            for (int v = 0; v < graph.nodeCount(); v++)
                if (dist[v] != INF)
                    for (auto wAndN: graph.adjusts(v))
                        dist[wAndN.second] = min(dist[wAndN.second], dist[v] + wAndN.first);

        // When more relaxing is possible it has negative cycle.
        negativeCycle = false;
        for (int v = 0; v < graph.nodeCount() && !negativeCycle; v++)
            if (dist[v] != INF)
                for (auto wAndN: graph.adjusts(v))
                    if (dist[wAndN.second] > dist[v] + wAndN.first) {
                        negativeCycle = true;
                        break;
                    }
    }

    // O(1)
    bool hasNegativeCycle() {
        return negativeCycle;
    }

    // O(1)
    int shortestPathTo(int i) {
        return dist[i];
    }

};

#endif //BELLMAN_FORD_H
