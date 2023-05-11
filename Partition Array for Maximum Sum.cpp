#include <bits/stdc++.h>
using namespace std;

// As we have the power to partion such that it only contains atmost k elments so that's why for loop is from i to k
// The helper function is checking every single partition possible, for that a maxum variable is declared who keeps track of maximum variable till now as we need to maximize the sum if all the elements of the partition is replaced with maxum so that's why (j-i+1)*maxum (total elements * maxum).
// after that just add helper of remaining array where i from j+1.

// Reccursive
class Solution {
private:
    int helper(vector<int>& arr, int k,int i,int n){
        if(i == n) return 0;
        int maxum = INT_MIN, maxi = INT_MIN;
        for(int j = i; j < i + k && j < n; j++){
            if(arr[j] > maxum) maxum = arr[j];
            int sol = (j-i+1)*maxum + helper(arr,k,j+1,n);
            maxi = max(sol,maxi);
        }
        return maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return helper(arr,k,0,n);
    }
};

// DP-Memoized
class Solution {
private:
    int helper(vector<int>dp,vector<int>& arr, int k,int i,int n){
        if(i == n) return 0;
        if(dp[i]) return dp[i];
        int maxum = INT_MIN, maxi = INT_MIN;
        for(int j = i; j < i + k && j < n; j++){
            if(arr[j] > maxum) maxum = arr[j];
            int sol = (j-i+1)*maxum + helper(dp,arr,k,j+1,n);
            maxi = max(sol,maxi);
        }
        return dp[i] = maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,0);
        return helper(dp,arr,k,0,n);
    }
};

// DP-Tabularization
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        for(int i = n-1; i >= 0; i--){
            int maxum = INT_MIN, maxi = INT_MIN;
            for(int j = i; j < i + k && j < n; j++){
                if(arr[j] > maxum) maxum = arr[j];
                int sol = (j-i+1)*maxum + dp[j+1];
                maxi = max(sol,maxi);
            }
            dp[i] = maxi;
        }
        return dp[0];
    }
};

int main(){
    

    return 0;
}