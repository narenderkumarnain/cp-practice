#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
class Solution {
    long long exponentiation(long long a, long long b) {
        // O(logB)
        long long res = 1;
        while(b > 0) {
            if(b % 2 != 0) 
                res = ((res % mod) * (a % mod)) % mod;
            a = ((a % mod) * (a % mod)) % mod;
            b = b / 2;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        long long half = n / (2*1LL);

        long long res = exponentiation(1LL * 20, half);

        if(n % 2 != 0) {
            res = ((res % mod) * 5 ) % mod;
        }

        return (int)res;
    }
};