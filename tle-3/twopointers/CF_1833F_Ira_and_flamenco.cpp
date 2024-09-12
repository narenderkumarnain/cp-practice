#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double

#define MOD 1000000007

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

int mul(int x, int y) {
    return (x * 1LL * y) % MOD;
}

int power(int x, int y) {
    int ans = 1;
    while (y > 0) {
        if (y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y = y >> 1;
    }
    return ans;
}

int divide(int x, int y) {
    return mul(x, power(y, (MOD - 2)));
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> students(n);
        // int maxLevel = 0;
        for(auto &it: students){
            cin >> it;
        }
        // cout << "till here" << maxLevel << endl;
        unordered_map<int,int> frequencyTable;
        set<int> st;
        for(int i=0;i<n;i++) {
            st.insert(students[i]);
            frequencyTable[students[i]]++;
        }

        vector<int> validLevelsTable(st.begin(), st.end());
        int maxLevel = validLevelsTable.size();

        // cout << "till here 2" << endl;

        // increasing type -> 
        int i = 0;
        int j = 0;

        int count = 0;

        int zerosCount = 0;
        int multiplicationRes = 1;


        while(j < maxLevel) {
            // add computation for j
            if(frequencyTable[validLevelsTable[j]] == 0) zerosCount++;
            else {
                multiplicationRes = mul(multiplicationRes,frequencyTable[validLevelsTable[j]]);
            }
            while(validLevelsTable[j]-validLevelsTable[i]+1 > m) {
                // remove i
                if(frequencyTable[validLevelsTable[i]] == 0) zerosCount--;
                else {
                    multiplicationRes = divide(multiplicationRes, frequencyTable[validLevelsTable[i]]);
                }
                i++;
            }

            // now we have biggest such array for which the m condition is fulfilled
            if(j-i+1 == m) {
                // form no of ways
                if(zerosCount == 0) {
                    count = (count +  multiplicationRes) % MOD;
                }
            }
            // update answer
            j++;
        }

        cout << count << endl;
    }
    return 0;
}