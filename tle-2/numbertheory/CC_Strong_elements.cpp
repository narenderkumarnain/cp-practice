#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &it: arr) cin >> it;
        
        vector<int> prefixGcd(n, 1);
        vector<int> suffixGcd(n, 1);
        
        prefixGcd[0] = arr[0];
        for(int i=1;i<n;i++) {
            prefixGcd[i] = __gcd(prefixGcd[i-1], arr[i]);
        }
        
        suffixGcd[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--) {
            suffixGcd[i] = __gcd(arr[i], suffixGcd[i+1]);
        }
        
        int overallGcd = prefixGcd[n-1];
        
        if(overallGcd > 1) {
            cout << n << endl;
        } else {
            int count = 0;
            for(int i=0;i<n;i++) {
                int combinedGcd;
                if(i==0) combinedGcd = suffixGcd[i+1];
                else if(i==n-1) combinedGcd = prefixGcd[i-1];
                else {
                    combinedGcd = __gcd(prefixGcd[i-1], suffixGcd[i+1]);
                }
                
                if(__gcd(arr[i], combinedGcd) != combinedGcd) {
                    count++;
                }
            }
            
            cout << count << endl;
        }
    }
}
