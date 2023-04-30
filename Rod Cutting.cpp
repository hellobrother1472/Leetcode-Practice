#include <bits/stdc++.h>
using namespace std;

// The approach is that imagine if we take one length peice then ask reccursion to solve question for N-1, in next iteration check for if length of peice is two and ask reccursion to solve for N-2 and so on and get max.
// Reccursion
class Solution{
  private:
    int helper(int price[], int n){
        if(n==0) return 0;
        int maxi = INT_MIN;
        for(int i = 1; i <= n; i++){
            int val = price[i-1] + helper(price,n-i);
            maxi = max(maxi,val);
        }
        return maxi;
    }
  public:
    int cutRod(int price[], int n) {
        helper(price,n);
    }
};

// Using DP
class Solution{
  private:
    int helper(int price[],vector<int>&dp, int n){
        if(n==0) return 0;
        int maxi = INT_MIN;
        if(dp[n]) return dp[n];
        for(int i = 1; i <= n; i++){
            int val = price[i-1] + helper(price,dp,n-i);
            maxi = max(maxi,val);
        }
        return dp[n] = maxi;
    }
  public:
    int cutRod(int price[], int n) {
        vector<int>dp(n+1,0);
        return helper(price,dp,n);
    }
};

// Tabulization
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int>dp(n+1,0);
        for(int i = n; i >= 1; i--){
            int maxi = INT_MIN;
            for(int j = n-i+1; j>=1; j--){
                int val = price[j-1] + dp[i+j-1];
                maxi = max(maxi,val);
            }
            dp[i-1] = maxi;
        }
        return dp[0];
    }
};


// This problem can be also solved by thinking of concept that we have to collect some lenghts to get total length N and have max value.
int main(){

    return 0;
}