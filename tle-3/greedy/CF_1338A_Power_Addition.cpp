#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,O3,Ofast") //even 10^8+ also works with this


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

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<lli> arr(n);
        for(auto &it: arr) cin >> it;

        // multiset<lli> deltas;

        lli maxBit = -1;

        for(int i=1;i<n;i++) {
            if(arr[i-1] > arr[i]) {
                lli d = arr[i-1] - arr[i];
                maxBit = max(maxBit, (lli)(log2(d)));
                arr[i] = arr[i-1];
            }
        }

        // int idx = 0;
        // int prevMaxIdx = -1;
        // while(idx < n) {
        //     // cout << idx << endl;
        //     int start = idx;
        //     while(idx < n && (idx == start || arr[idx] >= arr[idx-1])) {
        //         idx++;
        //     }

        //     if(prevMaxIdx != -1) {
        //         deltas.insert(arr[prevMaxIdx] - arr[start]);
        //     }

        //     prevMaxIdx = idx-1;
        // }

        // for(auto x: deltas) cout << x << " , ";
        // cout << endl;
        // if(deltas.size() == 0) {
        //     cout << 0 << "\n";
        // } else {
        //     // sort(deltas.begin(), deltas.end());
        //     lli bitPos = 0;
        //     for(auto d: deltas) {
        //         bitPos = max(bitPos, (lli)(log2(d)));
        //     }
        //     cout << bitPos << endl;
        //     // int time = 1;
        //     // int covered = 0;
        //     // int sum = 0;
        //     // int sizeN = deltas.size();
        //     // lli prevVal = 0;
        //     // while(covered < sizeN || sum != 0) {
        //     //     if(covered == sizeN && sum != 0) {
        //     //         time += sum-1;
        //     //         break;
        //     //     }
        //     //     // cout << time << endl;
        //     //     lli val = 1LL << (time-1);
                
        //     //     auto startIt = deltas.upper_bound(prevVal);
        //     //     auto endIt = deltas.upper_bound(val);

        //     //     int count = distance(startIt, endIt);

        //     //     // cout << "distance : from "<< prevVal <<  " - " << val << " - - " << count<< endl;
        //     //     // cout << "sum : " << sum << "covered: " << covered << endl;;
        //     //     prevVal = val;
        //     //     if(count != 0 || sum != 0)
        //     //         sum += (count - 1);

        //     //     covered += count;
        //     //     if(covered == sizeN && sum  == 0) break;
        //     //     time++;
        //     // }
        //     // int mxBit = 0;
        //     // while(sm > 0) {
        //     //     sm = sm >> 1;
        //     //     mxBit++;
        //     // }

        //     cout << bitPos + 1 << "\n";
        // }
        if(maxBit == -1) cout << 0 << "\n";
        else cout << maxBit+1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}