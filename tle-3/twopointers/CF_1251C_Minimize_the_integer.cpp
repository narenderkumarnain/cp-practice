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
        string s;
        cin >> s;
        int n = s.length();

        string even = "";
        string odd = "";
        for(int i=0;i<n;i++) {
            if((s[i] - '0') % 2 == 0) even += s[i];
            else odd += s[i];
        }

        int i = 0;
        int j = 0;

        string ans = "";

        while(i < even.size() && j < odd.size()) {
            if(even[i] < odd[j]) {
                ans += even[i];
                i++;
            } else {
                ans += odd[j];
                j++;
            }
        }

        while(i < even.size()) {
            ans += even[i];
            i++;
        }

        while(j < odd.size()) {
            ans += odd[j];
            j++;
        }
 
        cout << ans << endl;
    }
    return 0;
}