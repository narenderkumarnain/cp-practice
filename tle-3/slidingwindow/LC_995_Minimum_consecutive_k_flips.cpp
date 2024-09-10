#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> flips(n, 0); // this gives no of bit flip operations performed till flips[i]
        // so for sliding window, just take flips[i-1] - flips[i-k] 
        for(int i=0;i<n;i++) { 
            int value = nums[i];

            // check if this is flipped how many times.
            if(i > 0) {
                int b = flips[i-1];
                int a = i-k >=0 ? flips[i-k] : 0;
                int flipsCount = b - a;

                if(flipsCount %2 != 0) {
                    value = !value; 
                }
            }

            if(value == 0) {
                // perform the flip
                // flip will impact this and next k elements
                if(n - i >= k) {
                    flips[i]++;
                }  else {
                    return -1;
                }
            }

            nums[i] = 1;
            if(i > 0) {
                flips[i] += flips[i-1];
            }
        }

        return flips[n-1];
    }
};