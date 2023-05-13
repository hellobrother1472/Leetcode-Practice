#include <bits/stdc++.h>
using namespace std;

// Reccursive
class Solution {
    long long helper(vector<vector<int>>& questions,int i,int n){
        if(i >= n) return 0;
        long long take = questions[i][0] + helper(questions,i+questions[i][1]+1,n);
        long long notTake = helper(questions,i+1,n);
        return max(take,notTake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        return helper(questions,0,n);
    }
};

// DP-Memoization
class Solution {
    long long helper(vector<long long>&dp,vector<vector<int>>& questions,int i,int n){
        if(i >= n) return 0;
        if(dp[i]) return dp[i];
        long long take = questions[i][0] + helper(dp,questions,i+questions[i][1]+1,n);
        long long notTake = helper(dp,questions,i+1,n);
        return dp[i] = max(take,notTake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n,0);
        return helper(dp,questions,0,n);
    }
};

// DP-Tabularization
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n+1,0);
        for(int i = n-1 ; i >= 0; i--){
            long long take = questions[i][0];
            if(i+questions[i][1]+1 <= n) take += dp[i+questions[i][1]+1] ;
            long long notTake = dp[i+1];
            dp[i] = max(take,notTake);
        }
        return dp[0];
    }
};

int main(){

    return 0;
}