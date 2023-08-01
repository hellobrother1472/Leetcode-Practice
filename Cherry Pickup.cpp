#include <bits/stdc++.h>
using namespace std;

// approaching this problem considering that two men are standing at starting point starts simunteneously and moves till they reach last.
// 4D matrix is used.
class Solution {
private:
    int helper(vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>&dp, int i1, int j1, int i2,int j2, int n){
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) return INT_MIN;
        if(i1 == n-1 && j1 == n-1){
            return grid[i1][j1];
        }
        int cherries = 0;
        if(dp[i1][j1][i2][j2]) return dp[i1][j1][i2][j2];
        if(i1 == i2 && j1 == j2){
            cherries += grid[i1][j1];
        }
        else{
            cherries += grid[i1][j1] + grid[i2][j2];
        }

        int one = helper(grid,dp,i1+1,j1,i2+1,j2,n); // right and right
        int two = helper(grid,dp,i1+1,j1,i2,j2+1,n); // right and down
        int three = helper(grid,dp,i1,j1+1,i2+1,j2,n); // down and right
        int four = helper(grid,dp,i1,j1+1,i2,j2+1,n); // down and right

        cherries += max(max(one,two), max(three,four));
        dp[i1][j1][i2][j2] = cherries;
        return dp[i1][j1][i2][j2];
    }
        
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,0))));        
        int ans = helper(grid,dp,0,0,0,0,n);
        if(ans < 0) return 0;
        return ans;
    }
};

// Some space optimization in dp itself by observing that i1 + j1 = i2 + j2 because every time both moves one step and they both start from a same point, so we don't need 4 variables we need only three fourth can be calculated if we know other three.
// Removing j2
class Solution {
private:
    int helper(vector<vector<int>>& grid, vector<vector<vector<int>>>&dp, int i1, int j1, int i2, int n){
        int j2 = i1 + j1 - i2;
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) return INT_MIN;
        if(i1 == n-1 && j1 == n-1){
            return grid[i1][j1];
        }
        int cherries = 0;
        if(dp[i1][j1][i2]) return dp[i1][j1][i2];
        if(i1 == i2 && j1 == j2){
            cherries += grid[i1][j1];
        }
        else{
            cherries += grid[i1][j1] + grid[i2][j2];
        }

        int one = helper(grid,dp,i1+1,j1,i2+1,n); // right and right
        int two = helper(grid,dp,i1+1,j1,i2,n); // right and down
        int three = helper(grid,dp,i1,j1+1,i2+1,n); // down and right
        int four = helper(grid,dp,i1,j1+1,i2,n); // down and right

        cherries += max(max(one,two), max(three,four));
        dp[i1][j1][i2] = cherries;
        return dp[i1][j1][i2];
    }
        
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,0)));        
        int ans = helper(grid,dp,0,0,0,n);
        if(ans < 0) return 0;
        return ans;
    }
};

// Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
        
        for (int i1 = n - 1; i1 >= 0; i1--) {
            for (int j1 = n - 1; j1 >= 0; j1--) {
                for (int i2 = n - 1; i2 >= 0; i2--) {
                    int j2 = i1 + j1 - i2;
                    
                    if (j2 < 0 || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
                        dp[i1][j1][i2] = -1;
                        continue;
                    }
                    
                    if (i1 == n - 1 && j1 == n - 1) {
                        dp[i1][j1][i2] = grid[i1][j1];
                        continue;
                    }
                    
                    int cherries = grid[i1][j1] + (i1 != i2 || j1 != j2 ? grid[i2][j2] : 0);
                    
                    int one = (i1 < n - 1 && i2 < n - 1) ? dp[i1 + 1][j1][i2 + 1] : -1;
                    int two = (i1 < n - 1) ? dp[i1 + 1][j1][i2] : -1;
                    int three = (j1 < n - 1 && i2 < n - 1) ? dp[i1][j1 + 1][i2 + 1] : -1;
                    int four = (j1 < n - 1) ? dp[i1][j1 + 1][i2] : -1;
                    
                    dp[i1][j1][i2] = max({one, two, three, four});
                    if (dp[i1][j1][i2] != -1) {
                        dp[i1][j1][i2] += cherries;
                    }
                }
            }
        }
        
        return max(0, dp[0][0][0]);
    }
};

// Space optimization
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> prev(n, vector<int>(n, 0));
        
        for (int i1 = n - 1; i1 >= 0; i1--) {
            vector<vector<int>> curr(n, vector<int>(n, 0));
            for (int j1 = n - 1; j1 >= 0; j1--) {
                for (int i2 = n - 1; i2 >= 0; i2--) {
                    int j2 = i1 + j1 - i2;
                    
                    if (j2 < 0 || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
                        curr[j1][i2] = -1;
                        continue;
                    }
                    
                    if (i1 == n - 1 && j1 == n - 1) {
                        curr[j1][i2] = grid[i1][j1];
                        continue;
                    }
                    
                    int cherries = grid[i1][j1] + (i1 != i2 || j1 != j2 ? grid[i2][j2] : 0);
                    
                    int one = (i1 < n - 1 && i2 < n - 1) ? prev[j1][i2 + 1] : -1;
                    int two = (i1 < n - 1) ? prev[j1][i2] : -1;
                    int three = (j1 < n - 1 && i2 < n - 1) ? curr[j1 + 1][i2 + 1] : -1;
                    int four = (j1 < n - 1) ? curr[j1 + 1][i2] : -1;
                    
                    curr[j1][i2] = max({one, two, three, four});
                    if (curr[j1][i2] != -1) {
                        curr[j1][i2] += cherries;
                    }
                }
            }
            prev = curr;
        }
        
        return max(0, prev[0][0]);
    }
};


int main(){
    

    return 0;
}