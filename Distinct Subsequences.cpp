#include <bits/stdc++.h>
using namespace std;

// The approach is to reccursively find distinct subsequence, first if the word matches then we make i2-1 and serch that subsequence,and for all the possibilities one time we ignore current match and try to find that if their is other match in the string without current.
// If not matches then simply i1+1 to search further.
// Reccursive
class Solution {
private:
    int helper(string s, string t,int i1, int i2,int n, int m){
        if(i1>=n || i2 >= m){
            if(i2>=m) return 1;
            return 0;
        }
        if(s[i1] == t[i2]){
            return helper(s,t,i1+1,i2+1,n,m) + helper(s,t,i1+1,i2,n,m);
        }
        return helper(s,t,i1+1,i2,n,m);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        return helper(s,t,0,0,n,m);
    }
};

// DP
class Solution {
private:
    int helper(vector<vector<int>>&dp,string s, string t,int i1, int i2,int n, int m){
        if(i1>=n || i2 >= m){
            if(i2>=m) return 1;
            return 0;
        }
        if(dp[i1][i2]) return dp[i1][i2];
        if(s[i1] == t[i2]){
            return dp[i1][i2] = helper(dp,s,t,i1+1,i2+1,n,m) + helper(dp,s,t,i1+1,i2,n,m);
        }
        return dp[i1][i2] = helper(dp,s,t,i1+1,i2,n,m);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        return helper(dp,s,t,0,0,n,m);
    }
};

// Tabularization
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i = 0; i <= n; i++){
            dp[i][m] = 1;
        }        
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                }
                else dp[i][j] = dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};

int main(){

    return 0;
}