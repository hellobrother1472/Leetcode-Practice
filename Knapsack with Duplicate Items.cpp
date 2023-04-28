#include <bits/stdc++.h>
using namespace std;

// Reccursion
class Solution{
private:
    int helper(int n, int w, int val[], int wt[],int i){
        if(i >= n || w < 0) {
            return 0;
        }
        int take = 0;
        if(wt[i] <= w) take = val[i] + helper(n,w-wt[i],val,wt,i);
        int notTake = helper(n,w,val,wt,i+1);
        return max(take,notTake);
    }
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        return helper(n,w,val,wt,0);
    }
};

// DP
class Solution{
private:
    int helper(int n,vector<vector<int>>&dp, int w, int val[], int wt[],int i){
        if(i >= n || w < 0) {
            return 0;
        }
        if(dp[i][w] != -1) return dp[i][w];
        int take = 0;
        if(wt[i] <= w) take = val[i] + helper(n,dp,w-wt[i],val,wt,i);
        int notTake = helper(n,dp,w,val,wt,i+1);
        return dp[i][w]=max(take,notTake);
    }
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        return helper(n,dp,w,val,wt,0);
    }
};

int main(){

    return 0;
}