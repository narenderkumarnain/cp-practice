#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    int n, r;
    cin >> n >> r;

    vector<int> dis(n);
    for(auto &it: dis) cin >> it;

    lli count = 0;

    int i = 0;
    int j = 0;

    while(j < n) {

        while(i <= j && dis[j] - dis[i] > r) {
            count += (lli)(n - j);
            // [1,4] N = 5
            i++;
        }
        j++;
    }

    cout << count << endl;
    return 0;
}