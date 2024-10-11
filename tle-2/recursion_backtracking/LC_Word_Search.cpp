#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool recur(vector<vector<char>>& board, int i, int j, string word, int idx, vector<vector<bool>> &visited) {
        int m = board.size();
        int n = board[0].size();
        if(idx == word.size()) return true;
        if(i >= m || i < 0 || j >=n || j < 0) return false;


        // 4 options
        char toMatch = word[idx];

        if(j < n-1 && visited[i][j+1] == false && board[i][j+1] == toMatch) {
            visited[i][j+1] = true;
            bool res = recur(board, i, j+1, word, idx+1, visited);
            if(res) return true;
            visited[i][j+1] = false;
        }

        if(j > 0 && visited[i][j-1] == false && board[i][j-1] == toMatch) {
            visited[i][j-1] = true;
            bool res = recur(board, i, j-1, word, idx+1, visited);
            if(res) return true;
            visited[i][j-1] = false;
        }

        if(i < m-1 && visited[i+1][j] == false && board[i+1][j] == toMatch) {
            visited[i+1][j] = true;
            bool res = recur(board, i+1, j, word, idx+1, visited);
            if(res) return true;
            visited[i+1][j] = false;
        }

        if(i > 0 && visited[i-1][j] == false && board[i-1][j] == toMatch) {
            visited[i-1][j] = true;
            bool res = recur(board, i-1, j, word, idx+1, visited);
            if(res) return true;
            visited[i-1][j] = false;
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m);
        for(int i=0;i<m;i++) {
            visited[i] = vector<bool>(n, false);
        }


        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    bool res = recur(board, i, j, word, 1, visited);
                    if(res) return true;
                    visited[i][j] = false;
                }
            }
        }

        return false;

    }
};