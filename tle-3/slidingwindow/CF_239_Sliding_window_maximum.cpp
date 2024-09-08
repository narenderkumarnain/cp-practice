#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;

        int start = 0;
        for(int i=0;i<n;i++) {
            // add this to calculation 
            while(!q.empty() && q.back() < nums[i]) q.pop_back();
            q.push_back(nums[i]);

            // len(window) > k -> reduce it to k
            if(i-start+1 > k) {
                while(i-start+1 > k) {
                    // remove the start element 
                    int ele = nums[start];
                    if(q.front() == ele) q.pop_front();
                    start++;
                }
            }

            // if equal to k -> push answer 
            if(i-start+1 == k) {
                ans.push_back(q.front());
            }
        }
        return ans;
    }
};