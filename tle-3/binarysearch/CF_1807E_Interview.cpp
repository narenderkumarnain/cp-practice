#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

struct Interactor {
    vector<int> realSum;
    int maxQueries = 30;
    int queries;
    Interactor(vector<int> a){
        realSum = a;
        queries = 0;
    }

    int query(int l, int r) {
        queries++;
        if(queries > maxQueries) exit(0);
        int sm = 0;
        for(int i=l;i<=r;i++) sm += realSum[i];
        return sm;
    }
};
bool testing = false;
int query(int l, int r, Interactor &it) {
    if(testing) {
        return it.query(l, r);
    } 
    else {
        int k = r-l+1;
        cout << "? " << k << " ";
        for(int i=l;i<=r;i++) {
            cout << i+1 << " ";
        }
        cout << endl;
        int ans;
        cin >> ans;
        return ans;
    }
}

int main() {
    int t;
    cin >> t;

    Interactor it({1,2,3,5,3,4,3});

    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &it: arr) {
            cin >> it;
        }

        // turn this array in prefix sum
        for(int i=1;i<n;i++) arr[i] = arr[i-1] + arr[i];

        /**
         * Predicate function
         * f(x) -> returns true if [start, mid] has more sum then required , else false
         * FFFFFTTTTTT
         * find the first true
         */

        int start = 0;
        int end = n-1;
        int ans = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;

            int expectedSum = arr[mid];
            if(start > 0) expectedSum -= arr[start-1];

            int realSum = query(start, mid, it);

            if(realSum > expectedSum) {
                // cout << "tru happened: " << start << ": " << mid << " " << realSum << " " << expectedSum << endl;
                // it's a true, first tru on left
                ans = mid;
                end = mid-1;
            } else {
                start=mid+1;
            }
        }

        cout << "! " << ans + 1 << endl;
    }
    return 0;
}