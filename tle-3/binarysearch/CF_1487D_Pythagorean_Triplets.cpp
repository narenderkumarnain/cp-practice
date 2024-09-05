#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int maxValueOfA = floor(sqrt(2 * n - 1));

        lli sm = 0;
        for(int i=1; i <= maxValueOfA; i++) {
            if((i*i + 1) % 2 != 0) {
                continue;
            }

            int c = (i*i + 1) / 2;

            if(!(c >= 1 && c <= n)) {
                continue;
            }

            int b = c - 1;

            if(!(b >= 1 && b <= n)) {
                continue;
            }

            // cout << "combination: " << i << " : " << b << " : " << c << " : " << endl;

            sm++;
        }

        cout << sm << endl;
    }
    return 0;
}