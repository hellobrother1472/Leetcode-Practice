#include <bits/stdc++.h>
using namespace std;

// To find it first I found Longest palindromic subsequence and so after that as we got the max length palindrome present, now it means that the remaining letters which are not the palindrom we need to add one copy of that, so to find the remaining letters we do n-dp and this is also the answer because it is the amount of letters we need to push.

class Solution {
public:
    int minInsertions(string s) {
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
        return n-dp[0][0];
    }
};

int main(){

    return 0;
}