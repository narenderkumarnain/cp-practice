#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

bool predicate(vector<lli> &arr, lli x, lli k) {
    lli n = arr.size();
    lli sm = 0;
    for(lli i=0;i<n;i++) {
        sm += arr[i];
    }

    lli reductionRequired = sm - k;

    // cout << "reduction req: " << reductionRequired << endl;
    if(reductionRequired <= x) return true;

    lli minValue = arr[0];

    if(n == 1) {
        return reductionRequired <= x;
    }

    lli runningSum = 0;
    for(lli i=n-1;i>=1 && i >= n-x;i--) {
        runningSum += arr[i];

        lli d = max((lli)0, x - (n-i));

        lli reductionPossble = (runningSum - ((n-i) * (minValue - d)) + d);

        if(reductionPossble >= reductionRequired) return true;
    }

    return false;
}

int main() {
    lli t;
    cin >> t;

    while(t--) {
        lli n, k;
        cin >> n >> k;

        vector<lli> arr(n);
        for(auto &it: arr) cin >> it;

        sort(arr.begin(), arr.end());

        lli start = 0;
        lli end = 1e15;

        lli ans = -1;

        while(start <= end) {
            lli mid = start + (end-start)/2;

            if(predicate(arr, mid, k)) {
                ans = mid;
                end=mid-1;
            } else {
                start=mid+1;
            }   
        }

        cout << ans << endl;
    }
    return 0;
}