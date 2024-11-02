#include<bits/stdc++.h>
using namespace std;

struct Node {
    vector<int> children;
    int nodeEndVal = 0;
    int totalSum = 0;

    Node() {
        children = vector<int>(26, -1);
        nodeEndVal = -1;
        totalSum = 0;
    }
};

class MapSum {
    vector<Node> nodes;
    int root;
    // unordered_map<stringm÷>
public:
    MapSum() { 
        nodes.push_back(Node());
        root = nodes.size()-1;
    }
    
    void insert(string key, int val) {
        int n  = key.length();
        int idx = 0;

        int prevVal = findVal(key);

        int smDelta = val;

        if(prevVal != -1) {
            smDelta = val - prevVal;
        }

        int curr = root;
        while(idx < n) {
            int ch = key[idx]-'a';
            if(nodes[curr].children[ch] == -1) {
                nodes.push_back(Node());
                nodes[curr].children[ch] = nodes.size()-1;
            }
            curr = nodes[curr].children[ch];
            nodes[curr].totalSum += smDelta;
            if(idx == n-1) {
                nodes[curr].nodeEndVal = val;
            }
            idx++;
        }
    }

    int findVal(string key) {
        int res = -1;
        int n = key.length();
        int idx = 0;

        int curr = root;
        while(idx < n) {
            int ch = key[idx]-'a';
            if(nodes[curr].children[ch] == -1) return -1;
            curr = nodes[curr].children[ch];

            if(idx == n-1 ) {
                if(nodes[curr].nodeEndVal != -1) {
                    res = nodes[curr].nodeEndVal;
                }
            }
            idx++;
        }
        return res;
    }   
    
    int sum(string prefix) {
        int n = prefix.length();
        int idx = 0;
        int curr = root;
        int res = 0;
        while(idx < n) {
            int ch = prefix[idx]-'a';

            if(nodes[curr].children[ch] == -1) return 0;
            curr = nodes[curr].children[ch];

            if(idx == n-1) {
                res = nodes[curr].totalSum;
            }
            idx++;
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */