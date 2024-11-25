#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<vector<int>> dp(n, vector<int>(1 << (n+1), -1));
        function<int(int,int)> fn = [&](int idx, int visited) -> int {
            if(idx == n) return 1;

            if(dp[idx][visited] != -1) return dp[idx][visited];
            int ans = 0;
            for(int j=1;j<=n;j++) {
                // check if available
                if(( (visited & (1 << (j-1))) == 0 ) && (j%(idx+1) == 0 || (idx+1)%j == 0)) {
                    // candidate found
                    ans += fn(idx+1, (visited | (1 << (j-1))));
                } 
            }
            dp[idx][visited] = ans;

            return ans;
        }; 

        return fn(0, 0);
    }
};