#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,O3,Ofast") //even 10^8+ also works with this


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int a, int b, int m, int n){
    if(a>=0&&a<m&&b>=0&&b<n)return true;
    return false;
}
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));

        set<tuple<int,int,int>> pq;
        pq.insert({0, 0, 0});
        dist[0][0]=0;

        while(!pq.empty()){
            auto [currDist, nodex, nodey] = *pq.begin();
            pq.erase(pq.begin());

            for(int i=0;i<4;i++){
                int newx = nodex+dx[i];
                int newy = nodey+dy[i];
                if(isValid(newx, newy, m, n)){
                    int newDist=currDist;
                    if(grid[newx][newy] == 1) {
                        newDist++;
                    }
                    if(newDist < dist[newx][newy]){
                        auto it = pq.find({dist[newx][newy], newx, newy});
                        if(it!=pq.end())pq.erase(it);
                        dist[newx][newy] = newDist;
                        pq.insert({dist[newx][newy], newx, newy});
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};