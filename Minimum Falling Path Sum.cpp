#include <bits/stdc++.h>

using namespace std;

// Reccursion (solution of 2022)
class Solution {
private:
    int f(int i,int j,int n,int m,vector<vector<int>>& a)
    {
        if(j<0 || j>m-1)
            return 1e9;
        
        if(i==0)
            return a[i][j];
        
        int up = a[i][j] + f(i-1,j,n,m,a);
        
        int ld = a[i][j] + f(i-1,j-1,n,m,a);
        
        int rd = a[i][j] + f(i-1,j+1,n,m,a);
        
        
        return min(up,min(ld,rd));
        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n=matrix.size();
        
        int m=matrix[0].size();
        for(int j=0;j<m;j++)
        {
            ans=min(ans,f(n-1,j,n,m,matrix));
        }
        return ans;
    }
};

// Approach is that for current index the minimum value will be the mini (minimum of three below as per condition)+ current element.
class Solution {
private:
    int helper(vector<vector<int>>& matrix,vector<vector<int>>& dp, int n, int i, int j){
        if(i == n-1){
            return matrix[i][j];
        }
        if(!dp[i][j]){
            int mini = INT_MAX;
            for(int k = -1 ; k <=1; k++){
                if(j+k >= 0 && j+k < n) mini = min(mini, helper(matrix,dp,n,i+1,j+k));
            }
            dp[i][j] = matrix[i][j] + mini;
        }
        return dp[i][j];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int mini = INT_MAX;
        for(int k = 0 ; k < n; k++){
            mini = min(mini, helper(matrix,dp,n,0,k));
        }
        return mini;
    }
};

// Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = n-1 ; i >= 0; i--){
            for(int j = n-1 ; j >= 0; j--){
                if(i == n-1){
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                int minimum = INT_MAX;
                for(int k = -1 ; k <=1; k++){
                    if(j+k >= 0 && j+k < n) minimum = min(minimum,dp[i+1][j+k]);
                }
                dp[i][j] = matrix[i][j] + minimum;
            }
        }

        // Finding minimum from first row of dp
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans,dp[0][i]);
        }
        return ans;
    }
};


// Space optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev(n,0);
        for(int i = n-1 ; i >= 0; i--){
            vector<int>curr(n,0);
            for(int j = n-1 ; j >= 0; j--){
                if(i == n-1){
                    curr[j] = matrix[i][j];
                    continue;
                }
                int minimum = INT_MAX;
                for(int k = -1 ; k <=1; k++){
                    if(j+k >= 0 && j+k < n) minimum = min(minimum,prev[j+k]);
                }
                curr[j] = matrix[i][j] + minimum;

            }
            prev = curr;
        }
        int ans = INT_MAX;
        // Finding minimum from prev
        for(int i = 0; i < n; i++){
            ans = min(ans,prev[i]);
        }
        return ans;
    }
};


int main(){
    

    return 0;
}