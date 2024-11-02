#include<bits/stdc++.h>
using namespace std;


// bool comparatorLB(string s, string key) {
//     // return true if currstr < key
//     if(s.length() < key.length()) {
//         return s.substr(0, key.length()) < key;
//     }
//     // string pref = s.substr(0, key.length());
//     return s.compare(0, key.length(), key) < 0;
// }

// bool comparatorUB(string s, string key) {
//     // cout <<s << " " << key << endl;
//     // return true if currstr < key
//     if(s.length() < key.length()) {
//         return s.substr(0, key.length()) < key;
//     }
    
//     string pref = s.substr(0, key.length());
//     return pref <= key;
//     // return s.compare(0, key.length(), key) <= 0;
// }

int findStart(int n, string contact[], string key) {

    int start = 0;
    int end = n-1;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end-start)/2;

        // check if prefix == key -> move left
        // if not and string > key -> move left ow right 

        string curr = contact[mid];

        if(curr.length() >= key.length()) {
            string pref = curr.substr(0, key.length());
            if(pref == key) {
                ans = mid;
                end=mid-1;
            } else if(pref > key) {
                end=mid-1;
            }
            else start=mid+1;
        } else {
            if(curr > key) end=mid-1;
            else start=mid+1;
        }
    }
    return ans;
}


int findEnd(int n, string contact[], string key) {

    int start = 0;
    int end = n-1;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end-start)/2;

        // check if prefix == key -> move left
        // if not and string > key -> move left ow right 

        string curr = contact[mid];

        if(curr.length() >= key.length()) {
            string pref = curr.substr(0, key.length());
            if(pref == key) {
                ans = mid;
                start=mid+1;
            } else if(pref > key) {
                end=mid-1;
            }
            else start=mid+1;
        } else {
            if(curr > key) end=mid-1;
            else start=mid+1;
        }
    }
    return ans;
}



class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> res;
        
        sort(contact, contact+n);
        for(int i=0;i<n;i++) cout << contact[i] << " , ";
        cout << endl;
        
        int sLen = s.length();
        for(int i=1;i<=sLen;i++) {
            string pref = s.substr(0, i);
            cout << pref << " - " << endl;
            
            int firstIdx = findStart(n, contact, pref);
            
            int lastIdx = findEnd(n, contact, pref);
            // if(lastIdx == -1) lastIdx = 
            
            vector<string> currRes;
            if(firstIdx == -1) {
                res.push_back(currRes);
                continue;
            }
            
            cout << "first: " << contact[firstIdx] << endl;
            cout << "last: " << contact[lastIdx]<< endl;
            
            for(int j=firstIdx;j<=lastIdx;j++) {
                if(j == firstIdx || (j > firstIdx && contact[j] != contact[j-1]))
                currRes.push_back(contact[j]);
            }
            
            res.push_back(currRes);
        }
        return res;
    }
};

int main() {
    string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    string query = "geeips";

    int n = 3;

    Solution s;
    s.displayContacts(n, contact, query);
}