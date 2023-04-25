#include <bits/stdc++.h>
using namespace std;

// Reccursive
class Solution
{
    private:
    int helper(int W, int wt[], int val[], int n, int i, int valSum){
        if(i >= n || W < 0) {
            if(i == n && W >= 0) return valSum;
            return INT_MIN;
        }
        int take = helper(W-wt[i],wt,val,n,i+1, valSum + val[i]);
        int notTake = helper(W,wt,val,n,i+1, valSum);
        return max(take,notTake);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return helper(W,wt,val,n,0,0);
    }
};

// Recurrsion 2
class Solution
{
    private:
    int helper(int W, int wt[], int val[], int n, int i){
        if(i >= n || W < 0) {
            return 0;
        }
        int take = 0;
        if(wt[i] <= W) take = val[i] + helper(W-wt[i],wt,val,n,i+1);
        int notTake = helper(W,wt,val,n,i+1);
        return max(take,notTake);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return helper(W,wt,val,n,0);
    }
};

// DP
class Solution
{
    private:
    int helper(int W,vector<vector<int>>&dp, int wt[], int val[], int n, int i){
        if(i >= n || W < 0) {
            return 0;
        }
        if(dp[i][W] != -1) return dp[i][W];
        int take = 0;
        if(wt[i] <= W) take = val[i] + helper(W-wt[i],dp,wt,val,n,i+1);
        int notTake = helper(W,dp,wt,val,n,i+1);
        return dp[i][W] = max(take,notTake);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return helper(W,dp,wt,val,n,0);
    }
};

// Tabulization
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,0));
       for(int i = n-1; i >= 0; i--){
           for(int j = W; j >= 0; j--){
               int take = 0;
               if(wt[i] <= j) take = val[i] + dp[i+1][j-wt[i]];
               int notTake = dp[i+1][j];
               dp[i][j] = max(take,notTake);
           }
       }
       return dp[0][W];
    }
};

// Space Optimization
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<int>prev(W+1,0);
       for(int i = n-1; i >= 0; i--){
           vector<int>curr(W+1,0);
           for(int j = W; j >= 0; j--){
               int take = 0;
               if(wt[i] <= j) take = val[i] + prev[j-wt[i]];
               int notTake = prev[j];
               curr[j] = max(take,notTake);
           }
           prev = curr;
       }
       return prev[W];
    }
};

int main(){

    return 0;
}