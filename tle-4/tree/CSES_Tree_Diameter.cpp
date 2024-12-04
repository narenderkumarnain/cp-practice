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

/**
 * String Hashing
 */
/*

class StringHash {
    lli mod = 1e9 + 7;
    // lli mod2 = 1e9 + 7;
    lli B1 = 5689;
    lli B2 = 8861;

    vector<pair<lli,lli>> prefixHash, power;
public:
    StringHash(string &s) {
        int n = s.length();
        prefixHash.resize(n+1);
        power.resize(n+1);

        // using 1 based indexing here
        prefixHash[0] = {0,0};
        power[0] = {1, 1};
        for(int i=1;i<=n;i++) {
            prefixHash[i] = {
                mod_add(mod_mul(prefixHash[i-1].first, B1, mod), (s[i-1] - 'a' + 1LL), mod),
                mod_add(mod_mul(prefixHash[i-1].second, B2, mod), (s[i-1] - 'a' + 1LL), mod)
            };
            power[i] = {
                mod_mul(power[i-1].first, B1 , mod),
                mod_mul(power[i-1].second, B2 , mod),
            };
        }
    }

    pair<int,int> getHash(int l, int r) {
        l++;
        r++;
        lli hash1 = mod_sub(prefixHash[r].first, mod_mul(prefixHash[l-1].first, power[r-l+1].first, mod), mod);
        lli hash2 = mod_sub(prefixHash[r].second, mod_mul(prefixHash[l-1].second, power[r-l+1].second, mod), mod);
        return {hash1, hash2};
    }
};
*/
/* template end here */

/* problem code here */

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> tree[n];
//     for(int i=0;i<n-1;i++){
//         int a, b;
//         cin >> a >> b;
//         tree[a-1].push_back(b-1);
//         tree[b-1].push_back(a-1);
//     }

//     // diameter = sum of 2 max child heights + 1;

//     vector<int> diameter(n, 0);

//     function<int(int,int)> dfs = [&](int node, int parent) -> int {

//         int height = 0;

//         multiset<int> st;

//         for(auto x: tree[node]) {
//             if(x != parent) {
//                 int childHeight = dfs(x, node);
//                 height = max(height, childHeight+1);

//                 st.insert(childHeight);

//                 if(st.size() > 2) st.erase(st.begin());
//             }
//         }

//         diameter[node] = 0;
//         while(!st.empty()) {diameter[node] += (*st.begin()) + 1; st.erase(st.begin());}
//         // if(top!=-1)diameter[node]++;
//         // if(top2!=-1)diameter[node]++;
//         return height;
//     };

//     dfs(0,  -1);


//     int mxAns = 0;
//     for(auto x: diameter) mxAns = max(mxAns, x);

//     cout << mxAns << endl;
// }

void solve2(){
    // cout << "here";
    int n;
    cin >> n;
    vector<int> tree[n];
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }

    int heighestDistance = 0, thatNode = -1;
    function<void(int,int,int)> dfs = [&](int node, int parent, int lvl) -> void {
        for(auto x: tree[node]) {
            if(x != parent) {
                dfs(x, node, lvl+1);
            }
        }

        if(lvl > heighestDistance ){
            heighestDistance = lvl;
            thatNode = node;
        }
    };

    dfs(0, -1, 0);

    // now we have one mode
    int nodeOne = thatNode;
    heighestDistance = 0;
    thatNode = -1;
    // cout << nodeOne << endl;
    dfs(nodeOne, -1, 0);

    cout << heighestDistance << endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve2();
    return 0;
}