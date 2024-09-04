#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

bool predicate(vector<pair<int,int>> &pairs, ld ratio, int n, int k) {
    vector<ld> transformed(n);
    for(int i=0;i<n;i++) {
        transformed[i] = (ld)pairs[i].first - ((ld)pairs[i].second) * ratio;
    }

    // sort descending
    sort(transformed.begin(), transformed.end(), greater<ld>());  

    ld sm = 0;
    for(int i=0;i<k;i++){
        sm += transformed[i];
    }  

    return sm >= 0;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> pairs(n);

    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        pairs[i] = {a, b};
    }

    ld start = 0;
    ld end = 1e10;

    // time complexity: O(log(1e18) x NlogN)

    ld ans = 0;
    for(int iter=0;iter < 60;iter++) {
        ld mid = start + (end-start)/2;
        
        if(predicate(pairs, mid, n, k)) {
            ans = max(ans, mid);
            start = mid;
        }  else {
            end = mid;
        }
    }

    cout << setprecision(10) << fixed << ans << endl;
    return 0;
}