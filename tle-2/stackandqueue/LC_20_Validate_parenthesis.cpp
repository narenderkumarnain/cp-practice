#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';

        stack<char> st;
        for(int i=0;i<s.length();i++) {
            if(mp.find(s[i]) != mp.end()) {
                st.push(s[i]);
            } else {
                if(st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if(mp[top] != s[i]) {
                    return false;
                } 
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};