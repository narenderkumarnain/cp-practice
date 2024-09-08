#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> st1, st2;

        vector<double> ans(n-k+1);
        int ansIdx = 0;

        int i = 0;
        for(int j=0;j<n;j++) {
            // just add the jth element
            if(st1.empty() == true || nums[j] <= *st1.rbegin()) {
                // first add to st1
                st1.insert(nums[j]);

                if(st1.size() > st2.size() + 1) {
                    int ele = *st1.rbegin();
                    st1.erase(st1.find(ele));
                    st2.insert(ele);
                }
            } else {
                // first add to st2
                st2.insert(nums[j]);
                if(st1.size() < st2.size()) {
                    int ele = *st2.begin();
                    st2.erase(st2.find(ele));
                    st1.insert(ele);
                }
            }


            if(j-i+1 < k) {
                continue;
            }

            // add the answer
            /*
                 odd: 1 2 3 4 5
                 (3, 2)

                 even: 1 2 3 4
            */
            double currAns;
            if(!(k & 1)) {
                currAns = (double(*st1.rbegin()) + double(*st2.begin())) / 2;
            } else {
                currAns = *st1.rbegin();
            }
            // ans.push_back(currAns);
            ans[ansIdx++] = currAns;


            // increment the i and remove it's computation
            int toRemoveEle = nums[i];
            i++;

            // remove i computation
            auto tt = st1.find(toRemoveEle);
            if(tt != st1.end()) {
                st1.erase(tt); // to not remove all copies of ele
                if(st1.size() < st2.size()) {
                    int ele = *st2.begin();
                    st2.erase(st2.find(ele));
                    st1.insert(ele);
                }
            } else {
                st2.erase(st2.find(toRemoveEle));
                // x , x-1 or x+1, x-1
                if(st1.size() > st2.size() + 1) {
                    int ele = *st1.rbegin();
                    st1.erase(st1.find(ele));
                    st2.insert(ele);
                }
            }
        }

        return ans;
    }
};