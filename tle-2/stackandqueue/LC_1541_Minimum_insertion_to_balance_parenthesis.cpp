#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;

        int n = s.length();
        int i = 0;
        int ans = 0;
        while(i < n) {
            if(s[i] == '(') {
                st.push(s[i]);
                i++;
            } else {
                // closing brace
                // if is in pairs 
                if(i < n-1 && s[i+1] == s[i]) {
                    if(!st.empty() && st.top() == '(') {
                        st.pop();
                    } else {
                        ans++;
                    }
                    i+=2;
                } else {
                    if(!st.empty() && st.top() == '(') {
                        ans++;
                        st.pop();
                        i++;
                    } else {
                        ans += 2;
                        i++;
                    }
                    // i+=2;
                }
            }
        }
        ans += st.size() * 2;
        return ans;
    }
};