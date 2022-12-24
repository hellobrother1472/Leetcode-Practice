#include <bits/stdc++.h>
using namespace std;

//  The approach is to find the kth element in two sorted array.
// The concept is that, we want only that number of elements till the index so we try to get those by trying the combination from first and second vector. 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2){ // so that minimum of both can be taken as n1
            return findMedianSortedArrays(nums2, nums1); 
        }
        int flag = ((n1+n2) % 2 == 0) ? 0 : 1; // Flag is for odd and even because median formula varies
        
        int start = 0, end = n1;
        int index = ((n1+n2)+1)/2; // This is the index we want as we want median(works for both odd and even)
        while(start <= end){
            int cut1 = start + (end - start)/2; // mid is the cut1
            int cut2 = index - cut1; // And the remaining one from second array or vector

            // getting l1,l2,r1,r2 and optimizing for edge cases.
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            
            if(l1<=r2 && l2<=r1){
                return flag ? max(l1,l2) : (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) end = cut1-1;
            else start = cut1+1;
        }

        return 0.0;
    }
};

int main(){
    return 0;
}
