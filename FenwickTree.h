//
// Created by heuristy on 2020/02/19.
//

#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<int> ft;

    static int LSOne(int num) {
        return num & (-num);
    }

    int rangeSumQueryTo(int i) {
        int sum = 0;
        for (; i; i -= LSOne(i)) {
            sum += ft[i];
        }
        return sum;
    }

public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }

    int rangeSumQuery(int i, int j) {
        return rangeSumQueryTo(j) - (i == 1 ? 0 : rangeSumQueryTo(i));
    }

    /* index starts from 1 */
    void adjust(int index, int delta) {
        for (; index < ft.size(); index += LSOne(index)) {
            ft[index] += delta;
        }
    }

};

#endif //FENWICK_TREE_H
