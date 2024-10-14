#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDistance = 0;
        int n = nums.size();

        for(int i=0;i<n;i++) {
            if(i > maxDistance) {
                return false;
            }

            if(i + nums[i] > maxDistance) {
                maxDistance = i + nums[i];
            }
        }

        return maxDistance >= n-1;
    }
};