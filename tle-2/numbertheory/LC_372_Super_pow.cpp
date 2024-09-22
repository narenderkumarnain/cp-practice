#include<bits/stdc++.h>
using namespace std;

class Solution {
    // int exponentiation() {}
public:
    int superPow(int a, vector<int>& b) {
        int mod = 1337; // this is not a prime boi, not a prime
        // no fermat's little theorm here

        // b = b2 b1 b0
        // a^(b2*100 + b1*10 + b0)
        // a^p.a^q = a^p+q
        // a^10 * bi -> (a^10)^b1
        
        int ans = 1;
        int k = b.size();


        // this should contain a^b
        int currPow = 1;
        for(int i=1;i<=b[k-1];i++) {
            currPow = ((currPow % mod) * (a % mod))%mod;
        }
        ans = ((ans % mod) * (currPow % mod)) % mod;


        int prev = a % mod;
        for(int i=k-2;i>=0;i--) {
            // prev^10
            // prev ^ bi
            // update ans
            int newTens = 1;
            for(int j=1;j<=10;j++) {
                newTens = ((prev%mod) * (newTens%mod)) % mod;
            }
            prev = newTens;

            int currNew = 1;

            for(int j=1;j<=b[i];j++) {
                currNew = ((currNew%mod) * (newTens%mod)) % mod;
            }

            ans = ((ans % mod) * (currNew % mod)) % mod;
        }

        return ans;
    }
};