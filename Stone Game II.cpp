#include <bits/stdc++.h>
using namespace std;

// In this the value of M is not fixed as both alice and bob can pick form first 1 to 2M available stones.
// So taking the flag which is true in alice's turn, we wrote the reccursive solution.
// If it is alices turn then we have to maximize the value so we take all the possiblities and return the max value.
// If it is bob's turn then bob will try to minimize the alices score so we return the minimum value.
// At last we got the max alice can get

// Reccursive
class Solution {  
private:
    int helper(vector<int>& piles, int n, int i, int M,int flag){
        if(i >= n){
            return 0;
        }
        int ans = (flag) ? 0 : INT_MAX;
        int total = 0;
        for(int x = 1; x <= 2*M; x++){
            if(i+x > n) break;
            total += piles[i+x-1];
            if(flag){
                ans = max(ans,total + helper(piles,n,x+i,max(x,M), !flag));
            }
            else{
                ans = min(ans,helper(piles,n,x+i,max(x,M),!flag));// In bob's turn he is trying to return minimum of alice's score and total is not added because it is the total of bob which we don't want we want alice's total which is next turn and bob want to return minimum of the next turn.
            }
        }
        return ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        return helper(piles,n,0,1,true);
    }
};

// DP - Memoization
class Solution {  
private:
    int helper(vector<vector<vector<int>>>&dp,vector<int>& piles, int n, int i, int M,int flag){
        if(i >= n){
            return 0;
        }
        if(dp[i][M][flag]) return dp[i][M][flag];
        int ans = (flag) ? 0 : INT_MAX;
        int total = 0;
        for(int x = 1; x <= 2*M; x++){
            if(i+x > n) break;
            total += piles[i+x-1];
            if(flag){
                ans = max(ans,total + helper(dp,piles,n,x+i,max(x,M), !flag));
            }
            else{
                ans = min(ans,helper(dp,piles,n,x+i,max(x,M),!flag)); // In bob's turn he is trying to return minimum of alice's score and total is not added because it is the total of bob which we don't want we want alice's total which is next turn and bob want to return minimum of the next turn.
            }
        }
        return dp[i][M][flag] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(2,0)));
        return helper(dp,piles,n,0,1,true);
    }
};

// Tabularization
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 2, vector<int>(2, 0)));

        for (int i = n; i >= 0; i--) {
            for (int M = n; M >= 1; M--) {
                for (int flag = 0; flag <= 1; flag++) {
                    if (i >= n) {
                        dp[i][M][flag] = 0;
                        continue;
                    }

                    int ans = (flag) ? 0 : INT_MAX;
                    int total = 0;

                    for (int x = 1; x <= 2 * M; x++) {
                        if (i + x > n) {
                            break;
                        }

                        total += piles[i + x - 1];

                        if (flag) {
                            ans = max(ans, total + dp[i + x][max(x, M)][!flag]);
                        } else {
                            ans = min(ans, dp[i + x][max(x, M)][!flag]);
                        }
                    }

                    dp[i][M][flag] = ans;
                }
            }
        }

        return dp[0][1][1];
    }
};


int main(){

    return 0;
}