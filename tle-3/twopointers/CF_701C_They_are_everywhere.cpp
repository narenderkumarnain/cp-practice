#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    int n;
    cin >> n;

    string arr;
    cin >> arr;

    set<char> st;

    for(int i=0;i<n;i++) st.insert(arr[i]);

    int noOfUnique = st.size();

    int i = 0;
    int j = 0;

    map<char, int> mp;

    int ans = n;

    while(j < n) {
        // add calculation for map
        mp[arr[j]]++;

        while(i <= j && mp.size() == noOfUnique) {
            ans = min(ans, j-i+1);

            mp[arr[i]]--;
            if(mp[arr[i]] == 0) mp.erase(arr[i]);
            i++;
        }

        j++;
    }

    cout << ans << endl;
    return 0;
}