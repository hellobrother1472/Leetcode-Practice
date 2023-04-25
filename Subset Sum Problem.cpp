#include <bits/stdc++.h>
using namespace std;

// Reccursion
class Solution{   
public:
    
    bool helper(vector<int>arr, int sum, int i , int n){
        if(sum == 0) return true;
        if(i == n) return false;
        
        // Taking current element
        sum -= arr[i];
        bool one = helper(arr,sum,i+1,n);
        if(one) return true;
        sum += arr[i];
        bool two = helper(arr,sum,i+1,n);
        if(two) return true;
        return false;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        return helper(arr,sum,0,n);
    }
};

// Reccursion 2
class Solution{   
public:
    bool helper(vector<int>& arr, int sum, int i){
        if(sum == 0) return true;
        if(i == arr.size()) return false;
        
        // Taking current element
        if(arr[i] <= sum){
            if(helper(arr, sum - arr[i], i+1)) return true;
        }
        
        // Not taking current element
        if(helper(arr, sum, i+1)) return true;
        
        return false;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum){
        return helper(arr, sum, 0);
    }
};

// DP
class Solution{   
public:
    
    bool helper(vector<int>arr,vector<vector<int>>&dp, int sum, int i , int n){
        if(sum == 0) return true;
        if(i == n) return false;
        if(dp[i][sum] != -1) return dp[i][sum] == 1;
        if(arr[i] <= sum && helper(arr,dp,sum - arr[i],i+1,n)){
            dp[i][sum] = 1;
            return true;
        }
        if(helper(arr,dp,sum,i+1,n)){
            dp[i][sum] = 1;
            return true;
        }
        return false;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(arr,dp,sum,0,n);
    }
};

// Tabulization 1

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        for (int i = 0; i <= n; i++) dp[i][0] = true;
    
        for(int i = n-1 ; i>=0; i--){
            // if(arr[i] <= sum) dp[i][arr[i]] = 1; 
            for(int j = sum ;  j >= 1; j--){
                
                if(arr[i] <= j && dp[i+1][j - arr[i]] == 1){
                    dp[i][j] = 1;
                }
                else if(dp[i+1][j] == 1) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
        return dp[0][sum];
    }
};

// Tabulization 2 
class Solution {
public:
    bool isSubsetSum(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(sum + 1, -1));
        
        // Base cases
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] ==1 || dp[i + 1][j - nums[i]] == 1;
                }
            }
        }
        
        return dp[0][sum] ;
    }
};

// Tabulation 3
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            bool notTaken = dp[ind-1][target];
            bool taken = false;
            if(arr[ind]<=target) taken = dp[ind-1][target-arr[ind]];
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}

// Space Optimization
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<int>prev(sum+1,-1);
        prev[0] = 1;
    
        for(int i = n-1 ; i>=0; i--){
            vector<int>curr(sum+1,-1);
            curr[0] = 1;
            for(int j = sum ;  j >= 1; j--){
                
                if(arr[i] <= j && prev[j - arr[i]] == 1){
                    curr[j] = 1;
                }
                else if(prev[j] == 1) curr[j] = 1;
                else curr[j] = 0;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

int main(){

    return 0;
}