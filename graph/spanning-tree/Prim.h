//
// Created by heuristy on 2020/02/23.
//

#ifndef PRIM_H
#define PRIM_H

#include <queue>
#include <functional>
#include "../WeightUndirectedGraph.h"

class Prim {
private:
    const WeightUndirectedGraph &graph;
public:
    Prim(const WeightUndirectedGraph &_graph) : graph(_graph) {}

    // O(ElogV)
    int minCost() {
        int cost = 0;
        vector<bool> taken(graph.nodeCount(), false);
        priority_queue <ii, vector<ii>, greater<>> pq; // 오름차순
        pq.push(ii(0, 0)); // 임의로 0번을 시작점으로 잡는다.
        while (!pq.empty()) {
            ii wAndI = pq.top();
            pq.pop();
            if (taken[wAndI.second])
                continue;
            taken[wAndI.second] = true;
            cost += wAndI.first;
            for (ii wAndJ: graph.adjusts(wAndI.second)) {
                if (!taken[wAndJ.second]) {
                    pq.push(wAndJ);
                }
            }
        }
        return cost;
    }
};

#endif //PRIM_H

/* Examples

#include <iostream>

#include "graph/WeightUndirectedGraph.h"
#include "graph/spanning-tree/Prim.h"

int main() {
    WeightUndirectedGraph graph(5);
    graph.link(0, 1, 4);
    graph.link(0, 2, 4);
    graph.link(0, 3, 6);
    graph.link(0, 4, 6);
    graph.link(1, 2, 2);
    graph.link(2, 3, 8);
    graph.link(3, 4, 9);

    cout << Prim(graph).minCost() << endl; // 18
    return 0;
}
 */