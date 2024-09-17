#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        // from 0 to 2^n-1
        for(int mask = 0;mask < (1 << n);mask++) {
            bool passed = true;
            int count = 0;
            for(int i=0;i<n;i++) {
                if(mask & (1 << i)) {
                    count++;
                    // if the current one is true
                    for(int j=0;j<n;j++) {
                            bool good = mask & (1 << j) ? true : false;
                            // if j is also true
                            // and not inconsistent 
                            if((good && statements[i][j] == 0) || (!good && statements[i][j] == 1)) {
                                passed = false;
                                break;
                            }
                    }
                }
                if(!passed) break;
            }
            if(passed) {
                ans = max(ans, count);
            }
        }

        return ans;
    }
};