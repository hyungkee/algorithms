//
// Created by heuristy on 2020/02/18.
//

#ifndef UNION_FIND_H
#define UNION_FIND_H

#include<vector>

using namespace std;

class UnionFind {
private:
    vector<int> rank, parent;

public:
    UnionFind(int n) {
        rank.assign(n, 0);
        parent.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int root(int i) {
        return (parent[i] == i) ? i : (parent[i] = root(parent[i]));
    }

    bool isSameSet(int i, int j) {
        return root(i) == root(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int rootI = root(i);
            int rootJ = root(j);
            if (rank[rootI] > rank[rootJ]) {
                parent[rootJ] = rootI;
            } else {
                parent[rootI] = rootJ;
                if (rank[rootI] == rank[rootJ]) {
                    rank[rootJ]++;
                }
            }
        }
    }
};


#endif UNION_FIND_H
