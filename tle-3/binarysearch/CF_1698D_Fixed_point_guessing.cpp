#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */


struct Interactor {
    int queries;
    int maxQueries = 15;
    vector<int> arr;
    Interactor(vector<int> a) {
        queries = 0;
        arr=  a;
    }

    vector<int> query(int l, int r) {
        queries++;
        if(queries > maxQueries) exit(0);
        vector<int> ans;
        for(int i=l;i<=r;i++) {
            ans.push_back(arr[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
bool testing = false;
vector<int> query(int l, int r, Interactor &it) {
    if(testing) {
        return it.query(l, r);
    } else {
        cout << "? " << l+1 << " " << r+1 << endl;
        vector<int> arr(r-l+1);
        for(int i=0;i<=r-l;i++) {
            int temp;
            cin >> temp;
            arr[i] = temp;
        }
        return arr;
    }
}

int main() {
    // Interactor it({2,1,4,3,7,6,5,9,8});
        Interactor it({4,2,5,1,3});

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int start = 0;
        int end = n-1;

        int ans = -1;
       while(start<=end) {
            int mid = start + (end-start)/2;

            auto ansArr = query(start, mid, it);

            int noOfExternalSwaps = 0;
            int noOfElements = mid-start+1;

            for(int i=0;i<noOfElements;i++) {
                if((ansArr[i] < start + 1) || (ansArr[i] > mid+1)) {
                    noOfExternalSwaps++;
                }
            }

            int noOfElementsLeft = noOfElements - noOfExternalSwaps;

            // cout << "Mid: " << mid << ":" << start <<  " - " << noOfElementsLeft << endl;

            if(noOfElementsLeft % 2 == 0) {
                // this does not contain the single element
                start=mid+1;
            } else {
                // this contains the element
                ans = mid;
                end=mid-1;
            }
        }

        cout << "! " << ans + 1 << endl;
    }
    return 0;
}