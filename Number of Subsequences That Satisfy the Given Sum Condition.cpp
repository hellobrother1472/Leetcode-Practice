#include <bits/stdc++.h>
using namespace std;

// Reccursive
class Solution {
private:
    int helper(vector<int>&nums,int target,int mini, int maxi,int i, int n){
        if(i >= n){
            if(mini+maxi <= target) return 1;
            return 0;
        }
        int newMin = min(mini,nums[i]);
        int newMax = max(maxi,nums[i]);
        int take = helper(nums,target,newMin,newMax,i+1,n);
        int notTake = helper(nums,target,mini,maxi,i+1,n);
        return take + notTake;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(nums,target,INT_MAX,INT_MIN,0,n)-1;
    }
};

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        vector<int> exp(nums.size(),1);
        for(int i=1;i<exp.size();i++){
            exp[i]=(2*exp[i-1])%mod;
        }
        sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1,count=0;
        while(left<=right){
            if(nums[left] + nums[right] > target)
                right--;
            else{
                count=(count+exp[right - left]) % mod;
                left++;
            }
        }
        return count;
    }
};

int main(){

    return 0;
}