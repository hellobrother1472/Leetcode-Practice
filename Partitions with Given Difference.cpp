#include <bits/stdc++.h>
using namespace std;

// As we want s1 - s2 = d, also we know s1 + s2 = T, so the equation becomes 2s1 - t = d => s1 = (d + t) / 2, 
// So this question boils down to finding total partition with sum s1.
// Reccursion
class Solution {
  private:
    int helper(int n, int target, vector<int>& arr, int i){
        if(i == n){
            if(target == 0) return 1;
            else return 0;
        }
        
        int take = helper(n,target-arr[i],arr,i+1);
        int notTake =  helper(n,target,arr,i+1);
        return take + notTake;
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalSum = 0;
        for(int i = 0 ; i< n; i++){
            totalSum += arr[i];
        }
        if((totalSum - d) % 2 != 0) return 0;
        return helper(n,(totalSum-d)/2,arr,0);
    }
};

// DP
class Solution {
  private:
    int helper(int n,vector<vector<int>>&dp, int target, vector<int>& arr, int i){
        if(i == n){
            if(target == 0) return 1;
            else return 0;
        }
        if(dp[i][target]) return dp[i][target];
        int take = helper(n,dp,target-arr[i],arr,i+1);
        int notTake =  helper(n,dp,target,arr,i+1);
        return dp[i][target] = take + notTake;
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalSum = 0;
        for(int i = 0 ; i< n; i++){
            totalSum += arr[i];
        }
        vector<vector<int>>dp(n,vector<int>(totalSum,0));
        if((totalSum - d) % 2 != 0) return 0;
        return helper(n,dp,(totalSum-d)/2,arr,0);
    }
};

// Tabulization

class Solution {
  
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int MOD = 1e9 + 7;
        int totalSum = 0;
        for(int i = 0 ; i< n; i++){
            totalSum += arr[i];
        }
        if((totalSum + d) % 2 != 0) return 0;
        int target = (totalSum + d) / 2;
        
        vector<vector<long long>>dp(n+1,vector<long long>(target+1,0));
        for(int i = 0 ; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for(int i = n-1 ; i >= 0; i--){
            for (int s = target; s >= 0; s--)
            {
                dp[i][s] = dp[i + 1][s];
                if (s >= arr[i])
                {
                    dp[i][s] += dp[i + 1][s - arr[i]];
                }
                dp[i][s] = dp[i][s] % MOD;
            }
        }
        return dp[0][target];
    }
};

int main(){

    return 0;
}