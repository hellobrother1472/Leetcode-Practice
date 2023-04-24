#include <bits/stdc++.h>
using namespace std;

// Recurrsion
class Solution
{
public:
    int helper(int arr[], int n, int sum, int ind, int s)
    {
        if (s == sum)
            return 1;
        if (ind == n)
        {
            if (s == sum)
                return 1;
            else
                return 0;
        }
        int l = helper(arr, n, sum, ind + 1, s + arr[ind]);
        int r = helper(arr, n, sum, ind + 1, s);
        return l + r;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        return helper(arr, n, sum, 0, 0);
    }
};

// DP
class Solution
{
    int MOD = 1e9 + 7;

public:
    int helper(int arr[], vector<vector<long long int>> &dp, int n, int sum, int ind)
    {
        if (ind == n)
        {
            if (sum == 0)
                return 1;
            else
                return 0;
        }
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        int notPick = helper(arr, dp, n, sum, ind + 1);
        int pick = 0;
        if (arr[ind] <= sum)
            pick = helper(arr, dp, n, sum - arr[ind], ind + 1);
        return dp[ind][sum] = (pick + notPick) % MOD;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<long long int>> dp(n + 1, vector<long long int>(sum + 1, -1));
        return helper(arr, dp, n, sum, 0) % MOD;
    }
};

// Tabulization
int perfectSum(int arr[], int n, int sum)
{
    int MOD = 1e9 + 7;
    vector<vector<long long int>> dp(n + 1, vector<long long int>(sum + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int s = sum; s >= 0; s--)
        {
            dp[i][s] = dp[i + 1][s];
            if (s >= arr[i])
            {
                dp[i][s] += (dp[i + 1][s - arr[i]]);
            }
            dp[i][s] = dp[i][s] % MOD;
        }
    }
    return dp[0][sum];
}

int main()
{

    return 0;
}