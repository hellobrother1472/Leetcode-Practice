#include <bits/stdc++.h>
using namespace std;

// Brute force
class Solution{
    public:
    
    int longestCommonSubstr(string S1, string S2, int n, int m){
        int maxLen = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int len = 0;
                while(i+len<n && j+len<m && S1[i+len]==S2[j+len]){
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;  
    }

};

// Tabulation
class Solution{
    public:    
    int longestCommonSubstr(string S1, string S2, int n, int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans = -1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(S1[i-1] == S2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 0;
                ans = max(dp[i][j],ans);
            }
            
        }
        return ans;
    }
};

int main(){

    return 0;
}