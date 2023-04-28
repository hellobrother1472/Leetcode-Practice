#include <bits/stdc++.h>
using namespace std;

// Reccursion 1
// In reccursive calls I am having all the subsets and taking the value of totalSum, currSum and length with me as soon as length becomes half of total size of num I take the minimum value.

class Solution
{
private:
    int mini = INT_MAX;
    void helper(vector<int> &nums, int currSum, int totalSum, int i, int l1)
    {
        if (l1 == nums.size() / 2)
        {
            mini = min(mini, abs(totalSum - currSum));
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            helper(nums, currSum + nums[j], totalSum - nums[j], j + 1, l1 + 1);
        }
    }

public:
    int minimumDifference(vector<int> &nums)
    {
        if (nums.size() % 2 != 0)
            return 0;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
            totalSum += nums[i];
        helper(nums, 0, totalSum, 0, 0);
        return mini;
    }
};

// Reccursion 2
class Solution
{
private:
    int mini = INT_MAX;
    void helper(vector<int> &nums, int currSum, int totalSum, int i, int l1)
    {
        if (i >= nums.size())
            return;
        if (l1 == nums.size() / 2)
        {
            mini = min(mini, abs(totalSum - currSum));
            return;
        }
        helper(nums, currSum + nums[i], totalSum - nums[i], i + 1, l1 + 1);
        helper(nums, currSum, totalSum, i + 1, l1);
    }

public:
    int minimumDifference(vector<int> &nums)
    {
        if (nums.size() % 2 != 0)
            return 0;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
            totalSum += nums[i];
        helper(nums, 0, totalSum, 0, 0);
        return mini;
    }
};

// Recurrsive 3
class Solution {
private:
    int mini = INT_MAX;
    int helper(vector<int>& nums, int currSum, int totalSum, int i, int l1){
        if(l1 + nums.size() - i < nums.size()/2) return INT_MAX;
        if(i >= nums.size()) return INT_MAX;
        if(l1 == nums.size()/2 ){            
            return abs(totalSum - (2 * currSum));
        }
        int one = helper(nums, currSum + nums[i], totalSum, i+1, l1+1);
        int two = helper(nums, currSum, totalSum, i+1, l1);
        return min(one,two);
    }
public:
    int minimumDifference(vector<int>& nums) {
        if(nums.size()%2 != 0) return 0;
        int totalSum = 0;
        for(int i = 0 ; i< nums.size(); i++) totalSum += nums[i];
        
        return helper(nums, 0, totalSum, 0, 0);
    }
};

// DP- using map so that we can deal with negetive value
class Solution {
public:
    int solve(vector<int>& nums, int i, int currSum, int totSum, unordered_map<int,unordered_map<int,int>>& dp,int l) {
        if(l == nums.size()/2) {
            return abs(currSum - (totSum-currSum));
        }
        if(i >= nums.size()){
            return INT_MAX;
        }
        if(dp[i][currSum]) {
            return dp[i][currSum];
        }
        int take = solve(nums, i+1, currSum + nums[i], totSum, dp, l+1);
        int notTake = solve(nums, i+1, currSum, totSum, dp, l);
        return dp[i][currSum] = min(take, notTake);
    }  
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int mini = 0, maxi = 0;
        for(int i = 0 ; i< nums.size(); i++) {
            totalSum += nums[i];
        }
        unordered_map<int, unordered_map<int, int>> dp;
        int ans = solve(nums, 0, 0, totalSum, dp,0);
        return ans;
    }
    
};


// DP- if all numbers are positive and any length subset is allowed considering s1 + s2 = s
bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[ind][target] = true;

    if (ind == 0)
        return dp[ind][target] = arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

int minSubsetSumDifference(vector<int> &arr, int n)
{

    int totSum = 0;

    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

    for (int i = 0; i <= totSum; i++)
    {
        bool dummy = subsetSumUtil(n - 1, i, arr, dp);
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

// Tabulation of above
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;

    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= totSum)
        dp[0][totSum] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= totSum; target++)
        {

            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main()
{

    return 0;
}