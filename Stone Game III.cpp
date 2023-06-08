#include <bits/stdc++.h>
using namespace std;

// This question is similar to stone game 2, in this the value of M is fixed as both alice and bob can pick form first 3 available stones.
// So taking the flag which is true in alice's turn, we wrote the reccursive solution.
// If it is alices turn then we have to maximize the value so we take all the possiblities and return the max value.
// If it is bob's turn then bob will try to minimize the alices score so we return the minimum value.
// At last we got the max alice can get, we check it with bob and give the answer accordingly

// Reccursive
class Solution {
private:
    int helper(vector<int>& piles, int n, int i, int flag) {
        if (i >= n) {
            return 0;
        }

        int ans = (flag) ? INT_MIN : INT_MAX;
        int total = 0;

        for (int x = 1; x <= 3 && i + x <= n; x++) {
            total += piles[i + x - 1];

            if (flag) {
                ans = max(ans, total + helper(piles, n, i + x, !flag));
            } else {
                ans = min(ans, helper(piles, n, i + x, !flag));
            }
        }

        return ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int total = 0;
        for(int i = 0; i<n; i++) total += stoneValue[i];
        int alice = helper(stoneValue, n, 0, true);
        cout << alice;
        int bob = total - alice;
        if (alice - bob > 0) {
            return "Alice";
        } else if (alice-bob < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};

// DP-Memoized
class Solution {
private:
    int helper(vector<vector<int>>&dp,vector<int>& piles, int n, int i, int flag) {
        if (i >= n) {
            return 0;
        }
        if(dp[i][flag]) return dp[i][flag];
        int ans = (flag) ? INT_MIN : INT_MAX;
        int total = 0;

        for (int x = 1; x <= 3 && i+x <= n; x++) {
            total += piles[i + x-1];

            if (flag) {
                ans = max(ans, total + helper(dp,piles, n, i + x, !flag));
            } else {
                ans = min(ans, helper(dp,piles, n, i + x, !flag));
            }
        }

        return dp[i][flag] = ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int total = 0;
        for(int i = 0; i<n; i++) total += stoneValue[i];
        vector<vector<int>>dp(n,vector<int>(2,0));
        int alice = helper(dp,stoneValue, n, 0, true);
        int bob = total - alice;
        if (alice - bob > 0) {
            return "Alice";
        } else if (alice-bob < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};

// DP-Tabulization
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int total = 0;
        for(int i = 0; i<n; i++) total += stoneValue[i];
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        for(int i = n-1; i >=0; i--){
            for(int flag = 0; flag < 2; flag++){
                if(i >= n){
                    dp[i][flag] = 0;
                    continue;
                }
                int ans = (flag) ? INT_MIN : INT_MAX;
                int total = 0;

                for (int x = 1; x <= 3 && i+x <= n; x++) {
                    total += stoneValue[i + x-1];

                    if (flag) {
                        ans = max(ans, total + dp[i+x][!flag]);
                    } else {
                        ans = min(ans, dp[i+x][!flag]);
                    }
                }
                dp[i][flag] = ans;
            }
        }

        int alice = dp[0][1];
        
        int bob = total - alice;
        if (alice - bob > 0) {
            return "Alice";
        } else if (alice-bob < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};  

int main(){

    return 0;
}