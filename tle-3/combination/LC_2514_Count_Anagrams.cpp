#include<bits/stdc++.h>
using namespace std;

#define lli long long int
const lli MOD = 1e9 + 7;
class Permutations {
public:
    vector<lli> fact;
    vector<lli> invfact;

    lli mod_expo(lli val, lli pow, lli MOD) {
        lli res = 1;
        while(pow > 0) {
            if((pow & 1) > 0) {
                res = ( (res % MOD) *  (val % MOD) ) % MOD;
            }
            val = ((val%MOD) * (val%MOD))%MOD;
            pow = pow >> 1;
        }
        return res;
    }

    lli modinv(lli val, lli MOD) {
        return mod_expo(val, MOD-2, MOD);
    }

    lli modmul(lli a, lli b, lli MOD) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    Permutations(lli N) {
        fact.resize(N);
        invfact.resize(N);

        fact[0] = 1;
        for(lli i=1;i<N;i++) {
            fact[i] = ((i % MOD) * (fact[i-1] % MOD) ) % MOD;
        }

        invfact[N-1] = modinv(fact[N-1], MOD);
        for(int i=N-2;i>=0;i--){
            invfact[i] = ((invfact[i+1] % MOD) * ((i+1)%MOD))% MOD;
        }
    }
};

class Solution {
public:
    int countAnagrams(string s) {
        int n = s.length();
        int maxFact = n;
        
        int startIdx = 0;
        while(startIdx < n) {
            int endIdx = startIdx;
            while(endIdx < n && s[endIdx] != ' ') {
                endIdx++;
            }
            maxFact = max(endIdx - startIdx+1, maxFact);
            startIdx = endIdx+1;
        }
        // cout << "substrlen: 1" << endl;
        Permutations pm(maxFact);
        // cout << "substrlen: " << endl;
        lli res = 1;
        
        int idx = 0;

        while(idx < n) {
            // get the curr word
            int endIdx = idx;
            unordered_map<char, int> mp;
            while(endIdx < n && s[endIdx] != ' ') {
                mp[s[endIdx]]++;
                endIdx++;
            }
            int substrLen = endIdx - idx;
            cout << "substrlen: " << substrLen << endl;

            lli tmp = 1;
            tmp = pm.modmul(tmp, pm.fact[substrLen], MOD);
            for(auto x: mp) {
                int cnt = x.second;
                tmp = pm.modmul(tmp, pm.invfact[cnt], MOD);
            }

            res = pm.modmul(tmp, res, MOD);
            idx = endIdx + 1;
        }

        return res % MOD;
    }
};