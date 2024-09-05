#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */
bool query(int num) {
    cout << num << endl;
    string ans;
    cin >> ans;
    if(ans == "yes") return true;
    else return false;
}


int main() {
    vector<int> prime = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49, 
    };

    int count = 0;
    for(int i=0;i<prime.size();i++) {
        bool ans = query(prime[i]);
        if(ans == true) {
            count++;
        }
    }

    if(count > 1) {
        cout << "composite" << endl;
    } else {
        cout << "prime" << endl;
    }
    return 0;
}