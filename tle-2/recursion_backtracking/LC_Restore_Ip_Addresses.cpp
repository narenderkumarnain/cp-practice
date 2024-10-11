#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool validPart(string s, int start, int len) {
        if(len == 0) return false;
        if(len >= 4) return false;
        if(len > 1 && s[start] == '0') {
            return false;
        }
        int val = 0;
        // int val = stoi(s.substr(start, len));
        for(int i=start;i<start+len;i++) {
            val = (val * 10) + (s[i] - '0');
        }

        // cout << s.substr(start, len) << " - " << val << endl;
        return (val <= 255) && (val >= 0);
    }
    void builder(string &s, int idx, int rem, string curr,  vector<string> &res) {
        if(idx >= s.length()) return;
        if(rem == 0) {
            // cout << "rem here: " << curr << endl;
            // check remaining portion
            if(validPart(s, idx, s.length() - idx)) {
                curr += s.substr(idx, s.length() - idx);
                res.push_back(curr);
            }
            return;
        }

        // try to place a dot
        for(int i=1;i<=3;i++) {
            if(idx + i <= s.length()) {
                if(validPart(s, idx, i)) {
                    // cout << "start part: " << s.substr(idx, i) << endl;
                    builder(s, idx+i, rem-1, curr + s.substr(idx, i) + ".", res);
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        builder(s, 0, 3, "", res);
        return res;
    }
};