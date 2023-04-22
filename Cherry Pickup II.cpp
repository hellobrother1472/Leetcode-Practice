#include <bits/stdc++.h>
using namespace std;

// As we can observe from the question that we have to move the robots simunteneously, to do that we know that every time i for both robots will be same what will be different in thier values of j so we are taking those.
// For base case if we reach last row then accroding to question if j1 == j2 then only one path can choose and it will be return one only, but if they are different then sum of no. of cherries at j1 and j2 will occur.
// Now as we have to traverse all the possible paths and find out the maximum of the cherry collected, for that we will consider all possiblities of j1 and j2 with some condition as given in question and then updating maxi and doing that we will got our answer
// If doubt is of why we just give sum of one element if j1 and j2 are equal then this is due to condition in question, and the optimal path will be already stored if their is any for any combination of j1 and j2.

// Using DP
class Solution {
private:
    int helper(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int i, int j1, int j2, int n, int m){
        if(i == n-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(!dp[i][j1][j2]){
            int maxi = -1;
            for(int b = -1; b <= 1; b++){
                for(int c = -1; c <= 1; c++){
                    int newJ1 = j1+b, newJ2 = j2+c;
                    if(newJ1 < m && newJ1 >=0 && newJ2 < m && newJ2 >=0){
                        if(j1 == j2) maxi = max(maxi, grid[i][j1] + helper(grid,dp,i+1,newJ1,newJ2,n,m));
                        else maxi = max(maxi, grid[i][j1] + grid[i][j2] + helper(grid,dp,i+1,newJ1,newJ2,n,m));
                    }
                }
            }
            dp[i][j1][j2] = maxi;
        }
        return dp[i][j1][j2];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        return helper(grid,dp,0,0,m-1,n,m);
    }
};

// Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int i = n-1; i >= 0; i--){
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    if(i == n-1) {
                        if(j1 == j2) dp[i][j1][j2] = grid[i][j2];
                        else dp[i][j1][j2] = grid[i][j1] + grid[i][j2];

                        continue;
                    }
                    int maxi = -1;
                    for(int b = -1; b <= 1; b++){
                        for(int c = -1; c <= 1; c++){
                            int newJ1 = j1+b, newJ2 = j2+c;
                            if(newJ1 < m && newJ1 >=0 && newJ2 < m && newJ2 >=0){
                                if(j1 == j2) maxi = max(maxi, grid[i][j1] + dp[i+1][newJ1][newJ2]);
                                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + dp[i+1][newJ1][newJ2]);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }    
        }
        return dp[0][0][m-1];
    }
};

// Space optimization
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> front(m,vector<int>(m,0));
        for(int i = n-1; i >= 0; i--){
            vector<vector<int>> curr(m,vector<int>(m,0));
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    if(i == n-1) {
                        if(j1 == j2) curr[j1][j2] = grid[i][j2];
                        else curr[j1][j2] = grid[i][j1] + grid[i][j2];

                        continue;
                    }
                    int maxi = -1;
                    for(int b = -1; b <= 1; b++){
                        for(int c = -1; c <= 1; c++){
                            int newJ1 = j1+b, newJ2 = j2+c;
                            if(newJ1 < m && newJ1 >=0 && newJ2 < m && newJ2 >=0){
                                if(j1 == j2) maxi = max(maxi, grid[i][j1] + front[newJ1][newJ2]);
                                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + front[newJ1][newJ2]);
                            }
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }    
            front = curr;
        }
        return front[0][m-1];
    }
};

int main(){

    return 0;
}