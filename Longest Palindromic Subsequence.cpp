#include <bits/stdc++.h>
using namespace std;

// As palindrome means that if we reverse the string then it will be same to previous. So to get the maximum length of a palindromic subsequence, we have to find an subsequence which is palindromic. So if we reverse the given string and then find the max length common subsequence, then the answer we got will automatically is palindrome as we are reversing the given string to get the second string.

// DP-Tabulization
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(s.begin(), s.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i = n-1; i >=0 ;i--){
            for(int j = n-1; j >=0 ;j--){
                if(s[i] == t[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};

int main(){

    return 0;
}