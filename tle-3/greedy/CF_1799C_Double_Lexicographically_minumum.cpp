#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double


// modular arithemetic
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
lli gcd(lli a, lli b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
lli expo(lli a, lli b, lli mod) {lli res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(lli a, lli b, lli*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); lli x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
lli mminv(lli a, lli b) {lli arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
lli mminvprime(lli a, lli b) {return expo(a, b - 2, b);}
bool revsort(lli a, lli b) {return a > b;}
lli combination(lli n, lli r, lli m, lli *fact, lli *ifact) {lli val1 = fact[n]; lli val2 = ifact[n - r]; lli val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<lli> sieve(int n) {int*arr = new int[n + 1](); vector<lli> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
lli mod_add(lli a, lli b, lli m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
lli mod_mul(lli a, lli b, lli m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
lli mod_sub(lli a, lli b, lli m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
lli mod_div(lli a, lli b, lli m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
lli phin(lli n) {lli number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (lli i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
lli getRandomNumber(lli l, lli r) {return uniform_int_distribution<lli>(l, r)(rng);} 
/*--------------------------------------------------------------------------------------------------------------------------*/
/* Combinatrics Template */
/*
#define intl long long
 
const intl MOD = 1e9 + 7;
const intl N = 1e6;
 
intl mod(intl a, intl m = MOD) {
    return a % m;
}
 
template <class T> class Math {
  public:
    vector<T> fact, invfact;
    Math() {}
    Math(intl n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for (intl i = 1; i < n; i++) {
            fact[i] = mod(i * fact[i - 1]);
            invfact[i] = modinv(fact[i]);
        }
    }
    T modinv(T x, T m = MOD) { return expo(x, m - 2, m); }
    T expo(T base, T exp, T m = MOD) {
        T res = 1;
        while (exp) {
            if (exp & 1)
                res = mod(res * base, m);
            base = mod(base * base, m);
            exp >>= 1;
        }
        return res;
    }
    T choose(T n, T k) {
        if (k < 0 || k > n)
            return 0;
        T ans = fact[n];
        ans = mod(ans * invfact[n - k]);
        ans = mod(ans * invfact[k]);
        return ans;
    }
};

*/
/* template end here */

/* problem code here */

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        sort(s.begin(), s.end());
        // map<char, int> mp;
        // for(int i=0;i<n;i++) {
        //     mp[s[i]]++;
        // }
        int idx = 0;

        string res = "";
        for(int i=0;i<n;i++) res += '.';

        int frontIdx = 0;
        int backIdx = n-1;


        while(idx < n) {
            if(idx < n-1 && s[idx] == s[idx+1]) {
                res[frontIdx++] = s[idx];
                res[backIdx--] = s[idx];
                idx += 2;
                continue;
            } else if(idx < n-1 && s[idx] != s[idx+1]) {
                if(s[idx+1] == s[n-1]) {
                    // this was the last one 
                    // size of last segment 
                    int sz = (n-1) - (idx+1) + 1;
                    int cnt = sz/2;
                    while(cnt--) {
                        res[frontIdx++] = s[idx+1];
                        res[backIdx--] = s[idx+1];
                    }
                    if(sz%2 != 0) {
                        res[frontIdx++] = s[idx+1];
                    }
                    res[backIdx--] = s[idx];
                    idx = n;
                } else {
                    res[backIdx--] = s[idx];
                    for(int i=idx+1;i<n;i++) {
                        res[frontIdx++] = s[i];
                    }
                    idx = n;
                }
            } else {
                if(res[frontIdx] == '.') res[frontIdx] = s[idx];
                else res[backIdx] = s[idx];
                idx++;
            }
        }    

        string res2 = res;
        reverse(res2.begin(), res2.end());
        res = max(res, res2);


        cout << res << "\n";

        
    }
    return 0;
}