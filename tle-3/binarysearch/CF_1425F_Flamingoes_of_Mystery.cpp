#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

struct Interactor {
    vector<int> arr;
    int queryCount;
    int maxQueryCount;
    Interactor(vector<int> a) {
        arr = a;
        maxQueryCount = a.size();
        queryCount = 0;
    }

    int query(int l, int r) {
        queryCount++;
        if(queryCount > maxQueryCount) {
            cout << l << " " << r << queryCount << maxQueryCount << endl;
            throw invalid_argument("wrong answer");
        }
        int sm = 0;
        for(int i=l;i<=r;i++) {
            sm += arr[i];
        }
        return sm;
    };
};

bool testing = false;

int query(int l, int r, Interactor &it) {
    if(testing) { 
        return it.query(l, r);
    } else {
        cout << "? " << l + 1 << " " << r + 1 << endl;
        int ans;
        cin >> ans;
        return ans;
    }
}

int main() {
    int n;
    cin >> n;

    Interactor it({1,4,4,6,7,8});

    vector<int> prefixSumArr(n, 0);
    for(int i=1;i<n;i++) {
        int sm = query(0, i, it);
        prefixSumArr[i] = sm;
    }

    int smExceptFirst = query(1, n-1, it);
    prefixSumArr[0] = prefixSumArr[n-1] - smExceptFirst;

    for(int i=n-1;i>=1;i--) {
        prefixSumArr[i] = prefixSumArr[i] - prefixSumArr[i-1];
    }

    cout << "! ";
    for(int i=0;i<n;i++) {
        cout << prefixSumArr[i] << " ";
    }
    cout << endl;
    return 0;
}