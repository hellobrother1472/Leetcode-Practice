#include <bits/stdc++.h>
using namespace std;

// Consider i be the pointer at word1 and j be the pointer at word2
// At any instance or at any i and j I can do three operations either I can replace or I can delete or I can insert a new element. Or if those two elements are equal then I just simply move forward.
// In case of replace one operation is done and as I will replace the j with i means both index will move forward.
// In case of delete I delete i so, j remains at it's place and i will move forward because i is deleted and so i will shift to next.
// In case of insertion an extra character added which is equal to j so j increases but in case of i, i will remains at it place as insertion happens backward. Imagine just after insertion i is points at inserted element, so in the next step when i increases it will come to previous i, so that's why i does'nt changes.
// In base case thier can be two conditions, which are :
// if j reaches end means we have made the string but thier may be some remaining elements in i so we have to perform deletion for them so return total number of deletion required
// if i reaches end and j is not means we still are not able to made the string so we have to perform insertions until we make j, so to make j we have to return total number of insertion required.

// Reccursion
class Solution {
public:
    int helper(string word1, string word2, int n, int m, int i, int j){
        if(i>=n || j>=m){
            if(j>=m) return n - i;
            return m-j;
        }
        if(word1[i] == word2[j]) return helper(word1,word2,n,m,i+1,j+1);
        int replace = 1 + helper(word1,word2,n,m,i+1,j+1);
        int del = 1 + helper(word1,word2,n,m,i+1,j);
        int ins = 1 + helper(word1,word2,n,m,i,j+1);
        return min(replace,min(del,ins));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        return helper(word1,word2,n,m,0,0);
    }
};

// DP
class Solution {
public:
    int helper(vector<vector<int>>&dp,string word1, string word2, int n, int m, int i, int j){
        if(i>=n || j>=m){
            if(j>=m) return n - i;
            return m-j;
        }
        if(dp[i][j]) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = helper(dp,word1,word2,n,m,i+1,j+1);
        int replace = 1 + helper(dp,word1,word2,n,m,i+1,j+1);
        int del = 1 + helper(dp,word1,word2,n,m,i+1,j);
        int ins = 1 + helper(dp,word1,word2,n,m,i,j+1);
        return dp[i][j] = min(replace,min(del,ins));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        return helper(dp,word1,word2,n,m,0,0);
    }
};

// DP-Tabularization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 0 ; i < n; i++){
            dp[i][m] = n-i;
        }
        for(int i = 0 ; i < m; i++){
            dp[n][i] = m-i;
        }
        for(int i = n-1; i >= 0; i--){            
            for(int j = m-1; j >= 0; j--){
                if(word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                else{
                    int replace = 1 + dp[i+1][j+1];
                    int del = 1 + dp[i+1][j];
                    int ins = 1 + dp[i][j+1];
                    dp[i][j] = min(replace,min(del,ins));
                }
            }           
        }
        return dp[0][0];
    }
};

int main(){

    return 0;
}