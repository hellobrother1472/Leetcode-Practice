#include <bits/stdc++.h>
using namespace std;

// Helper function is designed in such a way that it sees argument isFirst and act according to it, we are running helper two times, one in which first element is included and last is not and second is when first element is not included and last element is included. And we are taking max of two.
class Solution {
public:
    int helper(vector<int>& nums,vector<int>&dp, int n, int i, bool isFirst){
        if(i >= n-2){
            if(i == n-1 && !isFirst) return nums[n-1];
            else if(i == n-2 && isFirst) return nums[n-2];
            else if(i > n-2 && isFirst) return 0;
            else if(i > n-1) return 0;
        }

        if(!dp[i]){
            int one = nums[i] + helper(nums,dp,n,i+2,isFirst);
            int two = helper(nums,dp,n,i+1,isFirst);
            
            dp[i] = max(one,two);
        }
        return dp[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int>dp1(n,0);
        vector<int>dp2(n,0);
        int one = helper(nums,dp1,n,1,false);
        int two = helper(nums,dp2,n,0,true);
        return max(one,two);
    }
};

// In above appraoch we are using two DPs and as the logic remains same if we change the helper function to the similar code to space optimized version of House Robber 1.
// Means as we have two choises of array like form 1 to n-1 or to 0 to n-2, so putting it and calculating both and then comparing it will be a good choice.
// Just we have to alter the code such that it will work for given array with given start and end.

class Solution {
public:
    int helper(vector<int>& nums,int n, int start, int end) {
        int fOne = nums[end], fTwo = 0;
        for(int i = end-1 ; i >= start; i--){
            int one;
            if(i==end) one = nums[i];
            else one = nums[i] + fTwo;
            int two = fOne;
            fTwo = fOne;
            fOne = max(one,two);
        }
        return fOne;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        int one = helper(nums, n-1, 1, n-1);
        int two = helper(nums, n-1, 0, n-2);
        return max(one,two);
    }
};

int main(){

    return 0;
}