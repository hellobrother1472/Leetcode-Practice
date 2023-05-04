#include <bits/stdc++.h>
using namespace std;
// The approach is that if you have already buyed the stock then you can only sell and ignore and if you does'nt have buy it then you can buy or ignore
// Here if curr = -1 it means we have nothing, if curr have some value then it means we have some buy previously.
// Reccursion
class Solution {
private:
    int helper(vector<int>& prices, int n, int i, int curr){
        if(i>=n) return 0;
        if(curr == -1){
            // you can buy or ignore
            int buy = helper(prices,n,i+1,prices[i]);
            int ignore = helper(prices,n,i+1,curr);
            return max(buy,ignore);
        }
        // You can sell or ignore
        int sell=0,ignore=0;
        if(prices[i] > curr) sell = prices[i]-curr + helper(prices,n,i,-1);
        ignore = helper(prices,n,i+1,curr);
        return max(sell,ignore) ;     
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return helper(prices,n,0,-1);
    }
};

// DP-Memoization
class Solution {
private:
    int helper(unordered_map<int,unordered_map<int,int>>&dp,vector<int>& prices, int n, int i, int curr){
        if(i>=n) return 0;
        if(dp[i][curr]) return dp[i][curr];
        if(curr == -1){
            // you can buy or ignore
            int buy = helper(dp,prices,n,i+1,prices[i]);
            int ignore = helper(dp,prices,n,i+1,curr);
            return dp[i][curr] = max(buy,ignore);
        }
        int sell=0,ignore=0,sellAndBuy;
        if(prices[i] > curr) sell = prices[i]-curr + helper(dp,prices,n,i,-1);
        ignore = helper(dp,prices,n,i+1,curr);
        return dp[i][curr] = max(sell,ignore) ;     
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        unordered_map<int,unordered_map<int,int>>dp;
        return helper(dp,prices,n,0,-1);
    }
};

// In this approach we are not using curr we are using buy which can be 1 or 0, 0 means no previous so buy allowed.
// When we buy, our account has decreases by current element value and when we sell our account increases by current, so profit is compensated by prev value.
// DP-Memoization
class Solution {
private:
    long helper(vector<int>&Arr, int ind, int buy, int n, vector<vector<long>> &dp ){

        if(ind==n) return 0; //base case
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
            
        long profit;
        
        if(buy==0){// We can buy the stock
            profit = max(0+helper(Arr,ind+1,0,n,dp), -Arr[ind] + helper(Arr,ind+1,1,n,dp));
        }
        
        if(buy==1){// We can sell the stock
            profit = max(0+helper(Arr,ind+1,1,n,dp), Arr[ind] + helper(Arr,ind+1,0,n,dp));
        }
        
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n,vector<long>(2,-1));
        return helper(prices,0,0,n,dp);
    }
};

// Tabulization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n+1,vector<long>(2,0));
        for(int i = n-1; i >= 0; i--){
            for(int buy = 1; buy >=0; buy--){
                if(buy==0){// We can buy the stock
                    dp[i][buy] = max(dp[i+1][0], -prices[i] + dp[i+1][1]);
                }
                
                if(buy==1){// We can sell the stock
                    dp[i][buy] = max(dp[i+1][1], prices[i] + dp[i+1][0]);
                }
            }
        }

        return dp[0][0];
    }
};

int main(){

    return 0;
}