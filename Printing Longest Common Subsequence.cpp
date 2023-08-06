#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2,vector<vector<int>>&dp) {
    
    int n=s1.size();
    int m=s2.size();
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
}


string findLCS(int n, int m, string &s1, string &s2){
    // Write your code here.    
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int length = lcs(s1,s2,dp);
    
    int i = n, j = m;
    string ans = "";
    while(i > 0 && j > 0){
        int up = dp[i-1][j];
        int left = dp[i][j-1];
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }
        else if(up >= left) i--;
        else j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main(){

    return 0;
}