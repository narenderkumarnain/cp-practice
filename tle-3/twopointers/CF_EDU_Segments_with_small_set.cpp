#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n, 0);
    for(auto &it: arr) cin >> it;

    map<int, int> mp;

    int i=0;
    int j=0;

    lli ans = 0;

    while(j < n) {
        mp[arr[j]]++;

        while(i <=j && mp.size() > k) {
            mp[arr[i]]--;
            if(mp[arr[i]] == 0) mp.erase(arr[i]);
            i++;
        }

        if(i <=j && mp.size() <= k) {
            ans += (j-i) + 1;
        }
        j++;
    } 

    cout << ans << endl;
    return 0;
}