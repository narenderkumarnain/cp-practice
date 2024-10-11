#include<bits/stdc++.h>
using namespace std;


class Solution {
    void builder(string curr, stack<bool> &st, int n, vector<string> &res) {
        if(n == 0 && st.empty()) {
            // no opening left
            // while(!st.empty()) {
            //     curr += ")";
            //     st.pop();
            // }
            res.push_back(curr);
            return;
        }

        if(st.empty() == false) {
            st.pop();
            builder(curr + ")", st, n, res);
            st.push(true);
        }

        if(n > 0) {
            st.push(true);
            builder(curr + "(", st, n-1, res);
            st.pop();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        stack<bool> st;
        string ans = "";
        vector<string> res;

        builder(ans, st, n,  res);

        return res;
    }
};