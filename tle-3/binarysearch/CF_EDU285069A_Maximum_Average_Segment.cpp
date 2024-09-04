#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

/**
 * Problem steps 
 * - given array arr of length n, find max subarray of length atleast d, which has max mean
 * 
 * mean: 0 to 100
 * search space length: 10^2 x 10^10 ~ 40 iterations 
 * lets just do 50 iterations and make sure unecessary iterations do not alter the solution bad.
 */

#define answer pair<bool, pair<int,int>>

answer maximumSubarray(
    vector<ld> &transformedArray,
    int n,
    int d
) {
    vector<ld> prefixSum(n);
    prefixSum[0] = transformedArray[0];
    for(int i=1;i<n;i++) {
        prefixSum[i] = prefixSum[i-1] + transformedArray[i];
    }

    ld minTillNow = 0; // start of array
    ld ans = -1e18;
    ld minCoord = 0;

    for(int i=d-1;i<n;i++) {
        // evaluate result
        ld t = prefixSum[i] - minTillNow;
        ans = max(ans, t);
        if(ans >= 0) {
            return {true, {minCoord, i}};
        }

        // update minTillNow
        if(minTillNow > prefixSum[i-d+1]) {
            minTillNow = prefixSum[i-d+1];
            minCoord = i-d+2;
        }
    }

    return {false, {-10,-10}};
}

answer checkIfSubarrayIsPossible(
    vector<ld> & arr,
    int n,
    ld mean,
    int d
) {
    // choose subarray such that (a1 + . + ak) / k >= mean => (a1-mean) + (a2-mean) >= 0
    vector<ld> transformedArray(n);
    for(int i=0;i<n;i++) {
        transformedArray[i] = arr[i] - mean;
    }

    // now find a subarray which have subarray sum >= 0  (and max) and length at least d
    auto ans = maximumSubarray(transformedArray, n, d);
    return ans;
}


int main() {
    int n, d;
    cin >> n >> d;

    vector<ld> arr(n);
    for(auto &it: arr) cin >> it;

    ld start = 0;
    ld end = 100;

    pair<int,int> res = {-10,-10};
    for(int i=0;i<100;i++) {
        // ld mid = start + (end-start)/2;
        ld mid =(end+start)/2;

        // validate if there is a subarray with mean >= mid
        auto tAns = checkIfSubarrayIsPossible(arr, n, mid, d);

        if(tAns.first == true) {
            res = tAns.second;
            start = mid;
        } else {
            end = mid;
        }

    }

    auto tt = checkIfSubarrayIsPossible(arr, n, start, d);
    res = tt.second;

    cout << res.first + 1 << " " << res.second + 1 << endl;
    return 0;
}