#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */


struct Interactor {
    int queries;
    int maxQueries = 40;
    vector<int> arr;
    Interactor(vector<int> a) {
        queries = 0;
        arr=  a;
    }

    int query(int l, int r) {
        if(l >= r) exit(0);
        queries++;
        if(queries > maxQueries) exit(0);
        vector<int> ans;
        for(int i=l;i<=r;i++) {
            ans.push_back(arr[i]);
        }
        sort(ans.begin(), ans.end(), greater<int>());
        int secondGreatest = ans[1];
        int secondGreatestIndex = -1;
        for(int i=l;i<=r;i++) {
            if(arr[i] == secondGreatest) {
                secondGreatestIndex = i;
                break;
            }
        }
        // return ans;
        // cout << "q: " << l << "-"<< r << " - " << secondGreatestIndex << endl;
        return secondGreatestIndex;
    }
};
bool testing = false;
int query(int l, int r, Interactor &it) {
    if(testing) {
        return it.query(l, r);
    } else {
        cout << "? " << l+1 << " " << r+1 << endl;
        vector<int> arr(r-l+1);
        int ans;
        cin >> ans;
        return ans - 1;
    }
}

Interactor it({3,1,4,5,2});


int right(int l, int r) {
    // pivot -> x > r
    int pivot = l-1;
    int ans = r;

    while(l <= r) {
        int mid = l + (r-l)/2;

        if(query(pivot, mid, it) == pivot) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ans;
}

int left(int l, int r) {
    // l _> x > pivot
    int pivot = r+1;
    int ans = r;

    while(l <= r) {
        int mid = l + (r-l)/2;

        if(query(mid, pivot, it) == pivot) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    if(testing) {
        n = it.arr.size();
    }

    int start = 0;
    int end = n-1;
    
    int pivot = query(start, end, it);

    int ans;

    if(pivot == 0) ans = right(pivot+1, end);
    else {
        int res = query(0, pivot, it);
        if(res == pivot) {
            ans = left(0, pivot-1);
        } else {
            ans = right(pivot+1, end);
        }
    }

    cout << "! " << ans+1 << endl;
    return 0;
}