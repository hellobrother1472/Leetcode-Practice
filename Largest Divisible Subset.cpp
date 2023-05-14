#include <bits/stdc++.h>
using namespace std;

// Way similar to print all increasing subsequence with codition change.
// As we want subset not subsequence same order is not required, so in starting I sort so that dividing will good

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n, 1),hash(n);
        
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if ((nums[i] % nums[j] == 0) && dp[j]+1 > dp[i]) {
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
        
        // reverse the array 
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

int main(){

    return 0;
}