#include <bits/stdc++.h>
using namespace std;

// As we need total deletion required, so first find longest common subsequence so as you find that then remove that from both strings, so the remaining letters in the string are the ones which we want to delete. So sum their sizes and return.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = n-1; i >=0 ;i--){
            for(int j = m-1; j >=0 ;j--){
                if(word1[i] == word2[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return (n - dp[0][0]) + (m-dp[0][0]);
    }
};

int main(){

    return 0;
}