#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int N = 1e8;
	vector<int> spf(N);
	for(int i=0;i<N;i++) spf[i] = i;
	for(int i=2;i*i < N;i++) {
	    if(spf[i] == i) {
	        for(int j=i*i;j<N;j+=i) {
	            spf[j] = i;
	        }
	    }
	}
	
	int t;
	cin >> t;
	while(t--) {
	    int x, y;
	    cin >> x >> y;
	    
	    set<int> stx, sty;
	    
	    string X = to_string(x);
	    string Y = to_string(y);
	    
	    sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
	    
	    do {
	        if(X[0] == '0') continue;
	       int t = stoi(X);
	       while(t > 1) {
	           stx.insert(spf[t]);
	           t /= spf[t];
	       }
	    } while(next_permutation(X.begin(), X.end()));
	    
	    do {
	       if(Y[0] == '0') continue;
	       int t = stoi(Y);
	       while(t > 1) {
	           sty.insert(spf[t]);
	           t /= spf[t];
	       }
	    } while(next_permutation(Y.begin(), Y.end()));
	    
	    auto itx = stx.rbegin();
	    auto ity = sty.rbegin();
	    
	   // cout << stx.size() << " " << sty.size() << endl;
	       
	    int ans = 1;
	    for(auto x: stx) {
	        if(sty.find(x) != sty.end()) ans = x;
	    }
	    
	    cout << ans << endl;
 	}

}
