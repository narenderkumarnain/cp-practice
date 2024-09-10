#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

// i still dont understand how this works 
int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &it: arr) cin >> it;

    // bool playerIsAlice = 
    // vector<int> seq;
    int i = 0;
    int j = n-1;

    // int lastEle = -1;
    // int seqSize = 0;

    while(i < n-1 && arr[i] < arr[i+1]) i++;
    while(j >= 1 && arr[j-1] > arr[j]) j--;

    // quickest possible solutions
    int lenA = i + 1;
    int lenB = n - j;
    

    // if somehow alice can reach in odd no of steps , she wins 
    if(lenA % 2 != 0 || lenB % 2 != 0) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    return 0;
}