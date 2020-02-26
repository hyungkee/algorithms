//
// Created by heuristy on 2020/02/26.
//

#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include <vector>

#define min(x, y) ((x)>(y)?(y):(x))

using namespace std;

class FloydWarshall {
private:
    const int INF = 1000000000; // '2 * INF < INT_MAX' to avoid overflow.
    const int N;
    vector<vector<int>> adjMat;
    vector<vector<int>> parents;
    bool cycle = false;
    bool negativeCycle = false;
public:
    FloydWarshall(int _N) : N(_N), adjMat(_N) {
        for (int i = 0; i < N; i++) {
            parents[i].assign(N, i);
            adjMat[i].assign(N, INF);
        }
    }

    // O(1)
    void link(int i, int j, int w) {
        adjMat[i][j] = w;
    }

    // O(N^3)
    void calcShortestPaths() {
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) {
                        adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                        parents[i][j] = parents[k][j];
                    }

        cycle = negativeCycle = false;
        for (int i = 0; i < N; i++) {
            if (adjMat[i][i] != INF)
                cycle = true;
            if (adjMat[i][i] < 0)
                negativeCycle = true;
        }
    }

    // O(1)
    int shortestPath(int i, int j) const {
        return adjMat[i][j];
    }

    // O(N)
    void routeOfShortestPath(int i, int j, vector<int> &routeOutput) const {
        if (i != j) routeOfShortestPath(i, parents[i][j], routeOutput);
        routeOutput.push_back(j);
    }

    // O(1)
    bool hasNegativeCycle() {
        return negativeCycle;
    }

    // O(1)
    bool hasCycle() {
        return cycle;
    }
};

#endif //FLOYD_WARSHALL_H
