#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool canHave(vector<vector<char>>& board, int i, int j, int val) {
        bool res = true;

        for(int idx=0;idx<9;idx++) {
            if(board[i][idx] != '.' && ((board[i][idx] - '0') == val)) {
                res = false;
                break;
            }

            if(board[idx][j] != '.' && ((board[idx][j] - '0') == val)) {
                res = false;
                break;
            }
        }

        int x = i / 3;
        int y = j / 3;

        for(int a = 3 * x;a < 3 * x + 3;a++) {
            for(int b = 3 * y;b < 3 * y + 3;b++) {
                if(a != i && b != j) {
                    if(board[a][b] != '.' && (board[a][b] - '0' == val)) {
                        res = false;
                        break;
                    }
                }
            }
        }
        return res;
    }
    bool solver(vector<vector<char>>& board, int i, int j) {
        if(j == 9) {
            return solver(board, i+1, 0);
        }

        if(i == 9) {
            return true;
        }

        // i have to fill the [i, j] column
        if(board[i][j] != '.') {
            return solver(board, i, j+1);
        }

        for(int val=1;val<=9;val++) {
            if(canHave(board, i , j, val)) {
                board[i][j] = '0' + val;
                // cout << board[i][j] << " - " << val << endl;
                bool result = solver(board, i, j+1);

                if(result == true) {
                    return true;
                }
                board[i][j] = '.';
            }
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board, 0 , 0);
    }
};