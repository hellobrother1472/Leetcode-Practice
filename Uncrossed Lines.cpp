#include <bits/stdc++.h>
using namespace std;

// We just have to find longest common subsequence.
// Reccursive
class Solution {
private:
    int helper(vector<int>& nums1, vector<int>& nums2,int n1, int n2, int i, int j){
        if(i >= n1 || j >= n2) return 0;
        int maxi = 0;
        if(nums1[i] == nums2[j]){
            maxi = 1 + helper(nums1,nums2,n1,n2,i+1,j+1);
        }
        else{
            maxi = max(helper(nums1,nums2,n1,n2,i+1,j),helper(nums1,nums2,n1,n2,i,j+1));
        }
        return maxi;
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        return helper(nums1,nums2,n1,n2,0,0);
    }
};

// DP-Memoized
class Solution {
private:
    int helper(vector<vector<int>>&dp,vector<int>& nums1, vector<int>& nums2,int n1, int n2, int i, int j){
        if(i >= n1 || j >= n2) return 0;
        if(dp[i][j]) return dp[i][j];
        int maxi = 0;
        if(nums1[i] == nums2[j]){
            maxi = 1 + helper(dp,nums1,nums2,n1,n2,i+1,j+1);
        }
        else{
            maxi = max(helper(dp,nums1,nums2,n1,n2,i+1,j),helper(dp,nums1,nums2,n1,n2,i,j+1));
        }
        return dp[i][j] = maxi;
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,0));
        return helper(dp,nums1,nums2,n1,n2,0,0);
    }
};

// DP-Tabularization
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i = n1-1; i >= 0; i--){
            for(int j = n2-1; j >= 0; j--){
                int maxi = 0;
                if(nums1[i] == nums2[j]){
                    maxi = 1 + dp[i+1][j+1];
                }
                else{
                    maxi = max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[0][0];
    }
};

int main(){

    return 0;
}