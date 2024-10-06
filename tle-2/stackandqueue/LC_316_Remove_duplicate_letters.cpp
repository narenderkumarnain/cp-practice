#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        map<char, int> mp;
        int n = s.length();
        map<char, bool> added;

        for(int i=0;i<n;i++) {
            mp[s[i]]++;
            added[s[i]] = false;
        }

        for(int i=0;i<n;i++) {
            if(mp[s[i]] >= 1 && added[s[i]] == false) {
                // remove all more than that
                string newAns = "";

                int idx;
                for(idx=ans.length()-1;idx>=0;idx--){
                    char ch = ans[idx];
                    bool deleted = false;
                    if(ch > s[i] && mp[ch] > 0) {
                        // it still have some left
                        // remove it
                        added[ch] = false;
                        deleted = true;
                    } else {
                        newAns = ch + newAns;
                    }

                    if(deleted == false) {
                        break;
                    }
                }
                idx--;
                for(;idx >= 0; idx--) {
                    newAns = ans[idx] + newAns;
                }

                // push this 
                newAns += s[i];
                added[s[i]] = true;
                mp[s[i]]--;

                ans = newAns;
            } else {
                if(added[s[i]] == true && mp[s[i]] >= 1) mp[s[i]]--;
            }
        }
        return ans;
    }
};