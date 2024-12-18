#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,O3,Ofast") //even 10^8+ also works with this


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n];
        for(int i=0;i<flights.size();i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            graph[from].push_back({to , price});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // using bellman ford algorithm
        for(int i=1;i<=k+1;i++){
            auto tmp = dist;
            for(int a=0;a<n;a++){
                if(dist[a]!=INT_MAX){
                    for(auto [v, wt]: graph[a]){
                        tmp[v] = min(tmp[v], dist[a]+wt);
                    }
                }
            }
            dist=tmp;
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};