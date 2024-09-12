#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    lli n, k;
    cin >> n >> k;

    vector<lli> arr(n);
    for(auto &it: arr) cin >> it;

    lli i = 0;
    lli j = 0;

    lli ans = 0;

    multiset<lli> st;

    /**
     * if [l:r] is good subarray, max-min <= k, then all inside it will also be good
     * if [l:r] if bad subarray, max-min > k then all including it will also be bad
     */

    while(j < n) {
        // add the jth element to calculation
        st.insert(arr[j]);

        while(i <= j && *(st.rbegin()) - *(st.begin()) > k) {
            // remove calclation for i
            st.erase(st.find(arr[i]));
            i++;
        }

        if(i <= j && *(st.rbegin()) - *(st.begin()) <= k) {
            ans += (j-i+1);
        }

        j++;
    }

    cout << ans << endl;
    return 0;
}