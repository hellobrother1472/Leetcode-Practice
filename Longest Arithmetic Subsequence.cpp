#include <bits/stdc++.h>
using namespace std;

// Using reccursion I am finding out every single element with difference diff.
class Solution {
private:
    int helper(vector<int>& nums,int n, int i, int diff,int prev){
        if(i >= n) return 0;
        if(nums[i] - prev == diff){
            return 1 + helper(nums,n,i+1,diff,nums[i]);
        }
        return helper(nums,n,i+1,diff,prev);
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return 2;
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int diff = nums[j] - nums[i];
                maxLen = max(maxLen,helper(nums,n,j+1,diff,nums[j]));
            }
        }
        return maxLen + 2;
    }
};

int main(){

    return 0;
}