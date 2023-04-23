#include <bits/stdc++.h>
using namespace std;

// At a particular index the minimum value is curr element + min((i,j), (i,j+1)); which means current element and minimum of next row's current index or next row's current index + 1
// If i comes at second last row if will call for both (i+1,j) and (i+1,j+1) so we just need to return triangle[i][j] their as we are not comparing two at i = n-1 we are comparing two at index i = n-2;

// Using DP
class Solution {
private:
    int helper(vector<vector<int>>& triangle,vector<vector<int>>& dp, int n, int i, int j){
        if(i == n-1){
            return triangle[i][j];
        }
        if(!dp[i][j]){
            dp[i][j] = triangle[i][j] + min(helper(triangle,dp,n,i+1,j),helper(triangle,dp,n,i+1,j+1));
        }
        return dp[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(triangle[n-1].size(),0));
        return helper(triangle, dp,n,0,0);
    }
};

// Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(triangle[n-1].size(),0));
        for(int i = n-1; i >= 0; i--){
            for(int j = triangle[i].size()-1; j >= 0; j--){
                if(i == n-1){
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

// Space optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>prev(n,0);
        for(int i = n-1; i >= 0; i--){
            vector<int>curr(n,0);
            for(int j = triangle[i].size()-1; j >= 0; j--){
                if(i == n-1){
                    curr[j] = triangle[i][j];
                    continue;
                }
                curr[j] = triangle[i][j] + min(prev[j],prev[j+1]);
            }
            prev = curr;
        }
        return prev[0];
    }
};

int main(){

    return 0;
}