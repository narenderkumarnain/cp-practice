#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,O3,Ofast") //even 10^8+ also works with this


/* template under progress */
#define lli long long int 
#define ld long double
#define pi pair<int,int>
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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool validate(int i,int j,int n, int m){
    if(i>=0&&i<n&&j>=0&&j<m)return true;
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> vec(n);
    int iLoc, jLoc;
    int bx, by;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        vec[i]=tmp;
        for(int j=0;j<m;j++){
            if(tmp[j]=='A'){
            iLoc = i;
            jLoc = j;
            }
            if(tmp[j]=='B'){
                bx=i;
                by=j;
            }
        }
    }



    /*
    Start bfs from A -> every node should know who pushed it
    */

   vector<vector<pi>>parent(n, vector<pi>(m, {-1,-1}));
   vector<vector<bool>> visited(n, vector<bool>(m,false));
   queue<pi> pq;

   pq.push({iLoc,jLoc});
   parent[iLoc][jLoc]={iLoc, jLoc};

   while(!pq.empty()){
        auto node=pq.front();
        pq.pop();
        visited[node.first][node.second]=true;
        // all adjacent nodes which are valid
        // extend to them
        for(int k=0;k<4;k++){
            int newx = node.first+dx[k];
            int newy = node.second+dy[k];

            // if not visited 
            if(validate(newx,newy,n,m)&& (visited[newx][newy]==false) && (vec[newx][newy] == '.' || vec[newx][newy]=='B')){
                // cout << "pushed: "<< newx << ":"<< newy<< endl;
                pq.push({newx,newy});
                parent[newx][newy]=node;
            }
        }
    }

    // compute backwards
    stack<pi> st;
    pi currNode = {bx, by};
    // cout << parent[bx][by].first << " - " << parent[bx][by].second << endl;
    bool ansFound = true;
    while(true){
        st.push(currNode);
        if(currNode.first==-1){
            ansFound=false;break;
        }
        if(currNode.first==iLoc&&currNode.second==jLoc)break;
        currNode = parent[currNode.first][currNode.second];
    }

    if(!ansFound) cout << "NO"<< endl;
    else {
        int distance=st.size();
        
        string ans="";
        auto prev=st.top();st.pop();
        // cout << prev.first << " - " << prev.second << endl;
        while(!st.empty()){
            auto tp = st.top();
            // cout << tp.first << " - " << tp.second << endl;
            st.pop();
            if(tp.first==prev.first) {
                if(tp.second==prev.second-1){
                    ans+="L";
                } else ans += "R";
            }else if(tp.second==prev.second){
                if(tp.first==prev.first-1) ans += "U";
                else ans += "D";
            }
            prev=tp;
        }
        // reverse(ans.begin(),ans.end());
        cout << "YES"<<"\n";
        cout << distance-1 << "\n";
        cout << ans << endl;
    } 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}