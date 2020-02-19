//
// Created by heuristy on 2020/02/18.
//

#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> A;
    vector<int> rmqSt;
    vector<int> rsqSt;

    int left(int p) { return p << 1; }

    int right(int p) { return (p << 1) + 1; }

    void calculateSt(int p) {
        int rmq1 = rmqSt[left(p)];
        int rmq2 = rmqSt[right(p)];
        rmqSt[p] = (A[rmq1] > A[rmq2]) ? rmq2 : rmq1;
        rsqSt[p] = rsqSt[left(p)] + rsqSt[right(p)];
    }

    void buildRange(int p, int L, int R, int i, int j) {
        if (L == R) {
            rmqSt[p] = L;
            rsqSt[p] = A[L];
        } else {
            if (j < L || R < i) return;
            buildRange(left(p), L, (L + R) / 2, i, j);
            buildRange(right(p), (L + R) / 2 + 1, R, i, j);
            calculateSt(p);
        }
    }

    void buildAll(int p, int L, int R) {
        buildRange(p, L, R, L, R);
    }

    int rangeMinQuery(int p, int L, int R, int i, int j) {
        if (j < L || R < i) return -1;
        if (i <= L && R <= j) return rmqSt[p];

        int rmq1 = rangeMinQuery(left(p), L, (L + R) / 2, i, j);
        int rmq2 = rangeMinQuery(right(p), (L + R) / 2 + 1, R, i, j);
        if (rmq1 == -1) return rmq2;
        if (rmq2 == -1) return rmq1;
        return (A[rmq1] > A[rmq2]) ? rmq2 : rmq1;
    }

    int rangeSumQuery(int p, int L, int R, int i, int j) {
        if (j < L || R < i) return 0;
        if (i <= L && R <= j) return rsqSt[p];

        int rsq1 = rangeSumQuery(left(p), L, (L + R) / 2, i, j);
        int rsq2 = rangeSumQuery(right(p), (L + R) / 2 + 1, R, i, j);
        return rsq1 + rsq2;
    }

public:
    SegmentTree(const vector<int> &_A) {
        A = _A;
        n = A.size();
        rmqSt.assign(4 * n, 0);
        rsqSt.assign(4 * n, 0);
        buildAll(1, 0, n - 1);
    }

    int rangeMinQuery(int i, int j) {
        return rangeMinQuery(1, 0, n - 1, i, j);
    }

    int rangeSumQuery(int i, int j) {
        return rangeSumQuery(1, 0, n - 1, i, j);
    }

    void update(int index, int num) {
        A[index] = num;
        buildRange(1, 0, n - 1, index, index);
    }

    void updateRange(int i, int j, int num) {
        for (int index = i; index <= j; index++) {
            A[index] = num;
        }
        buildRange(1, 0, n - 1, i, j);
    }
};

#endif //SEGMENT_TREE_H
