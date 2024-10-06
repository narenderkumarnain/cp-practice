#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxOnRight(n);
        maxOnRight[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxOnRight[i] = max(nums[i], maxOnRight[i+1]);
        }

        // max on right -> max from i to n-1

        int left = 0;
        int right = 0;

        int ans = 0;
        while(right < n) {
            while(left < right && nums[left] > maxOnRight[right]) {
                left++;
            }

            ans = max(ans, right - left);
            right ++;
        }

        return ans;
    }
};