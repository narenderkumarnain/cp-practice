#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

bool predicate(vector<pair<int,int>> &cond, int count) {
    int n = cond.size();
    int curr = 1;

    for(int i=0;i<n;i++) {
        // check if this is allowed
        int noOfFriendsPoor = curr-1;
        int noOfFriendsRich = count - curr;

        if((noOfFriendsRich <= cond[i].first) && (noOfFriendsPoor <= cond[i].second)) {
            curr++;
        }
    }
    return curr-1 >= count;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int,int>> cond(n);
        for(int i=0;i<n;i++) {
            int a, b;
            cin >> a >> b;
            cond[i] = {a, b};
        }

        int start = 1;
        int end = n;
        int ans = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;

            // find out if we can invite mid friends or not !
            if(predicate(cond, mid)) {
                ans = mid;
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}