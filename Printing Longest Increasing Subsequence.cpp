#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/IFfYfonAFGc?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&t=1061
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        
        vector<int> dp(n, 1),hash(n);
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j]+1 > dp[i]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }            
        }
        int ans = -1;
        int lastIndex =-1;
        
        for(int i=0; i<=n-1; i++){
            if(dp[i]> ans){
                ans = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        
        while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);    
        }
        
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

int main(){

    return 0;
}