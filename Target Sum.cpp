#include <bits/stdc++.h>
using namespace std;

// Reccursion
class Solution {
private:
    int helper(vector<int>& nums, int target,int n, int i){
        if(i == n){
            if(target == 0) return 1;
            return 0;
        }
        int minus = helper(nums,target-nums[i],n,i+1);
        int plus = helper(nums,target+nums[i],n,i+1);
        return minus + plus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(nums,target,n,0);
    }
};

// DP-Memoization
class Solution {
private:
    int helper(vector<int>& nums, unordered_map<int,unordered_map<int,int>>&dp, int target,int n, int i){
        if(i == n){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[i][target]) return dp[i][target];
        int minus = helper(nums,dp,target-nums[i],n,i+1);
        int plus = helper(nums,dp,target+nums[i],n,i+1);
        return dp[i][target] = minus + plus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,unordered_map<int,int>>dp;
        return helper(nums,dp,target,n,0);
    }
};

// DP-Memoized 
class Solution {
private:
    int helper(vector<int>& nums, int target, int n, int i, vector<vector<int>>& memo) {
        if (i == n) {
            if (target == 0) return 1;
            return 0;
        }
        if (memo[i][target + 2000] != 0) {
            return memo[i][target + 2000];
        }
        int minus = helper(nums, target - nums[i], n, i + 1, memo);
        int plus = helper(nums, target + nums[i], n, i + 1, memo);
        memo[i][target + 2000] = minus + plus;
        return memo[i][target + 2000];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(4001, 0));
        return helper(nums, target, n, 0, memo);
    }
};


// DP-Tabulization
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int,unordered_map<int,int>>dp;
        dp[n][0] = 1;
        // It's -sum to +sum because we are iterating in this range to acheive target == 0.
        for (int i = n-1; i >= 0; i--) {
            for (int j = -sum; j <= sum; j++) {
                int minus = dp[i+1][j-nums[i]];
                int plus = dp[i+1][j+nums[i]];
                dp[i][j] = minus + plus;
            }
        }
        return dp[0][target];
    }
};

int main(){

    return 0;
}