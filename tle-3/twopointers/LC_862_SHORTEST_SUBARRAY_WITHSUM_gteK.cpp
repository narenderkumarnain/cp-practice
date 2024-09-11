#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long int> prefixSum(n+1, 0);
        for(int i=0;i<n;i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        deque<int> dq;

        // int i = 0;
        int j = 0;

        int ans = INT_MAX;

        while(j < n) {
            // add calculation for jth element
            while(!dq.empty() && prefixSum[dq.back()] >= prefixSum[j]) {
                dq.pop_back();
            }
            dq.push_back(j);

            // try to reduce it
            while(!dq.empty() && prefixSum[j+1] - prefixSum[dq.front()] >= k) { 
                ans=min(ans, j - dq.front()+1);
                dq.pop_front();
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};