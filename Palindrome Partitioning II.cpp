#include <bits/stdc++.h>
using namespace std;

// Reccursion
class Solution {
private:
    bool checkPalindrome(string temp,int i, int j){
        int n = j-i+1;
        if(n == 1 || n == 0) return true;
        while(j > i){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(string s,int i,int j){
        if(i > j || i == j || checkPalindrome(s,i,j)) return 0;
        int mini = INT_MAX;
        for(int k = i; k < j;k++){
            int sol = 1 + helper(s,i,k) + helper(s,k+1,j);
            mini = min(sol,mini);
        }
        return mini;
    }

public:
    int minCut(string s) {
        int n = s.size();
        if(n == 1 || checkPalindrome(s,0,n-1)) return 0;
        return helper(s,0,n-1);
    }
};

// Reccursion 2 - Partitioning only when previous is palindrom.
class Solution {
private:
    bool checkPalindrome(string temp,int i, int j){
        int n = j-i+1;
        if(n == 1 || n == 0) return true;
        while(j > i){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(vector<int>&dp,string s,int i,int n){
        if(i == n || checkPalindrome(s,i,n-1)) return 0;
        if(dp[i]) return dp[i];
        int mini = INT_MAX;
        for(int k = i; k < n-1;k++){
            if(!checkPalindrome(s,i,k)) continue;
            int sol = 1 + helper(dp,s,k+1,n);
            mini = min(sol,mini);
        }
        return dp[i] = mini;
    }

public:
    int minCut(string s) {
        int n = s.size();
        if(n == 1 || checkPalindrome(s,0,n-1)) return 0;
        vector<int>dp(n,0);        
        return helper(dp,s,0,n);
    }
};

// DP-Memoization
class Solution {
private:
    bool checkPalindrome(string temp,int i, int j){
        int n = j-i+1;
        if(n == 1 || n == 0) return true;
        while(j > i){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(vector<int>&dp,string s,int i,int n){
        if(i == n) return 0;
        if(dp[i]) return dp[i];
        int mini = INT_MAX;
        for(int k = i; k < n;k++){
            if(!checkPalindrome(s,i,k)) continue;
            int sol = 1 + helper(dp,s,k+1,n);
            mini = min(sol,mini);
        }
        return dp[i] = mini;
    }

public:
    int minCut(string s) {
        int n = s.size();
        if(n == 1 || checkPalindrome(s,0,n-1)) return 0;
        vector<int>dp(n,0);        
        return helper(dp,s,0,n)-1;
    }
};

int main(){

    return 0;
}