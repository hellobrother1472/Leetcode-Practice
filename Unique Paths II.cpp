#include <bits/stdc++.h>
using namespace std;

// Logic is same as Unique Paths problem just with a little modification that if thier is an obstacle then make the helper(of that index) = 0 or return 0, because their should be no path without obstacles

// Using DP 
class Solution {
private:
int helper(vector<vector<int>>& obstacleGrid,int m,int n, vector<vector<int>>&dp, int i,int j){
    if(i < m && j < n && obstacleGrid[i][j] == 1) return 0;
    if(i >= m-1 || j >= n-1){
        if(i == m-1 && j == n-1) return 1;
        if(i > m-1 || j > n-1) return 0;
    }
    if(!dp[i][j]){
        dp[i][j] = helper(obstacleGrid,m,n,dp,i+1,j) + helper(obstacleGrid,m,n,dp,i,j+1);
    }
    return dp[i][j];
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        return helper(obstacleGrid,m,n,dp,0,0);
    }
};


// Using tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n,0));
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                else{
                    if(i == m-1 && j == n-1){
                        dp[i][j] = 1;
                        continue;
                    }
                    else{
                        long long right = 0, down = 0;
                        if(j+1 < n) right = dp[i][j+1];
                        if(i+1 < m) down = dp[i+1][j];

                        dp[i][j] = right + down;
                    } 
                }
            }
        }
        return dp[0][0];
    }
};

// Space optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long long>prev(n,0);
        for(int i = m-1; i >= 0; i--){
            vector<long long>curr(n,0);
            for(int j = n-1; j >= 0; j--){
                if(obstacleGrid[i][j] == 1){
                    curr[j] = 0;
                    continue;
                }
                else{
                    if(i == m-1 && j == n-1){
                        curr[j] = 1;
                        continue;
                    }
                    else{
                        long long right = 0, down = 0;
                        if(j+1 < n) right = curr[j+1];
                        if(i+1 < m) down = prev[j];

                        curr[j] = right + down;
                    } 
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};


int main(){

    return 0;
}