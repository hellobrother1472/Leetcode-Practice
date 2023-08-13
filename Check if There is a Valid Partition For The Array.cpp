#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool helper(vector<int>& dp, vector<int>& nums, int n, int i) {
        // Base case: If we've gone beyond the array size, we've successfully partitioned
        if (i >= n) return true;
        
        // Base case: If we are at the last element, we cannot partition further
        if (i == n - 1) return false;
        
        // If we've already computed and memoized the result for this index, return it
        if (dp[i] != -1) return dp[i];
        // Checking all conditions
        // If the current element and the next element are the same
        if (i + 1 < n && nums[i] == nums[i + 1]) {
            // Check if we can create a valid partition taking the current and check for further (for 2 equal)
            if (helper(dp, nums, n, i + 2)) return dp[i] = true;
            
            // If we have three equal consecutive then check for further taking current
            if (i + 2 < n && nums[i + 2] == nums[i] && helper(dp, nums, n, i + 3)) return dp[i] = true;
        }
        else if (i + 2 < n && nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1) {
            // if three consecutive increasing subarray
            if (helper(dp, nums, n, i + 3)) return dp[i] = true;
        }

        // Store the result in the dp array and return it
        return dp[i] = false;
    }
public:
    // Function to determine if a valid partition can be created from the given array
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // Memoization array to store computed results
        return helper(dp, nums, n, 0); // Call the helper function to solve the problem
    }
};


int main(){

    return 0;
}