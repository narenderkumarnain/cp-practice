#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 

/* template end here */

int noOfEleGTE(vector<int> nums, int start, int end, int val) {
    /**
     * no of elements greater than equal to value
     * = keep looking for element smaller than this and saving ans 
     */
    int e = end;
    // int totalCount = end-start+1;
    int ans = -1;
    while(start <= end) {
        int mid = start + (end-start)/2;
        // cout << "this: " <<start << " " << end << " " << mid << endl;;
        if(nums[mid] >= val) {
            ans = mid;
            end=mid-1;
        } else {
            start = mid + 1;
        }
    }
    if(ans == -1) {
        return 0;
    }
    return e-ans+1;
}


int main() {
    int n;
    cin >> n;
    vector<lli> nums(n);
    for(int i=0;i<n;i++){
        lli t;
        cin >> t;
        nums[i] = abs(t);
    }

    sort(nums.begin(), nums.end());

    lli noOfPairs = 0;
    for(int i=0;i<n;i++) {
        // int notOfNotEligible = noOfEleGTE(nums, i, n-1, 2*nums[i]+1);
        // // cout << i << " nums " << notOfNotEligible << endl; 
        // noOfPairs += (n-i-1) - notOfNotEligible;

        // to resolve tle
        auto itr = upper_bound(nums.begin(), nums.end(), 2*nums[i]);
        // itr--;
        if(itr == nums.end()) {
            noOfPairs += n - i-1;
            continue;
        }
        noOfPairs += itr - nums.begin() -i - 1;
    }

    cout << noOfPairs << endl;
    return 0;
}