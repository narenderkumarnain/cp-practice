#include<bits/stdc++.h>
using namespace std;

/* template under progress */
#define lli long long int 
#define ld long double
/* template end here */

/* problem code here */

class Solution {
public:
    bool predicate(vector<int> &nums, int dis, int k) {
        // all pairs with dis <= dis
        int n = nums.size();
        int cnt = 0;

        int j = 0;
        for(int i=0;i<n;i++) {
            while(j < n && nums[j]-nums[i] <= dis){
                j++;
                // cout << "j now: " << j << " i: " << i << " " << nums[j]-nums[i] << endl;
            }
            if(j < i) break;
            // cout << "ia nd j " << i << " " << j << endl;
            cnt += (j-i)-1;
        }

        // cout << "final: " << cnt << " " << dis << endl;
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        /*
            observations
            - n <= 10^4 -> O(n^2) solution will be allowed
            - heap solution: make a maxheap of size k 
            - if new ans < max of heap -> pop and push
            - are duplicates counted -> i guess should not 

            time complexity: O(N^2).O(log(k)) + O(1) or O(log(N))

            binary search:
            fn(x) -> count of pairs having distance <= x
        */

        // binary search
        // predicate function: if not of pairs with distance <= dis >= k
        // find the first true of this 
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = 1e6;

        int ans = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;

            if(predicate(nums, mid, k)) {
                // cout << "true: " << mid << endl;
                ans = mid;
                end = mid-1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}