#include <bits/stdc++.h>
using namespace std;

// Reccursion
class Solution {
private:
    
    long helper(vector<int>&Arr, int ind, int buy, int n, vector<vector<long>> &dp, int times ){

        if(ind==n || times == 0) return 0; //base case
        
        // if(dp[ind][buy]!=-1)
        //     return dp[ind][buy];
            
        long profit;
        
        if(buy==0){// We can buy the stock
            profit = max(0+helper(Arr,ind+1,0,n,dp,times), -Arr[ind] + helper(Arr,ind+1,1,n,dp,times));
        }
        
        if(buy==1){// We can sell the stock
            profit = max(0+helper(Arr,ind+1,1,n,dp,times), Arr[ind] + helper(Arr,ind+1,0,n,dp,times-1));
        }
        
        return profit;
    }

public:
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        // unordered_map<int,unordered_map<int,int>>dp;
        vector<vector<long>> dp(n,vector<long>(k,-1));
        return helper(prices,0,0,n,dp,k);
    }
};

// DP-Memoization
class Solution {
private:
    
    long helper(vector<int>&Arr, int ind, int buy, int n, vector<vector<vector<long>>> &dp, int times ){

        if(ind==n || times == 0) return 0; //base case
        
        if(dp[ind][buy][times]!=-1)
            return dp[ind][buy][times];
            
        long profit;
        
        if(buy==0){// We can buy the stock
            profit = max(0+helper(Arr,ind+1,0,n,dp,times), -Arr[ind] + helper(Arr,ind+1,1,n,dp,times));
        }
        
        if(buy==1){// We can sell the stock
            profit = max(0+helper(Arr,ind+1,1,n,dp,times), Arr[ind] + helper(Arr,ind+1,0,n,dp,times-1));
        }
        
        return dp[ind][buy][times] = profit;
    }

public:
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        // unordered_map<int,unordered_map<int,int>>dp;
        vector<vector<vector<long>>> dp(n,vector<vector<long>>(2,vector<long>(k+1,-1)));
        // vector<vector<int
        return helper(prices,0,0,n,dp,k);
    }
};

// DP-Tabularization
class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long>>> dp(n+1,vector<vector<long>>(2,vector<long>(k+1,0)));
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){                    
                    if(buy==0){// We can buy the stock
                        dp[ind][buy][cap] = max(0+dp[ind+1][0][cap],-prices[ind] + dp[ind+1][1][cap]);
                    }
        
                    if(buy==1){// We can sell the stock
                        dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],prices[ind] + dp[ind+1][0][cap-1]);
                    }
                }
            }
        }

        return dp[0][0][k];
    }
};

int main(){

    return 0;
}