#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

bool predicate(string s, string t, int x, vector<int> &maxSuffix, vector<int> &maxPrefix) {
    // check for all substrings of size x -> if sub seq still holds 
    // how can subseq hold

    int n = s.size();
    int m = t.size();

    int i = 0;
    int j = x-1;

    while(j < n) {
        // cout << "i: " << i << " " <<  j << endl;
        // check this window 
        int maxBefore = i > 0 ? maxPrefix[i-1] : 0;
        int maxAfter = j < n-1 ? maxSuffix[j+1] : 0;

        if(maxBefore+maxAfter >= m) {
            // cout << "true" << endl;
            return true;
        }
        // increment this window
        i++;
        j++;
    }

    return false;
    
}

int main() {
    string s;
    cin >> s;

    string t;
    cin >> t;

    int start = 0;
    int end = s.size() - t.size(); // max length substring you can remove such that it still remains subseq

    int n = s.size();
    int m = t.size();
    vector<int> maxSuffix(s.size() , 0); // ith -> length of t possible after this index (from back)
    vector<int> maxPrefix(s.size(), 0); // ith -> length of t possible before this index 

    int i = 0;
    int j = 0;
    while(j < n) {
        if(i < m && s[j] == t[i]) {
            // we found one matching
            i++;
        }
        maxPrefix[j] = i;
        j++;
    } 

    i = m-1;
    j = n-1;
    while(j >= 0) {
        if(i >= 0 && s[j] == t[i]) {
            i--;
        }
        maxSuffix[j] = (m-1) - i;
        j--;
    }

    // for(int i=0;i<n;i++) {
    //     cout << maxSuffix[i] << " ," ;
    // }
    // cout << endl;
    // cout << "prefix" << endl;
    // for(int i=0;i<n;i++) {
    //     cout << maxPrefix[i] << " ," ;
    // }
    // cout << endl;

    int ans = -1;
    while(start <= end) {
        int mid = start + (end-start)/2;

        // predicate function such that
        // if x len substring removal can be true, then x-delta should also be true , just remove a less substring
        // hense predicate function is monotonic like TTTTTFFF
        // find max T
        if(predicate(s, t, mid, maxSuffix, maxPrefix)) {
            ans = mid;
            start=mid+1;
        } else {
            end=mid-1;
        }
    }

    cout << ans << endl;
    return 0;
}