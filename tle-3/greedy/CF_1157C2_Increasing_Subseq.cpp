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
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &it: arr) cin >> it;

    int startIdx = 0;
    int endIdx = n-1;

    string ans = "";

    int prev = -1;

    while(startIdx <= endIdx) {
        if(arr[startIdx] != arr[endIdx]) {
            if(arr[startIdx] < arr[endIdx] && arr[startIdx] > prev) {
                ans += "L";
                prev = arr[startIdx];
                startIdx++;
            } else if(arr[startIdx] > arr[endIdx] && arr[endIdx] > prev) {
                ans += "R";
                prev = arr[endIdx];
                endIdx--;
            } else if(arr[startIdx] < arr[endIdx] && arr[endIdx] > prev){
                ans += "R";
                prev = arr[endIdx];
                endIdx--;
            } else if(arr[startIdx] > arr[endIdx] && arr[startIdx] > prev){
                ans += "L";
                prev = arr[startIdx];
                startIdx++;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    if(startIdx == endIdx && arr[startIdx] > prev) ans += "R";
    if(startIdx < endIdx) {
        string ans1 = ans;
        string ans2 = ans;

        int prevNew = prev;
        
        int a = startIdx;
        int b = endIdx;

        while(a < b) {
            if(arr[a] > prevNew) {
                ans1 += "L";
                prevNew = arr[a];
                a++;
            } else {
                break;
            }
        }

        a = startIdx;
        b = endIdx;

        prevNew = prev;

        while(b > a) {
            if(arr[b] > prevNew) {
                ans2 += 'R';
                prevNew = arr[b];
                b--;
            } else {
                break;
            }
        }

        if(ans1.length() > ans2.length()) {
            ans = ans1;
        } else ans = ans2;
    }

    cout << ans.length() << "\n";
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}