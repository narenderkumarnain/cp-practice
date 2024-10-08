#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool palindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void recur(string s, int idx, vector<string> & curr,  vector<vector<string>> &res) {
        if(idx == s.length()) {
            res.push_back(curr);
            return;
        }

        for(int i = idx;i<s.length();i++) {
            if(palindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i-idx+1));
                recur(s, i+1, curr, res);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        recur(s, 0, curr, res);
        return res;
    }
};