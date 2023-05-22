#include <bits/stdc++.h>
using namespace std;

// Reccursive
class Solution {
private:
    bool helper(string s, string p,int n, int m, int i,int j){
        if(j>=m && i>=n) return true;
        if(i>=n && p[j] == '*') return helper(s,p,n,m,i,j+1);
        if((j>=m && i < n) || (j<m && i>=n)) return false;
        if(s[i]!=p[j] && p[j]!= '?' && p[j] != '*') return false;

        if(p[j] == '?' || s[i] == p[j]) return helper(s,p,n,m,i+1,j+1);
        bool take, notTake,takeOne;
        if(p[j] == '*'){
            take = helper(s,p,n,m,i+1,j);
            notTake = helper(s,p,n,m,i,j+1);
            takeOne = helper(s,p,n,m,i+1,j+1);
        }
        return take || notTake || takeOne;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        return helper(s,p,n,m,0,0);
    }
};

// Reccursive-modified
class Solution {
private:
    bool helper(vector<vector<bool>>&dp,string s, string p,int n, int m, int i,int j){
        if(j>=m && i>=n) return true;
        if(j>=m && i < n) return false;
        if(j<m && i>=n){
            for(int k = j; k < m; k++){
                if(p[k]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]) return dp[i][j];

        if(p[j] == '?' || s[i] == p[j]) return dp[i][j] = helper(dp,s,p,n,m,i+1,j+1);
        if(p[j] == '*'){
            bool take = helper(dp,s,p,n,m,i+1,j);
            bool notTake = helper(dp,s,p,n,m,i,j+1);
            return dp[i][j] = take || notTake;
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>>dp(n,vector<bool>(m,false));
        return helper(dp,s,p,n,m,0,0);
    }
};

// DP- Tabularization
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[n][m] = true;
        for(int i = 0 ; i < n; i++){
            dp[i][m] = false;
        }
        for(int i = 0 ; i < m; i++){
            bool flag = true;
            for(int k = i; k < m; k++){
                if(p[k]!='*'){
                    dp[n][i] = false;
                    flag = false;
                    break;
                }
            }
            if(flag) dp[n][i] = true;
        }

        for(int i = n-1 ; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(p[j] == '?' || s[i] == p[j]) dp[i][j] = dp[i+1][j+1];
                else if(p[j] == '*'){
                    bool take = dp[i+1][j];
                    bool notTake = dp[i][j+1];
                    dp[i][j] = take || notTake;
                }
                else dp[i][j] = false;
            }
        }
        return dp[0][0];
    }
};

int main(){

    return 0;
}