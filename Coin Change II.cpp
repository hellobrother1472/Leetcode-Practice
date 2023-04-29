#include <bits/stdc++.h>
using namespace std;

// Reccursion
class Solution {
private:
    int helper(vector<int>& coins, int amount,int n, int i){
        if(i == n){
            if(amount == 0) return 1;
            return 0;
        }
        int take = 0;
        if(coins[i] <= amount) take = helper(coins,amount-coins[i],n,i);
        int notTake = helper(coins,amount,n,i+1);
        return take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return helper(coins,amount,n,0);
    }
};

// DP- memoization
class Solution {
private:
    int helper(vector<int>& coins,vector<vector<int>>&dp, int amount,int n, int i){
        if(i == n){
            if(amount == 0) return 1;
            return 0;
        }
        if(dp[i][amount]) return dp[i][amount];
        int take = 0;
        if(coins[i] <= amount) take = helper(coins,dp,amount-coins[i],n,i);
        int notTake = helper(coins,dp,amount,n,i+1);
        return dp[i][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        return helper(coins,dp,amount,n,0);
    }
};

// DP-Tabulization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        dp[n][0] = 1;
        for(int i = n-1; i>=0;i--){
            for(int j = 0; j <= amount;j++){
                int take = 0;
                if(j >= coins[i]) take = dp[i][j - coins[i]];
                int notTake = dp[i+1][j];
                dp[i][j] = take + notTake;
            }
        }
        return dp[0][amount];
    }
};

int main(){

    return 0;
}