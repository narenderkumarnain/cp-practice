#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solutionBuilder(vector<string> &state, int idx, vector<vector<string>> &res) {
        if(idx == state.size()) {
            res.push_back(state);
            return;
        }
        int n = state.size();
        for(int i=0;i<n;i++) {
            bool allowed = true;
            for(int j=0;j<idx;j++) {
                if(state[j][i] == 'Q') {
                    allowed = false;
                    break;
                } 
            }
            int x = idx-1;
            int y = i-1;
            while(x >=0 && y >=0) {
                if(state[x][y] == 'Q') {
                    allowed=false;
                    break;
                }
                x--;y--;
            }
            x = idx-1;
            y = i+1;
            while(x >= 0 && y < n) {
                if(state[x][y] == 'Q') {
                    allowed=false;
                    break;
                }
                x--;y++;
            }
            if(allowed) {
                state[idx][i] = 'Q';
                solutionBuilder(state, idx+1, res);
                state[idx][i] = '.';
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> finalRes;
        vector<string> state(n);
        for(int i=0;i<n;i++) {
            state[i] = "";
            for(int j=0;j<n;j++) state[i] += ".";
        }
        solutionBuilder(state, 0, finalRes);
        return finalRes;
    }
};