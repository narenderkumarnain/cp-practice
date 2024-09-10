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

        vector<int> arr(n, 0);

        for(auto &it: arr) cin >> it;

        // peaksTillNow[i] -> no of peaks till now inlcuding i also
        vector<int> peaksTillNow(n, 0);
        peaksTillNow[0] = 0;
        int start = 0;

        int maxT = -1, l = -1;
        for(int i=1;i<n;i++) {
            bool iIsPeak = false;
            if(i < n-1) {
                if(arr[i] > arr[i+1] && arr[i] > arr[i-1]) {
                    peaksTillNow[i]++;
                    iIsPeak = true;
                }
            }
            peaksTillNow[i] += peaksTillNow[i-1];
            // check sliding window 

            if(i-start+1 == k) {
                int noOfPeaks = peaksTillNow[i] - peaksTillNow[start];
                // remove if i or start are peak
                if(iIsPeak) noOfPeaks--;
                if(start >= 1 && arr[start] > arr[start-1] && start < n-1 && arr[start] > arr[start+1]) {
                    noOfPeaks--;
                }

                if(l == -1) {
                    l = start;
                    maxT = noOfPeaks+1;
                }

                if(noOfPeaks+1 > maxT) {
                    l = start;
                    maxT = noOfPeaks+1;
                }
                start++;
            }
        }

        cout << maxT << " " << l+1 << endl;

    }
    return 0;
}