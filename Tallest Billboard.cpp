#include <bits/stdc++.h>
using namespace std;

// First approach is that we have three options skip, take it in first rod or take it in second rod. Now return the value if first become equal to second or return zero.
class Solution {
private:
    int helper(vector<int>& rods, int n, int i,int first,int second){
        if(i == n){
            if(first == second) return first;
            return 0;
        }
        int maxi = 0;
        int notTake = helper(rods,n,i+1,first,second);
        int takeInFirstRod = helper(rods,n,i+1,first+rods[i],second);
        int takeInSecondRod = helper(rods,n,i+1,first,second+rods[i]);
        return max(notTake,max(takeInFirstRod,takeInSecondRod));
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        return helper(rods,n,0,0,0);
    }
};


// As we only require difference to be zero so we take that in consideration and optimize the approach. Now we consider (first-second), and we consider length of one rod only
// So if we take in first then diff will increase and if we take that element in second then difference is decreased.
// Helper function returns maximum value of first rod that can be formed considering the given conditions.
class Solution {
private:
    int helper(vector<int>& rods,vector<unordered_map<int,int>>&dp, int n, int i,int diff){
        if(i == n){
            if(diff == 0) return 0;
            return INT_MIN;
        }
        if(dp[i][diff]) return dp[i][diff];
        int notTake = helper(rods,dp,n,i+1,diff); // Length of first if we not take
        int takeInFirstRod = rods[i] + helper(rods,dp,n,i+1,diff+rods[i]); // Length of first if we take in first
        int takeInSecondRod = helper(rods,dp,n,i+1,diff - rods[i]); // Length of first if we take in second 
        return dp[i][diff] = max(notTake,max(takeInFirstRod,takeInSecondRod));
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<unordered_map<int,int>>dp(n);
        return helper(rods,dp,n,0,0);
    }
};

// Same algorithm with small edit using constraints given in question
class Solution {
private:
    int helper(vector<int>& rods,vector<vector<int>>&dp, int n, int i,int diff){
        if(i == n){
            if(diff == 0) return 0;
            return INT_MIN;
        }
        if(dp[i][diff+5000] != -1) return dp[i][diff+5000];
        int notTake = helper(rods,dp,n,i+1,diff);
        int takeInFirst = rods[i] + helper(rods,dp,n,i+1,diff+rods[i]);
        int takeInSecond = helper(rods,dp,n,i+1,diff - rods[i]);
        return dp[i][diff+5000] = max(notTake,max(takeInFirst,takeInSecond));
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>>dp(n,vector<int>(10000,-1));
        return helper(rods,dp,n,0,0);
    }
};

int main(){

    return 0;
}