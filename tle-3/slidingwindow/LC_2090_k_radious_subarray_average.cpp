#include<bits/stdc++.h>
using namespace std;

#define lld long long int
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans(n, -1);
        // vector<lld> prefixSum(n, 0);
        // prefixSum[0] = nums[0];
        // for(int i=1;i<n;i++) {
        //     prefixSum[i] = prefixSum[i-1] + nums[i];
        // }

        // for(int i=0;i<n;i++) {
        //     if((i-k < 0 || i+k >= n)) {
        //         ans[i] = -1;
        //         continue;
        //     }

        //     lld minusValue = (i-k-1) >= 0 ? prefixSum[i-k-1] : 0;
        //     lld sm = prefixSum[i+k] - minusValue;

        //     ans[i] = sm / (2 * k + 1);
        // }

        // optimizations
        // int i = 0;
        int j = 0;
        lld topsm = 0;
        lld mnSum = 0;

        while(j < n) {
            topsm += nums[j];

                // mnidx (j-k) - k - 1 = j - 2k -1
            if(j-2*k-1 >= 0) {
                mnSum += nums[j-2*k-1];
            }

              // which one is completed at j
                // j = i + k
                // i = j - k
                int i = j - k;
            
            if(i >= 0 && (i-k) >= 0) {
                ans[i] = (topsm - mnSum) / (2 * k + 1);
            }
            j++;
        }


        return ans;
    }
};