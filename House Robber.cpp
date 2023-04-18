#include <bits/stdc++.h>
using namespace std;

// Logic is that if you are standing at an index you have two options one is to take current element, but in this condition you can't take adjecent element so you take next to adjecent, and second is to not take current element and take the adjecent element.

// Using Reccursion
class Solution{
public:	
	int helper(vector<int>& arr, int n,int i ){
	    if(i >= n-1){
	        if(i == n-1) return arr[i]; // when it reaches last then max sum is itself so return itself
	        return 0; // if it reaches above n-1 just return 0, which keeps previous sum intact
	    }
        // Their can be these two cases possible
	    int one = arr[i] + helper(arr,n,i+2); // Take the current element and plus it with max value of one after next
	    int two = helper(arr,n,i+1); // Don't take current element and have max value of the adjecent element
	    return max(one,two);
	}
	int rob(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,n,0);
    }
};

// Using DP
class Solution {
public:
    int helper(vector<int>&arr, int n,vector<int>&dp,int i ){
	    if(i >= n-1){
	        if(i == n-1) return arr[i];
	        return 0;
	    }
	    if(!dp[i]){
	        int one = arr[i] + helper(arr,n,dp,i+2);
	        int two = helper(arr,n,dp,i+1);
	        dp[i] = max(one,two);
	    }
	    return dp[i];
	}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        return helper(nums,n,dp,0);
    }
};

// Using tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0; i--){
            int one = 1;
            if(i==n-2) one = nums[i];
            else one = nums[i] + dp[i+2];
            int two = dp[i+1];
            dp[i] = max(one,two);
        }
        return dp[0];
    }
};

// Space optimization of tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int fOne = nums[n-1], fTwo = 0;
        for(int i = n-2 ; i >= 0; i--){
            int one;
            if(i==n-2) one = nums[i];
            else one = nums[i] + fTwo;
            int two = fOne;
            fTwo = fOne;
            fOne = max(one,two);
        }
        return fOne;
    }
};

int main(){

    return 0;
}