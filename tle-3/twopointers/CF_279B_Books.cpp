#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> readTime(n);
    for(auto &it: readTime) cin >> it;

    int i = 0;
    int j = 0;

    lli sm = 0;
    int ans = 0;
    while(j < n) {
        // add calculation for j
        sm += readTime[j];

        while(i <= j && sm > t) {
            sm -= readTime[i];
            i++;
        }

        if(i <= j && sm <= t) {
            ans = max(ans, j-i+1);
        }
        j++;
    }

    cout << ans << endl;
    return 0;
}