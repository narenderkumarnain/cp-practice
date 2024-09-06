#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

bool predicate(vector<lli> &prices, lli maxTickets, lli k, lli a, lli x, lli b , lli y) {
    // vector<lli> pricesAgain(maxTickets, -1);
    // prices is sorted
    lli lcm = abs(a * b) / __gcd(a, b);

    lli aCount = maxTickets / a;
    lli bCount = maxTickets / b;

    lli commonCount = maxTickets / lcm;

    // cout << aCount << " " << bCount << " " << commonCount << endl;

    lli totalContribution = 0;
    // int totalAmount 
    // assign top max to all columns 
    lli currIdx = 0;
    for(lli i=1;i<=commonCount;i++) {
        // lli idx = lcm * i;
        // pricesAgain[idx] = prices[currIdx];
        totalContribution += ((x + y) * prices[currIdx]) / 100; 
        if(totalContribution >= k) return true;
        currIdx++;
    }

    lli contribA = 0;
    lli idxA = currIdx;
    for(lli i=1;i<=aCount;i++) {
        if((i * a) % lcm != 0){
            // not already done
            contribA += (x * prices[idxA]) / 100;
            idxA++;
        }
    }
    for(lli i=1;i<=bCount;i++) {
        if((i * b) % lcm != 0){
            // not already done
            contribA += (y * prices[idxA]) / 100;
            idxA++;
        }
    }

    lli contribB = 0;
    lli idxB = currIdx;
    for(lli i=1;i<=bCount;i++) {
        if((i * b) % lcm != 0){
            // not already done
            contribB += (y * prices[idxB]) / 100;
            idxB++;
        }
    }
    for(lli i=1;i<=aCount;i++) {
        if((i * a) % lcm != 0){
            // not already done
            contribB += (x * prices[idxB]) / 100;
            idxB++;
        }
    }

    // cout << "contribs: " << totalContribution << " " << contribA << " " << contribB << endl;
    totalContribution += max(contribA, contribB);
    // cout << "maxTickets: " << maxTickets << " - " << totalContribution << endl;
    return totalContribution >= k;
}

int main() {
    int q;
    cin >> q;

    while(q--) {
        lli n;
        cin >> n;

        vector<lli> prices(n);
        for(auto &it: prices) {
            cin >> it;
        }

        // sort descending
        sort(prices.begin(), prices.end(), greater<lli>());

        lli x, a;
        lli y, b;

        cin >> x >> a;
        cin >> y >> b;

        lli k;
        cin >> k;

        // binary search on predicate(x) : is getting atleast k amount possible using atmost x tickets
        lli start = 1;
        lli end = n;

        lli ans = -1;
        while(start <= end) {
            lli mid = start + (end-start)/2;

            if(predicate(prices, mid, k, a, x, b , y)) {
                ans = mid;
                end = mid-1;
            } else {    
                start = mid+1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}