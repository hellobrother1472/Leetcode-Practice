#include <bits/stdc++.h>
using namespace std;

// Reccursion 1
class Solution {
private:
    int helper(vector<int>& coins, int amount, int i){
        if(amount == 0) return 0;
        if(i >= coins.size() && amount != 0) return -1;

        int take = -1;
        if(coins[i] <= amount) take = helper(coins,amount-coins[i],i);
        int notTake = helper(coins,amount,i+1);
        if(take == -1 && notTake == -1) return -1;
        if(take == -1) return notTake;
        if(notTake == -1) return 1+take;

        return min(1+take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int ans = helper(coins,amount,0);
        return ans;
    }
};

// Reccursion 2
class Solution {
private:
    int helper(vector<int>& coins, int amount, int i){
        // Base case 1
        if(amount == 0) return 0; // returning zero because addition of 1 is taking place in take condition, so which means taking is done previously when we got amount = 0, so to compensate I return 0 or either,you can return final ans - 1.
        if(i >= coins.size() && amount != 0) return 10000000;


        // or Base case 2, in this case if we see closely it is calculation before amount becomes 0
        if(i >= coins.size()-1){
            if(i == coins.size() -1 && amount % coins[i] == 0) return amount/coins[i];
            return 10000000;
        }

        int take = 10000000;
        if(coins[i] <= amount) take = 1 + helper(coins,amount-coins[i],i);
        int notTake = helper(coins,amount,i+1);
        return min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int ans = helper(coins,amount,0);
        if(ans >= 10000000) return -1;
        return ans;
    }
};

// DP - Memoized
class Solution {
private:
    int helper(vector<int>& coins, vector<vector<int>>&dp, int amount, int i){
        if(i >= coins.size()-1){
            if(i == coins.size() -1 && amount % coins[i] == 0) return amount/coins[i];
            return 10000000;
        }
        if(dp[i][amount]) return dp[i][amount];
        int take = 10000000;
        if(coins[i] <= amount) take = 1 + helper(coins,dp,amount-coins[i],i);
        int notTake = helper(coins,dp,amount,i+1);
        return dp[i][amount] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1,0));
        int ans = helper(coins,dp,amount,0);
        if(ans >= 10000000) return -1;
        return ans;
    }
};

// Tabulization(DP with base 1)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0) return 0;
        vector<vector<int>>dp(n+1, vector<int>(amount+1,1e9));
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int ind = n-1; ind>=0; ind--){
            for(int target = 1; target<=amount; target++){
                
                int notTake = 0 + dp[ind+1][target];
                int take = 1e9;
                if(coins[ind]<=target)
                    take = 1 + dp[ind][target - coins[ind]];
                    
                dp[ind][target] = min(notTake, take);
            }
        }
        return (dp[0][amount] >= 1e9) ? -1 : dp[0][amount];
    }
};

int main(){

    return 0;
}