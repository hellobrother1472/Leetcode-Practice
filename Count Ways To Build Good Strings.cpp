#include <bits/stdc++.h>
using namespace std;

// Reccursive
class Solution {
private:
    int mod = 1000000000 + 7;
    int helper(int low, int high, int zero, int one,int length){
        if(length > high) return 0;
        int ones = helper(low,high,zero,one,length+one);
        int zeros = helper(low,high,zero,one,length+zero);
        if(length <= high && length >= low) return (1 + ones+zeros) % mod;
        return (ones+zeros)%mod;
    }
public:
    int lengthGoodStrings(int low, int high, int zero, int one) {
        return helper(low,high,zero,one,0);
    }
};

// DP-Memoization
class Solution {
private:
    int mod = 1000000000 + 7;
    int helper(vector<int>&dp,int low, int high, int zero, int one,int length){
        if(length > high) return 0;
        if(dp[length]) return dp[length];
        int ones = helper(dp,low,high,zero,one,length+one);
        int zeros = helper(dp,low,high,zero,one,length+zero);
        if(length <= high && length >= low) return dp[length] = (1 + ones+zeros) % mod;
        return dp[length] = (ones+zeros)%mod;
    }
public:
    int lengthGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,0);
        return helper(dp,low,high,zero,one,0);
    }
};

// DP-Tabularization
class Solution {
private:
    int mod = 1000000000 + 7;
public:
    int lengthGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+max(zero,one)+1,0);
        for(int length = high; length >= 0; length--){
            int ones = dp[length+one];
            int zeros = dp[length+zero];
            if(length <= high && length >= low) dp[length] = (1 + ones+zeros) % mod;
            else dp[length] = (ones+zeros)%mod;
        }
        return dp[0];
    }
};

int main(){

    return 0;
}