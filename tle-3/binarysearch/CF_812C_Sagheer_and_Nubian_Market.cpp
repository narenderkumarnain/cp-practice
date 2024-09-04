#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
/* template end here */

/* problem code here */

/**
 * base cost of al items are given
 * 
 * while buying -> the cost is given by 
 * xj -> a[xj] + xj x k (k is the no of items she choose to buy)
 * 
 * find max no of items, with min cost
 * 
 *  TC
 * 3 11
   2 3 5

   [2 + 1*3, 3 + 2*3, 5 + 3*3] = [5, 9, 14]

   only two items -> 

   algorithm
   - first find how many items he can buy at max with this budget
   - for count of items -> find minimum budget he can assign that;s the answer

   first binary search then optimization using some dp or something lets see.



 */

pair<bool,int> checkIfPossible(
    vector<lli> &baseCost,
    lli noOfItems,
    int budget
) {
    // O(N) + O(NlogN) + O(k)
    vector<lli> newCost(baseCost.size());
    for(lli i=0;i<baseCost.size();i++) {
        newCost[i]=baseCost[i] + noOfItems * (i+1);
    }

    // sort ascending 
    sort(newCost.begin(), newCost.end());

    lli maxCost = 0;
    for(lli i=0;i<noOfItems;i++) {
        maxCost += newCost[i];
    }

    if(maxCost > budget) {
        return {false, 0};
    }

    return {true, maxCost};
}

int main() {
    int n, s;
    cin >> n >> s;

    vector<lli> baseCost(n);
    for(auto &it: baseCost) {
        cin >> it;
    }

    lli start = 0;
    lli end = n;

    lli ansItems = 0, ansBudget = 0;
    while(start <= end) {
        lli mid = start + (end-start)/2;

        auto res = checkIfPossible(baseCost, mid, s);

        if(res.first == true) {
            ansItems = mid;
            ansBudget = res.second;
            start = mid+1;
        } else {
            end=mid-1;
        }
    }

    cout << ansItems << " " << ansBudget;
    return 0;
}