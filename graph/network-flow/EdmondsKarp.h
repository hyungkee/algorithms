//
// Created by heuristy on 2020/02/23.
//

#ifndef EDMONDS_KARP_H
#define EDMONDS_KARP_H

#include <queue>
#include "../WeightUndirectedGraph.h"

class EdmondsKarp {
private:
    const int INF = 0x7FFFFFFF;
    const WeightUndirectedGraph &graph;
    int source, sink;
    vector<vector<int>> flows;
    int maxFlow = 0;
public:
    EdmondsKarp(const WeightUndirectedGraph &_graph, int _source, int _sink)
            : graph(_graph), source(_source), sink(_sink) {}

    // O(VE^2)
    void calcFlows() {
        flows.assign(graph.nodeCount(), vector<int>());
        for (int i = 0; i < graph.nodeCount(); i++) {
            flows[i].assign(graph.nodeCount(), 0);
        }

        while (true) {
            vector<int> weights(graph.nodeCount(), 0);
            vector<int> parents(graph.nodeCount(), -1);
            vector<bool> visit(graph.nodeCount(), 0);
            queue<int> q;
            q.push(source);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                if (v == sink) break;
                for (auto wAndI: graph.adjusts(v)) {
                    int w = wAndI.first;
                    int next = wAndI.second;
                    if (w - flows[v][next] > 0 && !visit[next]) {
                        weights[next] = w - flows[v][next];
                        parents[next] = v;
                        visit[next] = true;
                        q.push(next);
                    }
                }
            }

            if (parents[sink] == -1) break;

            int flow = INF;
            for (int i = sink; i != source; i = parents[i]) {
                flow = min(flow, weights[i]);
            }

            for (int i = sink; i != source; i = parents[i]) {
                flows[parents[i]][i] += flow;
                flows[i][parents[i]] -= flow;
            }
            maxFlow += flow;
        }
    }

    int getMaxFlow() { return maxFlow; }

    int getFlow(int i, int j) { return flows[i][j]; }
};

#endif //EDMONDS_KARP_H
