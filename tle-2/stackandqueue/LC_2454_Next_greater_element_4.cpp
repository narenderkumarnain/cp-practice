#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        stack<int> st1, st2;

        vector<int> ans(n, -1);
        for(int i=0;i<n;i++) {
            while(!st2.empty() && nums[st2.top()] < nums[i]) {
                // this is ans of it
                ans[st2.top()] = nums[i];
                st2.pop();
            }
            stack<int> tmp;
            while(!st1.empty() && nums[st1.top()] < nums[i]) {
                // this is ans of it
                // ans[st1.top()] = nums[i];
                tmp.push(st1.top());
                st1.pop();
            }

            while(tmp.empty() == false) {
                st2.push(tmp.top());
                tmp.pop();
            }

            st1.push(i);
        }

        return ans;
    }
};