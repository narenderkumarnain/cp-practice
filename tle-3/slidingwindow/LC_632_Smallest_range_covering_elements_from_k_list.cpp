#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();

        map<int, vector<int>> mp;
        for(int i=0;i<n;i++) {
            for(int j=0;j<nums[i].size();j++) {
                // values.push_back({nums[i][j], i});
                if(mp.find(nums[i][j]) == mp.end()) mp[nums[i][j]] = {};
                mp[nums[i][j]].push_back(i);
            }
        }

        vector<pair<int,vector<int>>> values;
        for(auto it = mp.begin();it != mp.end();it++) {
            values.push_back({(*it).first, (*it).second});
        }

        // sort(values.begin(), values.end());

        vector<int> ans = {values[0].first, (*values.rbegin()).first};

        map<int,int> condition;

        int start = 0;
        for(int i=0;i<values.size();i++) {
            // add this element in calculation
            // condition[values[i].second]++;
            for(int k=0;k<values[i].second.size();k++) {
                condition[values[i].second[k]]++;
            }

            // check if condition is acquired and update answer 
            if(condition.size() == n) {
                // all n elements covered 
                int windowSize = values[i].first - values[start].first;

                if(windowSize < ans[1]-ans[0]) {
                    ans[0] = values[start].first;
                    ans[1] = values[i].first;
                    // cout << "ans upd: " << ans[0] << ": " << ans[1] << endl;
                     // ans = {start, end};
                }

                // try reducing the size of the windown by remove start elements
                while(start < i && condition.size() == n) {
                    // while the condition holds 
                    // remove the start element 
                    auto ele = values[start];
                    // condition[ele.second]--;
                    // if(condition[ele.second] == 0) condition.erase(ele.second);
                    for(int k=0;k<ele.second.size();k++) {
                        condition[ele.second[k]]--;
                        if(condition[ele.second[k]] == 0) condition.erase(ele.second[k]);
                    }
                    start++;

                    if(condition.size() == n) {
                        int windowSize = values[i].first - values[start].first;

                        if(windowSize < ans[1]-ans[0]) {
                            ans[0] = values[start].first;
                            ans[1] = values[i].first;
                            // cout << "ans upd 2: " << ans[0] << ": " << ans[1] << endl;
                        }
                    }
                }

            }
        }
        return ans;

    }
};