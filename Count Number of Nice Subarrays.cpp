#include <bits/stdc++.h>
using namespace std;

// Getting j to a point where it makes a window valid
// The approach is to count the left even elements and right even elements of minimum length valid subarray window.
// ans += (lCount+1)*(rCount+1), these are the total subsets.

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, oddCount = 0;
        int i = 0, j = 0, lCount = 0, rCount = 0, n = nums.size();
        while(j<n && oddCount < k){
            if(nums[j]%2 != 0) {
                oddCount++;
                if(oddCount == k) break;
            }
            j++;
        }
        while(j<n && i<n){
            while(i<n && nums[i]%2 == 0){
                lCount++;
                i++;
            }
            j++;
            while(j<n && nums[j]%2 == 0){
                rCount++;
                j++;
            }
            i++;
            ans += (lCount+1)*(rCount+1);
            lCount = 0;
            rCount = 0;
        }
        return ans;
    }
};

int main(){

    return 0;
}