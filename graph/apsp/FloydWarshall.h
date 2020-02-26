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
public:
    FloydWarshall(int _N) : N(_N), adjMat(_N) {
        for (int i = 0; i < N; i++) {
            adjMat[i].assign(N, INF);
            adjMat[i][i] = 0;
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
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
    }

    // O(1)
    int shortestPath(int i, int j) const {
        return adjMat[i][j];
    }
};

#endif //FLOYD_WARSHALL_H
