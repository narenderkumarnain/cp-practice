#include<bits/stdc++.h>
using namespace std;
struct Node {
    vector<int> children;
    int noOfWordsEndingHere = 0, totalWords = 0;
    Node() {
        children = vector<int>(26, -1);
    }
};
class Trie {
    int root = -1;
    vector<Node> nodes;
public:
    Trie() {
        nodes.push_back(Node());
        root = 0;
    }
    
    void insert(string word) {
        int n = word.size();
        int idx = 0;
        int curr = root;
        while(idx < n) {
            int num = word[idx]-'a';
            // insert this word 
            if(nodes[curr].children[num] == -1) {
                nodes.push_back(Node());
                nodes[curr].children[num] = nodes.size()-1;
            } 
            nodes[curr].totalWords++;
            curr = nodes[curr].children[num];

            // insert the char
            if(idx == n-1) {
                nodes[curr].noOfWordsEndingHere++;
            }
            idx++;
        }
    }
    
    bool search(string word) {
        int n = word.size();
        int idx = 0;
        int curr = root;
        while(idx < n) {
            int num = word[idx]-'a';
            if(nodes[curr].children[num] == -1) return false;


            curr = nodes[curr].children[num];
            idx++;
            if(idx == n) {
                if(nodes[curr].noOfWordsEndingHere > 0) return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        int idx = 0;
        int curr = root;
        while(idx < n) {
            int num = prefix[idx]-'a';
            if(nodes[curr].children[num] == -1) {
                return false;
            }

            curr = nodes[curr].children[num];
            idx++;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */