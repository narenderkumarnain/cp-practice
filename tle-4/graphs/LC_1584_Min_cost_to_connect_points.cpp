#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops,O3,Ofast") //even 10^8+ also works with this


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // kruskals and prims algorithm
        // prims tc = ElogV
        int n=points.size();
        set<pair<int,int>> pq;
        pq.insert({0,0});
        vector<bool> visited(points.size(), false);
        vector<int> minWtEdge(n, INT_MAX);


        int sm = 0;

        while(!pq.empty()){
            auto [wt, node] = *pq.begin();
            pq.erase(pq.begin());

            if(visited[node])continue;
            visited[node]=true;
            sm += wt;

            for(int i=0;i<n;i++){
                if(i!=node){
                    int dis = abs(points[node][0]-points[i][0]) + abs(points[node][1]-points[i][1]);
                    if(dis < minWtEdge[i]) {
                        auto it = pq.find({minWtEdge[i], i});
                        if(it!=pq.end())pq.erase(it);
                        pq.insert({dis, i});
                        minWtEdge[i]=dis;
                    }
                }
            }
        }

        return sm;

    }
};