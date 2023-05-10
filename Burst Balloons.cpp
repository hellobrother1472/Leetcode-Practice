#include <bits/stdc++.h>
using namespace std;

// Reccursive - Trying out all possible cases.
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] == -1) continue;
            int val = nums[j];
            int left = 1, right = 1;
            int k = j;
            if(k > 0){
                k--;
                while(k>=0 && nums[k] == -1) k--;
                if(k >= 0 && nums[k] != -1) left = nums[k];
            }
            k = j;
            if(k < n-1){
                k++;
                while(k<n && nums[k] == -1) k++;
                if(k < n && nums[k] != -1) right = nums[k];
            }
            nums[j] = -1;
            int sol = val*right*left + maxCoins(nums);
            nums[j] = val;
            maxi = max(sol,maxi); 
        }
        return maxi;
    }
};

// Reccursion 2 - Thinking backwards, means we are thinking what happend at last then before that and so on.
// https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52
class Solution {
private:
    int helper(vector<int>& nums, int i,int j){
        if(i > j) return 0;
        int maxi = 0;
        for(int k = i; k <=j; k++){
            int sol = nums[i - 1] * nums[k] * nums[j + 1] + helper(nums,i,k-1) + helper(nums,k+1,j);
            maxi = max(sol,maxi);
        }
        return maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return helper(nums,1,nums.size()-2);
    }
};

// DP-Memoization
class Solution {
private:
    int helper(vector<vector<int>>&dp,vector<int>& nums, int i,int j){
        if(i > j) return 0;
        if(dp[i][j]) return dp[i][j];
        int maxi = 0;
        for(int k = i; k <=j; k++){
            int sol = nums[i - 1] * nums[k] * nums[j + 1] + helper(dp,nums,i,k-1) + helper(dp,nums,k+1,j);
            maxi = max(sol,maxi);
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        return helper(dp,nums,1,n-2);
    }
};

// DP-Tabularization

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = n-2; i > 0; i--){
            for(int j = 1; j < n-1; j++){
                if(i <= j){
                    int maxi = 0;
                    for(int k = i; k <=j; k++){
                        int sol = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k-1] + dp[k+1][j];
                        maxi = max(sol,maxi);
                    }
                    dp[i][j] = maxi;
                }
            }
        }
        return dp[1][n-2];
    }
};

int main(){

    return 0;
}