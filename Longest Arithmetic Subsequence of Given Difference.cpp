#include <bits/stdc++.h>
using namespace std;

// Using dp and storing the answer in dp. Check with every number and do reccursive as we go further and then during backtracking the dp[i] number of valid subsequence which have above this i.
class Solution {
private:
    int helper(vector<int>& arr, int difference, int i,vector<int>&dp){
        int ans = 0;
        if(dp[i] != -1) return dp[i];
        for(int j = i+1; j < arr.size(); j++){
            if(arr[j] - arr[i] == difference) ans = max(ans,helper(arr,difference,j,dp));
        }
        return dp[i] = ans + 1;
    }
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int>dp(n,-1);
        int maxi = 0;
        for(int i = 0; i < n;i++){
            if(dp[i] == -1) maxi = max(maxi,helper(arr,difference,i,dp));
            else maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};

int main(){

    return 0;
}