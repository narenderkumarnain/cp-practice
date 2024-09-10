#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

pair<int,int> twosumPossible(
    vector<int> &arr,
    int m, 
    int x
) {
    int i = 0;
    int j = m;

    while(i < j) {
        int sm = arr[i] + arr[j];

        if(sm == x) {
            return {i, j};
        } else if(sm > x) {
            j--;
        } else {
            i++;
        }
    }

    return {-1,-1};
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n, 0);
    for(auto &it: arr) cin >> it;

    vector<int> original(arr);
    sort(arr.begin(), arr.end());

    int a = -1, b, c;

    for(int i=2;i<n;i++) {
        if(arr[i] >= x) {
            continue;
        }

        int newX = x - arr[i];

        auto anySolve = twosumPossible(arr, i-1, newX);

        if(anySolve.first != -1) {
            // we found the solution
            a = anySolve.first;
            b = anySolve.second;
            c = i;
        }
    }

    // cout << arr[a] << " " << arr[b] << " " << arr[c] << endl;

    if(a == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> ans = {-1, -1, -1};
    for(int i=0;i<n;i++) {
        if(ans[0] == -1 && original[i] == arr[a]) {
            ans[0] = i;
            continue;
        }

        if(ans[1] == -1 && original[i] == arr[b]) {
            ans[1] = i;
            continue;
        }

        if(original[i] == arr[c]) {
            ans[2] = i;
        }
    }

    // if(ans[0] == -)

    sort(ans.begin(), ans.end());

    for(int i=0;i<=2;i++) {
        cout << ans[i] + 1<< " ";
    }
    cout << endl;

    return 0;
}