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
        int n, k , d;
        cin >> n >> k >> d;

        vector<int> arr(n);
        for(auto &it: arr) cin >> it;

        int i = 0;
        int j = 0;

        int ans = n;

        map<int,int> mp;


        while(j < n) {
            // add jth element
            mp[arr[j]]++;

            while(i <= j && j-i+1 > d) {
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }
                i++;
            }

            if(j-i+1 == d) {
                ans = min(ans, (int)mp.size());
            }
            j++;
        }
        cout << ans << endl;

    }
    return 0;
}