#include <bits/stdc++.h>
using namespace std;

// Its all about take or not take, just at every point check that it must be greater than previous.
// Reccursion
class Solution {
private:
    int helper(vector<int>& nums,int n, int prev, int i){
        if(i >= n ) return 0;
        int take = 0;
        if(prev == n || nums[i] > nums[prev]) take = 1 + helper(nums,n,i,i+1);
        int notTake = helper(nums,n,prev,i+1);      
        return max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,n,n,0);
    }
};

// DP-Memoization
class Solution {
private:
    int helper(vector<vector<int>>&dp,vector<int>& nums,int n, int prev, int i){
        if(i >= n ) return 0;
        int take = 0;
        if(dp[i][prev]) return dp[i][prev];
        if(prev == n || nums[i] > nums[prev]) take = 1 + helper(dp,nums,n,i,i+1);
        int notTake = helper(dp,nums,n,prev,i+1);      
        return dp[i][prev] = max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        return helper(dp,nums,n,n,0);
    }
};

// DP-Memoization
class Solution {
private:
    int helper(vector<vector<int>>&dp,vector<int>& nums,int n, int prev, int i){
        if(i >= n ) return 0;
        int take = 0;
        if(dp[i][prev+1]) return dp[i][prev+1];
        if(prev == -1 || nums[i] > nums[prev]) take = 1 + helper(dp,nums,n,i,i+1);
        int notTake = helper(dp,nums,n,prev,i+1);      
        return dp[i][prev+1] = max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        return helper(dp,nums,n,-1,0);
    }
};

// DP-Tabulization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        for(int i = n-1; i >=0; i--){
            for(int j = i-1; j >=-1; j--){
                int take = 0;
                if(j == -1 || nums[i] > nums[j]) take = 1 + dp[i+1][i+1];
                int notTake = dp[i+1][j+1];      
                dp[i][j+1] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
};

// Space optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n+2,0);
        for(int i = n-1; i >=0; i--){
            vector<int>curr(n+2,0);
            for(int j = i-1; j >=-1; j--){
                int take = 0;
                if(j == -1 || nums[i] > nums[j]) take = 1 + next[i+1];
                int notTake = next[j+1];      
                curr[j+1] = max(take,notTake);
            }
            next = curr;
        }
        return next[0];
    }
};


// New approach - https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Using Binary search - https://youtu.be/on2hvxBXJH4?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i] > temp.back()) temp.push_back(nums[i]);
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};

int main(){

    return 0;
}