#include<bits/stdc++.h>
using namespace std;

class Solution {
     int noOfEleLTE(vector<int>& nums, int val) {
        // last when nums[i] <= val
        int start = 0;
        int end = nums.size()-1;

        int ans = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;

            if(nums[mid] > val) {
                end = mid -1;
            } else {
                ans = mid;
                start = mid + 1;
            }

        }
        return ans + 1;
    }
     int findTheElement(vector<int>& nums1, vector<int>& nums2, int minLessOrEqualRequired) {
        int n = nums1.size();
        int m = nums2.size();

        int start = 1e9;
        int end = 0;

        if(n > 0) start = min(start, nums1[0]);
        if(m > 0) start = min(start, nums2[0]);

        if(n > 0) end = max(end, nums1[n-1]);
        if(m > 0) end = max(end, nums2[m-1]);

        // cout << "here" << start << end << endl;

        int ans = 0;
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            int totalCount = noOfEleLTE(nums1, mid) + noOfEleLTE(nums2, mid);

            if(totalCount >= minLessOrEqualRequired) {
                // cout << "ans" << mid << totalCount << endl;
                ans = mid;
                end=mid-1;
            } else {
                start=mid+1;
            }

        }
        return ans;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // handle n or m zero


        if ((n+m) %2 == 0) {
            // even
            // find two elements now
            // and average them
            int t = (m+n) / 2;
            int a = findTheElement(nums1, nums2, t);
            int b = findTheElement(nums1, nums2, t+1);
            // cout << "ands" << a << " " << b << endl;
            return (double(a)+double(b)) / 2;
        } else {
            // odd 
            int noOfElementsLessThanAndEqual = (n+m+2-1)/2; // floor of 2
            // cout << noOfElementsLessThanAndEqual << endl;
            return double(findTheElement(nums1, nums2, noOfElementsLessThanAndEqual));
        }
        return 0.0;
    }
};