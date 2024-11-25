#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<vector<int>> dp(n, vector<int>((1 << (n+1))-1, -1));
        function<int(int,int)> fn = [&](int idx, int visited) -> int {
            int ans = INT_MAX;
            if(idx == n) return 0;

            if(dp[idx][visited] != -1) return dp[idx][visited];
            for(int i=0;i<n;i++) {
                if((visited & (1 << i)) == 0) {
                    // we can pick this up
                    ans = min(ans, (nums1[idx] ^ nums2[i]) + fn(idx+1, visited | (1 << i)));
                }
            }
            dp[idx][visited]= ans;

            return ans;
        };
        return fn(0, 0);
    }
};