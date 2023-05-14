#include <bits/stdc++.h>
using namespace std;

// Formula comes as first we have answer of left chunk and right chunk after that we will multiply those two matrices also so final answer will be sum of these three.

// Reccursion
class Solution{
private:
    int helper(int N, int arr[],int i, int j){
        if(i == j) return 0;
        int mini = INT_MAX;
        for(int k = i; k < j; k++){
            int sol = arr[i-1]*arr[j]*arr[k] + helper(N,arr,i,k) + helper(N,arr,k+1,j);
            mini = min(mini,sol);
        }
        return mini;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        return helper(N,arr,1,N-1);
    }
};

// DP-Memoization
class Solution{
private:
    int helper(int N, int arr[],int i, int j,vector<vector<int>>&dp){
        if(i == j) return 0;
        if(dp[i][j]) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i; k < j; k++){
            int sol = arr[i-1]*arr[j]*arr[k] + helper(N,arr,i,k,dp) + helper(N,arr,k+1,j,dp);
            mini = min(mini,sol);
        }
        return dp[i][j] = mini;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N,0));
        return helper(N,arr,1,N-1,dp);
    }
};

// DP-Tabularization
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N,0));
        for(int i = N-1; i >= 1 ; i--){
            for(int j = i+1; j < N; j++){
                int mini = INT_MAX;
                for(int k = i; k < j; k++){
                    int sol = arr[i-1]*arr[j]*arr[k] + dp[i][k] + dp[k+1][j];
                    mini = min(mini,sol);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N-1];
    }
};

int main(){

    return 0;
}