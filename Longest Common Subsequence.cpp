#include <bits/stdc++.h>
using namespace std;

// Approach is that we are starting from string length of 1 if that matches me take both the pointers aage and check further reccursively which is 1 + helper() here 1 is added because we got one equal element.
// If they are not equal then their is two possibility of either moving i1 or i2 so we take both possibility and then return max of both.
// If anyone of the i1 or i2 reaches greater than end it means we reach end and we must return 0;
// Reccursive
class Solution {
private:
    int helper(string text1, string text2, int i1, int i2){
        if(i1>=text1.size() || i2 >= text2.size()) return 0;
        if(text1[i1] == text2[i2]) return 1 + helper(text1,text2,i1+1,i2+1);
        return max(helper(text1,text2,i1,i2+1),helper(text1,text2,i1+1,i2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return helper(text1,text2,0,0);
    }
};

// DP-Memoized
class Solution {
private:
    int helper(vector<vector<int>>&dp,string text1, string text2, int i1, int i2){
        if(i1>=text1.size() || i2 >= text2.size()) return 0;
        if(dp[i1][i2]) return dp[i1][i2];
        if(text1[i1] == text2[i2]) return dp[i1][i2] = 1 + helper(dp,text1,text2,i1+1,i2+1);
        return dp[i1][i2] = max(helper(dp,text1,text2,i1,i2+1),helper(dp,text1,text2,i1+1,i2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(),0));
        return helper(dp,text1,text2,0,0);
    }
};

// Tabulization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1,0));
        for(int i1 = n1-1; i1 >= 0; i1--){
            for(int i2 = n2-1; i2 >= 0; i2--){
                if(text1[i1] == text2[i2]) dp[i1][i2] = 1 + dp[i1+1][i2+1];
                else dp[i1][i2] = max(dp[i1][i2+1], dp[i1+1][i2]);
            }            
        }
        return dp[0][0];
    }
};

// Space optimization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1,0));
        vector<int>prev(n2+1,0);
        for(int i1 = n1-1; i1 >= 0; i1--){
            vector<int>curr(n2+1,0);
            for(int i2 = n2-1; i2 >= 0; i2--){
                if(text1[i1] == text2[i2]) curr[i2] = 1 + prev[i2+1];
                else curr[i2] = max(curr[i2+1], prev[i2]);
            }          
            prev = curr;  
        }
        return prev[0];
    }
};

int main(){

    return 0;
}