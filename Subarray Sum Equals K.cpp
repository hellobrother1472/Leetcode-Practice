#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// If the array given has non negetive.
// DP signifies in how many ways we can make the remaining currSum from the remaining array
// Reccursive
int mod = 1e9 + 7;

int helper(vector<int>& nums, int k, int currSum, int i){
    if(i == nums.size()){
        if(currSum == k) return 1;
        return 0;
    }
    return ((helper(nums,k,currSum+nums[i],i+1) % mod) + (helper(nums,k,currSum,i+1) % mod)) % mod;
}

int findWays(vector<int>& arr, int k)
{
	return helper(arr,k,0,0) % mod;
}

// DP
int mod = 1e9 + 7;

int helper(vector<int>& nums, int k, int currSum, int i,vector<vector<int>>&dp){
    if(i == nums.size()){
        if(currSum == k) return 1;
        return 0;
    }
	if(currSum > k) return 0;
	if(dp[i][currSum] != -1) return dp[i][currSum];
    return dp[i][currSum] = ((helper(nums,k,currSum+nums[i],i+1,dp) % mod) + (helper(nums,k,currSum,i+1,dp) % mod)) % mod;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
	return helper(arr,k,0,0,dp) % mod;
}


// The brute force is simple, we just need to generate all sub-arrays, check the sum, and update the number of subarrays we found so far.

// Optimized way is to use prefix concept 
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); // take the size of the array
        
        int prefix[n]; // make a prefix array to store prefix sum
        
        prefix[0] = arr[0]; // for element at index at zero, it is same
        
        // making our prefix array
        for(int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; // declare an unordered map
        
        int ans = 0; // to store the number of our subarrays having sum as 'k'
        
        for(int i = 0; i < n; i++) // traverse from the prefix array
        {
            if(prefix[i] == k) // if it already becomes equal to k, then increment ans
                ans++;
            
            // now, as we discussed find whether (prefix[i] - k) present in map or not
            if(mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; // if yes, then add it our answer
            }
            
            mp[prefix[i]]++; // put prefix sum into our map
        }
        
        return ans; // and at last, return our answer
    }
};

int main()
{

    return 0;
}