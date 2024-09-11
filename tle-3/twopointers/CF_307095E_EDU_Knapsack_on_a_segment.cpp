#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

int main() {
    // increasing type problem, update ouside the while loop
    int n, s;
    cin >> n >> s;
    vector<int> weight(n);
    for(auto &it: weight) cin >> it;
    vector<int> cost(n);
    for(auto &it: cost) cin >> it;

    int i = 0;
    int j = 0;

    lli sm_weight = 0;
    lli sm_cost = 0;

    lli maxCost = 0;
    while(j < n) {
        // add the computation for j
        sm_weight += weight[j];
        sm_cost += cost[j];

        // try to form a subarray with the condition
        while(i <= j && sm_weight > s) {
            sm_weight-=weight[i];
            sm_cost-=cost[i];
            i++;
        }

        if(i <= j) {
            maxCost = max(maxCost, sm_cost);
        }
        j++;
    }

    cout << maxCost << endl;
    return 0;
}