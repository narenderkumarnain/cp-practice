#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    lli n, c;
    cin >> n >> c;

    string s;
    cin >> s;

    lli i = 0;
    lli j = 0;

    lli maxlen = 0;

    lli aCount = 0;
    lli bCount = 0;

    lli rudeness = 0;

    while(j < n) {
        // add calculation for jth
        if(s[j] == 'a') {
            aCount++;
        } else if(s[j] == 'b') {
            bCount++;
            rudeness += aCount;
        }

        while(i <= j && rudeness > c) {
            // remove computation for c
             if(s[i] == 'a') {
                aCount--;
                rudeness -= bCount;
            } else if(s[i] == 'b') {
                bCount--;
            }
            i++;
        }

        // update answer 
        if(i <=j && rudeness <= c) {
            maxlen = max(maxlen, j-i+1);
        }
        j++;
    }

    cout << maxlen << endl;
    return 0;   
}