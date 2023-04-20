#include <bits/stdc++.h>
using namespace std;

// When you reach last return 1, and at any point total path is sum of helper(i+1,j) and helper(i,j+1);

// Using DP
class Solution {
private:
    int helper(int m,int n, vector<vector<int>>&dp, int i,int j){
        if(i >= m-1 || j >= n-1){
            if(i == m-1 && j == n-1) return 1;
            if(i > m-1 || j > n-1) return 0;
        }

        if(!dp[i][j]){
            dp[i][j] = helper(m,n,dp,i+1,j) + helper(m,n,dp,i,j+1);
        }
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        return helper(m,n,dp,0,0);
    }
};

// Using tabulation
// knowing that dp[m-1][n-1] = 1, we can iterate in matrix while filling the value of right and down if valid otherwise 0.
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    dp[i][j] = 1;
                    continue;
                }
                else{
                    int right = 0, down = 0;
                    if(j+1 < n) right = dp[i][j+1];
                    if(i+1 < m) down = dp[i+1][j];

                    dp[i][j] = right + down;
                }                
            }
        }
        return dp[0][0];
    }
};

// Space optimization
// As we just want down value and right value, so if we see, down value are the results of prev computed row and right value is value of right of current row.
// So we just need 2 rows one for storing prev and one for current.
// After end of loop each time the current will become prev.
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int i = m-1; i >= 0; i--){
            vector<int>curr(n,0);
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    curr[j] = 1;
                    continue;
                }
                int right = 0, down = 0;
                if(j+1 < n) right = curr[j+1];
                if(i+1 < m) down = prev[j];
                curr[j] = right + down;
            }
            prev = curr;
        }
        return prev[0];
    }
};

int main(){

    return 0;
}