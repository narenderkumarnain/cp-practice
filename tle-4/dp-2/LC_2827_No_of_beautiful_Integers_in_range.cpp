#include<bits/stdc++.h>
using namespace std;

#define lli long long int
lli findAns(int num, int k) {
    string nm = to_string(num);
    int n = nm.length();

    vector<vector<vector<vector<lli>>>> dp(n, vector<vector<vector<lli>>>(2, vector<vector<lli>>(k+1, vector<lli>(20, -1))));

    function<lli(int,int,int,int)> fn = [&](int idx, int bounded, int rem, int unmatchedOdd) -> lli {
        // base cases 
        if(idx == n){
            if(unmatchedOdd == 0 && rem == 0) return 1;
            else return 0;
        }

        if(dp[idx][bounded][rem][unmatchedOdd+10] != -1) return dp[idx][bounded][rem][unmatchedOdd+10];

        // result calculations
        lli res = 0;

        for(char c = '0';c <= ((bounded == 1) ? nm[idx] : '9'); c++){
            // compute new remainder 
            int newRemainder = ((rem % k) * 10 + (c - '0')) % k;
            if(c == '0' && rem == k) {
                // this also adds up in leading zeros 
                newRemainder = rem;
            }
            int newUnmatchedOdd = unmatchedOdd;
            if((newRemainder != k) && ((c-'0') % 2 == 0)) newUnmatchedOdd --;
            else if((c-'0') % 2 == 1) newUnmatchedOdd++;
            res += fn(idx+1, ((bounded == 1) && (c == nm[idx])),  newRemainder, newUnmatchedOdd);
        }

        dp[idx][bounded][rem][unmatchedOdd+10] = res;

        return res;
    };
    return fn(0, 1, k, 0);
}

class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        lli ans = findAns(high, k) - findAns(low, k);

        // check for the low element 
        bool valid = true;
        if(low % k != 0) valid = false;
        if(valid){
            int cutCount;
            int currNum = low;
            while(currNum > 0){
                int digit = currNum % 10;
                currNum = currNum / 10;
                if(digit%2==0) cutCount++;
                else cutCount--;
            }
            if(cutCount != 0) valid = false;
        }

        if(valid) ans ++;
        return ans;
    }
};