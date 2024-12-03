#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int> skillMap;
        int noOfSkills = req_skills.size();
        for(int i=0;i<noOfSkills;i++) skillMap[req_skills[i]] = i;
        int noOfPeople = people.size();

        // vector dp(noOfPeople, vector((1 << noOfSkills)), -1);
        vector<vector<int>> dp(noOfPeople, vector<int>((1 << noOfSkills), -1));

        function<int(int,int)> fn = [&](int idx, int skillsCovered) -> int {
            if(skillsCovered == ((1 << noOfSkills)-1)) return 0; // all covered 
            if(idx == noOfPeople) return 100; // max possible value
            if(dp[idx][skillsCovered] != -1) return dp[idx][skillsCovered];
            int oldCovered = skillsCovered;
            for(int i=0;i<people[idx].size();i++){
                oldCovered = (oldCovered | (1 << skillMap[people[idx][i]]));
            }
            int ans = min(
                fn(idx+1, skillsCovered),
                1 + fn(idx+1, oldCovered)
            );
            dp[idx][skillsCovered] = ans;
            return ans;
        };

        int ansSize = fn(0,0);
        // cout << ans << endl;
        // answer construction for final answer
        vector<int> ans;
        int a = 0, b = 0;
        while(true) {
            if(a == noOfPeople) {
                break;
            }
            if((a < noOfPeople-1 && dp[a][b] == dp[a+1][b])) {
                // don not take it
                a++;
                continue;
            } else if((a == noOfPeople-1 && b == ((1 << noOfSkills)-1))){
                a++;
                continue;
            } else if((a == noOfPeople-1 && b < ((1 << noOfSkills)-1))) {
                ans.push_back(a);
                a++;
                break;
            }
            else {
                int newMask = b;
                for(int i=0;i<people[a].size();i++){
                    newMask = (newMask | (1 << skillMap[people[a][i]]));
                }
                ans.push_back(a);
                a++;
                b = newMask;
            }
        }
        return ans;
    }
};