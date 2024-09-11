#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    vector<int> b(m, 0);

    for(auto &it : a) cin >> it;
    for(auto &it : b) cin >> it;

    lli noOfEqualPairs = 0;

    int i = 0;
    int j = 0;

    while(i < n && j < m) {
        if(a[i] != b[j]) {
            if(a[i] > b[j]) j++;
            else i++;
        } else {
            // now find all equal elements 
            int startIdxA = i;
            int startIdxB = j;

            while(i < n-1 && a[i+1] == a[i]) i++;
            while(j < m-1 && b[j] == b[j+1]) j++;

            int noOfA = i - startIdxA + 1;
            int noOfB = j - startIdxB + 1;

            noOfEqualPairs += (lli)noOfA * (lli)noOfB;
            i++;
            j++;
        }
    }

    cout << noOfEqualPairs << endl;

    return 0;
}