#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    lli n , p;
    cin >> n >> p;

    vector<lli> arr(n);
    lli posCountArr = 0;
    for(auto &it: arr) {
        cin >> it;
        posCountArr += it;
    }

    lli noOfCompleteIterations = p / posCountArr;
    lli pRemaning = p % posCountArr;

    if(pRemaning == 0) {
        cout << 1 << " " << noOfCompleteIterations * n << endl;
        return 0;
    }

    lli songs = noOfCompleteIterations * n;
    lli start = 0;

    
        // solve last iteration using increasing technique
        lli i = 0;
        lli j = 0;

        lli sm_v = posCountArr;
        lli ansSizeA = 0;
        lli startA = 0;

        while(j < n) {
            sm_v -= arr[j];

            while(i <= j && sm_v < pRemaning) {
                sm_v += arr[i];
                i++;
            }

            if(i <= j && sm_v >= pRemaning)  {
                if(j-i+1 > ansSizeA) {
                    ansSizeA = j-i+1;
                    startA = (j + 1) % n;
                }
            }
            j++;
        }

        ansSizeA = n - ansSizeA;


        // solve using decreasing technique
        // find min size subarray such that sm >= pRem
        i = 0; // start
        j = 0; // end 

        sm_v = 0;

        lli ansSizeB = n;
        lli startB = 0;

        while(j < n) {
            sm_v += arr[j];

            while(i <= j && sm_v >= pRemaning) {
                if(j-i+1 < ansSizeB) {
                    ansSizeB = j-i+1;
                    startB = i;
                }
                sm_v -= arr[i];
                i++;
            }
            j++;
        }
    
    if(ansSizeA > ansSizeB) {
        songs += ansSizeB;
        start = startB;
    } else {
        songs += ansSizeA;
        start = startA;
    }

    cout << start+1 << " " << songs << endl;


    return 0;
}