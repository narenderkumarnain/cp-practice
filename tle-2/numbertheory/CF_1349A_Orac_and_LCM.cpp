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
/* template end here */

/* problem code here */

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int N = 1;
    for(auto &it: arr) {cin >> it; N = max(it, N);}
    N ++;

    vector<int> spf(N);
    for(int i=0;i<N;i++) spf[i] = i;
    for(int i=2;i*i<N;i++) {
        if(spf[i] == i) {
            for(int j=i*i;j<N;j+=i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

    map<int, pair<multiset<int>,int>> factors;

        // cout << "done" << endl;


    for(int i=0;i<n;i++) {
        int nm = arr[i];

        while(nm > 1) {
            int sf = spf[nm];

            if(factors.find(sf) == factors.end()) {
                factors[sf] = {multiset<int>(), 0};
            }

            int count = 0;
            while(nm % sf == 0) {
                count++;
                nm = nm / sf;
            }

            factors[sf].second = factors[sf].second + 1;

            factors[sf].first.insert(count);
            // if(factors[sf].first.size() > 2) {
            //     factors[sf].first.erase(factors[sf].first.end()--);
            // }

        }

    }

    lli finalAns = 1;
    for(auto x: factors) {
        if(x.second.second >= (n-1)) {
            int val = x.first;
            int minFreq;
            if(x.second.second == n) {
                int tt = 0;
                int idx = 0;
                for(auto abc: x.second.first) {
                    tt = max(tt, abc);
                    idx++;
                    if(idx == 2) break;
                }
                minFreq = tt;
                // cout << x.first << " - n " << minFreq << endl;
            } else {
                minFreq = *x.second.first.begin();
                // cout << x.first << " - n - " << minFreq << endl;
            }

            finalAns *= pow(1LL * val, 1LL * minFreq);
        }
    }

    cout << finalAns << endl;

    return 0;
}