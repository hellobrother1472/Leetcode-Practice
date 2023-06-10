#include <bits/stdc++.h>
using namespace std;

// Using reccursion
// All paths are explored so starting from start in all direction and that path which reaches end return 1, and count all the way to the top.
class Solution {
private:
    int helper(vector<vector<int>>& grid, int n, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= n) return INT_MAX;
        if(grid[i][j] == 1 || grid[i][j] == -1) return INT_MAX;
        if(i == n-1 && j == n-1) return 1;
        int val = INT_MAX;
        for(int k = -1; k <= 1; k++){
            for(int l = -1; l <= 1; l++){
                if(k != 0 || l != 0){
                    int r = grid[i][j];
                    grid[i][j] = -1;
                    val = min(val,helper(grid,n,i+k, j+l));
                    grid[i][j] = r;
                }
            }
        }
        if(val == INT_MAX) return INT_MAX;
        return 1 + val;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int ans = helper(grid,grid.size(),0,0);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

// Using DP
class Solution {
private:
    int helper(vector<vector<int>>& grid, int n, int i, int j,vector<vector<int>>&dp){
        if(i < 0 || j < 0 || i >= n || j >= n) return INT_MAX;
        if(grid[i][j] == 1 || grid[i][j] == -1) return INT_MAX;
        if(i == n-1 && j == n-1) return 1;
        if(dp[i][j]) return dp[i][j];
        int val = INT_MAX;
        for(int k = -1; k <= 1; k++){
            for(int l = -1; l <= 1; l++){
                if(k != 0 || l != 0){
                    int r = grid[i][j];
                    grid[i][j] = -1;
                    val = min(val,helper(grid,n,i+k, j+l,dp));
                    grid[i][j] = r;
                }
            }
        }
        if(val == INT_MAX) return INT_MAX;
        return dp[i][j] = 1 + val;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        int ans = helper(grid,n,0,0, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main(){

    return 0;
}