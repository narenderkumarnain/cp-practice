#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

struct Interactor {
    int maxQueries;
    int queriesCount;
    vector<int> arr;
    Interactor(vector<int> a) {
        arr = a;
        maxQueries = 20;
        queriesCount = 0;
    }

    int query(int l, int r) {
        int sm = 0;
        for(int i=l;i<=r;i++) sm += arr[i];
        return sm;
    }
};

bool testing = false;
int query(int l, int r, Interactor &it) {
    if(testing) {
        return it.query(l, r);
    }
    else {
        cout << "? " << l+1 << " " << r+1 << endl;
        int ans;

        cin >> ans;
        return ans;
    }
}

int main() {
    Interactor it({1,0,1,1,0,1});


    int n, t;
    cin >> n >> t;

    // n = 2 x 10^5 -> max 20 iterations required to find answer using BS
    int k;
    cin >> k;

    // kth zero index -> leftmost element where sm == k
    int ansIdx = -1;
    
    int start = 0;
    int end = n-1;

    while(start <= end) {
        int mid = start + (end-start)/2;

        int ans = query(0, mid, it);

        int noOfZeros = (mid+1) - ans;

        if(noOfZeros >= k) {
            ansIdx = mid;
            end = mid-1;
        } else {
            start = mid+1;
        }
    }

    cout << "! " << ansIdx + 1 << endl;

    return 0;
}