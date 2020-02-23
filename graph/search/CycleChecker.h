//
// Created by heuristy on 2020/02/23.
//

#ifndef CYCLE_CHECKER_H
#define CYCLE_CHECKER_H

#include "../UndirectedGraph.h"

class CycleChecker {
private:
    enum STATE {
        UNVISITED = 0, EXPLORED, VISITED
    };
    vector<int> states;
    vector<int> parents;
    const UndirectedGraph &g;

    bool checkCycleFrom(int i) {
        states[i] = EXPLORED;
        for (int j: g.adjusts(i)) {
            if (states[j] == UNVISITED) {
                parents[j] = i;
                if (checkCycleFrom(j)) {
                    return true;
                }
            } else if (states[j] == EXPLORED && parents[i] != j) {
                // Back Edge
                return true;
            } else if (states[j] == VISITED) {
                // Forward/Cross Edge
            }
        }
        states[i] = VISITED;
        return false;
    }

public:
    CycleChecker(const UndirectedGraph &_g) : g(_g) {}

    bool checkCycle() {
        int N = g.nodeCount();
        states.assign(N, UNVISITED);
        parents.assign(N, -1);
        for (int i = 0; i < N; i++) {
            if (checkCycleFrom(i)) {
                return true;
            }
        }
        return false;
    }
};

#endif //CYCLE_CHECKER_H

/* Examples
 *
#include <iostream>

#include "graph/UndirectedGraph.h"
#include "graph/CycleChecker.h"

int main() {
    UndirectedGraph graph(9);
    graph.link(0, 1);
    graph.link(1, 2);
    graph.link(1, 3);
    graph.link(2, 3);
    graph.link(3, 4);
    graph.link(6, 7);
    graph.link(6, 8);

    cout << CycleChecker(graph).checkCycle() << endl;
    return 0;
}

 */