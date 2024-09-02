#include<bits/stdc++.h>
using namespace std;

/* template under progress */

/* template end here */

bool isMinDistancePossible(
    vector<int>& stalls,
    int minDist,
    int noOfCows
) {
    noOfCows--;
    int currDist = 0;
    for(int i=1;i<stalls.size();i++) {
        currDist += stalls[i] - stalls[i-1];

        if(currDist >= minDist) {
            // cout << i << endl;
            currDist = 0;
            noOfCows--;

            if(noOfCows == 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {    
    int t;
    cin >> t;

    while(t--) {
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        for(int i=0;i<n;i++) {
            cin >> stalls[i];
        }

        sort(stalls.begin(), stalls.end());

        int start = 0;
        int end = 1e9;


        // // TTTTFFF
        int ans = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;

            if(isMinDistancePossible(stalls, mid, c)==true) {
                // cout << "this" << mid << endl;
                ans = max(ans, mid);
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        cout << ans << endl;
    }

    // O(t) * (O(nlogn) + O(N) * O(log(10e9))) ~ O(t) * (O(NlogN)) more or less
    return 0;
}