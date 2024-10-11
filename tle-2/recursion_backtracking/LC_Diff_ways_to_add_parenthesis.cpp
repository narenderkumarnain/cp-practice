#include<bits/stdc++.h>
using namespace std;

unordered_map<string, vector<int>> dp;
class Solution {
    vector<int> compute(vector<int> &a, vector<int> &b, char opt) {
        vector<int> ans;
        for(int x: a) {
            for(int y: b) {
                switch(opt) {
                    case '+':
                        ans.push_back(x + y);
                        break;
                    case '-':
                        ans.push_back(x - y);
                        break;
                    case '*':
                        ans.push_back(x * y);
                        break;
                    case '/':
                        if(y != 0) ans.push_back(x / y);
                        break;
                }
            }
        }
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        if(dp.find(expression) != dp.end()) {
            return dp[expression];
        }
        vector<int> finalAns;
        
        int n = expression.size();
        bool anyOps = false;
        for(int i=0;i<n;i++) {
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
                anyOps = true;
                vector<int> ways1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> ways2 = diffWaysToCompute(expression.substr(i+1, n - i-1));

                // combination and then solution;
                vector<int> ans = compute(ways1, ways2, expression[i]);
                for(auto aa: ans) finalAns.push_back(aa);
            }
        }

        if(anyOps == false) {
            int val = 0;
            for(int i=0;i<n;i++) {
                val = (val * 10) + (expression[i] - '0');
            }

            finalAns.push_back(val);
        }

        dp[expression] = finalAns;

        return finalAns;
    }
};