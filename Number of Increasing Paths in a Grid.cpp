#include <bits/stdc++.h>
using namespace std;

// Starting from any node start doing dfs in every possible path which is valid now,and from every next element. Now the total paths for the current i and j is the 1 + left + right + up + down. So just do it and fill in dp.
// Now to find total available count add every node's dp value to ans.
// Make a reccursion tree for more understanding.
class Solution {
private:
    int mod = 1e9+7;
    int helper(vector<vector<int>>& grid,vector<vector<int>>&dp,int m,int n, int i, int j, int prev){
        if(i >= m || j >= n || j<0 || i<0 || grid[i][j] <= prev) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = helper(grid,dp,m,n,i-1,j,grid[i][j])%mod;
        int down = helper(grid,dp,m,n,i+1,j,grid[i][j])%mod;
        int right = helper(grid,dp,m,n,i,j+1,grid[i][j])%mod;
        int left = helper(grid,dp,m,n,i,j-1,grid[i][j])%mod;
        return dp[i][j] = (up + down + right + left + 1)%mod;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] == -1) ans += helper(grid,dp,m,n,i,j,INT_MIN);
                else ans += dp[i][j];
                ans %= mod;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}