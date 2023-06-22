#include <bits/stdc++.h>
using namespace std;

// Reccursive
class Solution {
private:
    long helper(vector<int>&Arr, int ind, int buy, int n, vector<vector<long>> &dp,int fee ){

        if(ind>=n) return 0; //base case
        
        long profit;
        
        if(buy==0){// We can buy the stock
            profit = max(0+helper(Arr,ind+1,0,n,dp,fee), -Arr[ind] + helper(Arr,ind+1,1,n,dp,fee)); // Jab aage ka profit aayega tbb apne app hi arr[ind] minus ho jaiga.
        }
        
        if(buy==1){// We can sell the stock
            profit = max(0+helper(Arr,ind+1,1,n,dp,fee), Arr[ind] - fee + helper(Arr,ind+1,0,n,dp,fee));
        }
        
        return profit;
    }

public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        // unordered_map<int,unordered_map<int,int>>dp;
        vector<vector<long>> dp(n,vector<long>(2,-1));
        return helper(prices,0,0,n,dp,fee);
    }
};

// DP-Memoization
class Solution {
private:
    long helper(vector<int>&Arr, int ind, int buy, int n, vector<vector<long>> &dp,int fee ){

        if(ind>=n) return 0; //base case
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
            
        long profit;
        
        if(buy==0){// We can buy the stock
            profit = max(0+helper(Arr,ind+1,0,n,dp,fee), -Arr[ind] + helper(Arr,ind+1,1,n,dp,fee));
        }
        
        if(buy==1){// We can sell the stock
            profit = max(0+helper(Arr,ind+1,1,n,dp,fee), Arr[ind] - fee + helper(Arr,ind+1,0,n,dp,fee));
        }
        
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        // unordered_map<int,unordered_map<int,int>>dp;
        vector<vector<long>> dp(n,vector<long>(2,-1));
        return helper(prices,0,0,n,dp,fee);
    }
};

// DP-Tabularization
class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<long>> dp(n+2,vector<long>(2,0));
        for(int i = n-1; i >= 0; i--){
            for(int buy = 1; buy >=0; buy--){
                if(buy==0){// We can buy the stock
                    dp[i][buy] = max(dp[i+1][0], -prices[i] + dp[i+1][1]);
                }
                
                if(buy==1){// We can sell the stock
                    dp[i][buy] = max(dp[i+1][1], prices[i]- fee + dp[i+1][0]);
                }
            }
        }

        return dp[0][0];
    }
};

int main(){

    return 0;
}