#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

#define answer pair<bool, vector<int>>

answer predicate(vector<int> &prices, int x) {
    int n = prices.size();

    // pick min x elements 
    int minIdx = x-1;
    // pick the next greatest element
    int maxIndex = n-1;
    int minMaxIndex = x;

    vector<int> res(n);
    int i = 0;

    for(int i=0;i<n;i++) {
        if(i % 2 == 0) {
            // index 0, 2, 4, 6, 8
            res[i] = prices[maxIndex];
            maxIndex--;
        } else {
            // index 1, 3, 5, 7 -> valleys to be formed
            if(minIdx >= 0){
                res[i] = prices[minIdx];
                minIdx--;
            } else {
                res[i] = prices[maxIndex];
                maxIndex--;
            }
        }
    }

    // cout << "array formed with mid: " << x << " - ";
    // for(auto it: res) {
    //     cout << it << " ";
    // }
    // cout << endl;

    int noOfValleys = 0;
    for(int i=0;i<n;i++) {
        if(i%2 !=0 && i < n-1) {
            if(res[i] < res[i+1] && res[i] < res[i-1]) {
                noOfValleys++;
            }
        }
    }

    if(noOfValleys >= x) {
        return {true, res};
    }
    return {false, res};
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(auto &it: prices) {
        cin >> it;
    }

    sort(prices.begin(), prices.end()); // ascending order

    int start = 0;
    int end = n / 2;

    if(n%2 == 0) end--;

    answer ans;
    int maxSphere = -1;
    while(start <= end) {
        int mid = start + (end-start)/2;

        auto t = predicate(prices, mid);

        // cout << mid << " ? " << t.first << endl;
        if(t.first == true) {
            ans = t;
            maxSphere = mid;
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }

    cout << maxSphere << endl;
    for(auto it: ans.second) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}