//
// Created by heuristy on 2020/02/22.
//

#ifndef BIPARTITE_MATCHING_H
#define BIPARTITE_MATCHING_H

#include<vector>

using namespace std;

class BipartiteMatching {
private:
    int N, M;
    vector<vector<int> > adjList;
    vector<bool> visitedA;
    vector<int> matchedA, matchedB;

    bool visitA(int ai) {
        if (visitedA[ai]) {
            return false;
        }
        visitedA[ai] = true;
        for (int bi: adjList[ai]) {
            if (matchedB[bi] == -1 || visitA(matchedB[bi])) {
                matchedB[bi] = ai;
                matchedA[ai] = bi;
                return true;
            }
        }
        return false;
    }

public:
    BipartiteMatching(int _N, int _M, vector<vector<int> > &_adjList) : N(_N), M(_M), adjList(_adjList) {
        matchedA.assign(N, -1);
        matchedB.assign(N, -1);
    }

    int matchAndGetMax() {
        int matches = 0;
        for (int ai = 0; ai < N; ai++) {
            visitedA.assign(N, false);
            if (visitA(ai)) {
                matches++;
            }
        }
        return matches;
    }

    int getMatchesOfA(int ai) {
        return matchedA[ai];
    }

    int getMatchesOfB(int bi) {
        return matchedB[bi];
    }
};

#endif //BIPARTITE_MATCHING_H
