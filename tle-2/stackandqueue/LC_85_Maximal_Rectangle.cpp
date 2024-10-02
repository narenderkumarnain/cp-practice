#include<bits/stdc++.h>
using namespace std;


class Solution {
    int helper(vector<int> & vec) {
        int n = vec.size();
        for(auto x: vec) cout << x << " ";
        cout << endl;
        // next smallest right 
        // next smallest left
        stack<int> nsr, nsl;

        vector<int> nextSmallestLeft(vec.size(), -1);
        for(int i=n-1;i>=0;i--) {
            while(!nsl.empty() && vec[nsl.top()] >= vec[i]) nsl.pop();
            if(!nsl.empty()) nextSmallestLeft[i]=nsl.top();
            nsl.push(i);
        }

        int res = 0;

        for(int i=0;i<n;i++) {
            while(!nsr.empty() && vec[nsr.top()] >= vec[i]) nsr.pop();
            int nextSmallestrt = -1;
            if(!nsr.empty()) nextSmallestrt = nsr.top();
            nsr.push(i);

            if(nextSmallestrt == -1 && nextSmallestLeft[i] == -1) {
                res = max(res, n * vec[i]);
            } else if(nextSmallestrt == -1) {
                res = max(res, (nextSmallestLeft[i]) * vec[i]);
                // cout << "this case: " <<nextSmallestLeft[i]<< endl;
            } else if(nextSmallestLeft[i] == -1) {
                res = max(res, (n - nextSmallestrt - 1) * vec[i]);
            } else {
                res = max(res, (nextSmallestLeft[i]-nextSmallestrt-1) * vec[i]);
            }
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> vec(rows);
        vec[0] = vector<int>(cols, 0);
        for(int i=0;i<cols;i++) {
            if(matrix[0][i] == '1') vec[0][i]++;
        }

        for(int i=1;i<rows;i++) {
            vec[i] = vector<int>(cols, 0);
            for(int j=0;j<cols;j++) {
                if(matrix[i][j] == '1') {
                    vec[i][j] = 1 + vec[i-1][j];
                }
            }
        }

        int ans = 0;
        for(int i=0;i<rows;i++) {
            ans = max(ans, helper(vec[i]));
        }

        return ans;
    }
};