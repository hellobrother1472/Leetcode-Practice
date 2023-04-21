#include <bits/stdc++.h>
using namespace std;

// At any index the minimum path ahead is grid[i][j] (current) + minimum of( down path , right path).
// If index reaches last then return itself as their is no other options or if i or j become invalid so return INT_MAX as it will help to eliminate it when we are filtering using min function.

// Using DP
class Solution {
private:
    int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n , int i, int j){
        if(i >= m-1 || j >= n-1){
            if(i == m-1 && j == n-1) return grid[i][j];
            if(i > m-1 || j > n-1) return INT_MAX;
        }

        if(!dp[i][j]){
            // Not added grid[i][j] in right or down itself because for invalid value of i or j base case is returning INT_MAX and for anything + INT_MAX will not be in int, which creates problem.
            // int right = grid[i][j] + helper(grid,dp,m,n,i,j+1);
            // int down = grid[i][j] + helper(grid,dp,m,n,i+1,j);
            int right = helper(grid,dp,m,n,i,j+1);
            int down = helper(grid,dp,m,n,i+1,j);
            dp[i][j] = grid[i][j] + min(right,down);
        }
        return dp[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,0));
        return helper(grid,dp,m,n,0,0);
    }
};

// Using Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,0));
        for(int i = m-1 ; i >= 0; i--){
            for(int j = n-1 ; j >= 0; j--){
                if( i == m-1 && j == n-1){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int right = INT_MAX, down = INT_MAX;
                if(i+1 < m) down = dp[i+1][j];
                if(j+1 < n) right = dp[i][j+1];

                dp[i][j] = grid[i][j] + min(right,down);
            }
        }
        return dp[0][0];
    }
};

// Space optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>prev(n,0);
        for(int i = m-1 ; i >= 0; i--){
            vector<int>curr(n,0);
            for(int j = n-1 ; j >= 0; j--){
                if( i == m-1 && j == n-1){
                    curr[j] = grid[i][j];
                    continue;
                }
                int right = INT_MAX, down = INT_MAX;
                if(i+1 < m) down = prev[j];
                if(j+1 < n) right = curr[j+1];

                curr[j] = grid[i][j] + min(right,down);
            }
            prev = curr;
        }
        return prev[0];
    }
};

int main(){

    return 0;
}