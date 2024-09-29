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
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        // max factorial -> n + k - 1
        // n = 32 powers of 2 into k = 1e4 boxes
        // n + k -1 -> 1e4 + 32 max 
        int N = 1e4 + 32;

        Permutations pmt(N);

        vector<int> ans;

        for(int i=0;i<queries.size();i++) {
            int nSize = queries[i][0];
            int kVal = queries[i][1];

            map<int,int> primeFactors;

            for(int i=2;i*i<=kVal;i++) {
                if(kVal % i == 0) {
                    int count = 0;
                    while(kVal % i == 0) {
                        kVal = kVal / i;
                        count++;
                    }
                    primeFactors[i] = count;
                }
            }
            if(kVal > 1) primeFactors[kVal] = 1;

            lli res = 1;
            for(auto x: primeFactors) {
                lli object = x.second;
                lli boxes = nSize;

                lli temp = pmt.modmul(pmt.fact[object + boxes - 1], pmt.invfact[boxes-1], MOD);
                temp = pmt.modmul(pmt.invfact[object], temp, MOD);

                res = pmt.modmul(res, temp, MOD);
            }

            ans.push_back(res);
        }

        return ans;
    }
};