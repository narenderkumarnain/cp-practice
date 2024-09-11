#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    lli n, s;
    cin >> n >> s;

    vector<lli> arr(n, 0);
    for(auto &it: arr) cin >> it;

    lli i = 0;
    lli j = 0;

    lli sm = 0;
    lli ans = 0;

    while(j < n) {
        sm += arr[j];

        while(i <= j && sm > s) {
            sm -= arr[i];
            i++;
        }

        if(i <= j && sm <= s) {
            // 1 + 2 + 3 + .. + size 
            ans += (lli)(j-i+1) * (lli)(j-i+2) / 2;
        }
        j++;
    }

    cout << ans << endl;
    return 0;
}