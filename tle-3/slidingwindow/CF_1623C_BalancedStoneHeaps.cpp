#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

bool predicate2(vector<int> h, int minReq) {
    int n = h.size();
    vector<int> upwardComing(h.size(), 0);
    for(int i=n-1;i>=2;i--) {
        int currSurplus = h[i] + upwardComing[i] - minReq;
        int dPossibleMax = currSurplus / 3;
        if(dPossibleMax < 0) dPossibleMax = 0;
        int realDMax = h[i] / 3;
        int d = min(dPossibleMax, realDMax);

        upwardComing[i-1] += d;
        upwardComing[i-2] += 2 * d;
        h[i] -= 3 * d;
    }

    for(int i=0;i<n;i++) {
        if(h[i] + upwardComing[i] - minReq < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> h(n);
        for(auto &it: h) {
            cin >> it;
        }

        int start = 0;
        int end = 1e9;

        int ans = -1;

        while(start <= end) {
            int mid = start + (end-start)/2;

            // cout << " mid : " << mid << endl;

            // validate if this is possible
            if(predicate2(h, mid)) {
                ans = mid;
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        cout << ans << endl;

    }
    return 0;
}