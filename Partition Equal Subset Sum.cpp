#include <bits/stdc++.h>
using namespace std;

// Reccursion
// In reccursive calls I am having all the subsets and taking the value of totalSum and currSum with me as soon as currSum == totalsum I return true .
class Solution {
private:
    bool helper(vector<int>& nums, int currSum, int totalSum, int i){
        if(currSum == totalSum) return true;
        for(int j = i; j < nums.size(); j++){
            if(helper(nums, currSum + nums[j], totalSum - nums[j], j+1)) return true;
        }
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0 ; i< nums.size(); i++) totalSum += nums[i];
        return helper(nums, 0, totalSum, 0);
    }
};

// We need to divide the array in two subsets of equal sum means S1 + S2 = TotalSum so if we want s1 = s2 then what we want is boiles down, to we need an array whose sum is totalSum/2.
// I am using code from problem Subset Sum Problem

class Solution {
private:
    bool helper(vector<int>arr, int sum){
        // Using space optimized tabularize dp solution of problem Subset Sum Problem
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
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0 ; i< nums.size(); i++) totalSum += nums[i];
        if(totalSum%2 != 0) return false;
        return helper(nums,totalSum/2);
    }
};

int main(){

    return 0;
}