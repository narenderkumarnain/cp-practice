#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();

        int i = 0, j = 0;
        stack<int> st;
        while(i < n && j < n) {
            // always two options , push the element or pop the element
            // check if pop allowed 
            if(!st.empty() && pushed[st.top()] == popped[j]) {
                // pop this element
                st.pop();
                j++;
            } else {
                // push the element
                st.push(i);
                i++;
            }
        }

        while(!st.empty()) {
            if(pushed[st.top()] != popped[j]) return false;
            j++;
            st.pop();
        }
        return true;
    }
};