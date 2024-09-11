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

    string s;
    cin >> s;
    string cards;
    cin >> cards;

    vector<int> hashmap(26, 0);


    for(int i=0;i<m;i++){
        hashmap[cards[i] - 'a']++;
    }

    int i=0;
    int j=0;

    lli finalCount = 0;

    int negativeCount = 0;
    while(j < n) {
        // add computation for jth
        hashmap[s[j] - 'a']--;
        if(hashmap[s[j] - 'a'] < 0) {
            negativeCount++;
        }

        // increement i till condition is true
        while(i <= j && negativeCount > 0) {
            hashmap[s[i] - 'a']++;
            if(hashmap[s[i] - 'a'] == 0) negativeCount--;
            i++;
        }

        // update answer 
        if(negativeCount == 0) {
            finalCount += (j-i)+1;
        }

        // increment j
        j++;
    }

    cout << finalCount << endl;
    return 0;
}