#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> fruits(n, 0);
        vector<int> heights(n, 0);

        for(auto &it: fruits) cin >> it;
        for(auto &it: heights) cin >> it;

        int ans = 0;

        int i = 0;
        int j = 0;

        int sm_fruits = 0;

        while(j < n) {
            // add the jth element
            sm_fruits += fruits[j];
            if(j > 0 && heights[j-1] % heights[j] != 0) { i = j; sm_fruits = fruits[j]; }

            while(i <= j && (sm_fruits > k)) {
                sm_fruits -= fruits[i];
                i++;
            }

            if(i <= j && (sm_fruits <= k)) {
                ans = max(ans, j-i+1);
            }
            j++;
        }

        cout << ans << endl;
    }
    return 0;
}