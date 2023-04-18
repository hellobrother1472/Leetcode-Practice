#include <bits/stdc++.h>
using namespace std;

// Using Reccursion
class Solution {
  private:
    int minCost(vector<int>& height, int n, int k, int i){
        if(i >= n-1){
            if(i == n-1){
                return 0;
            }
            return INT_MAX;
        }
        int min = INT_MAX;
        for(int j = 1; j <= k;j++){
            int num = INT_MAX;
            if(i+j < n) num = abs(height[i]-height[i+j]) + minCost(height,n,k,i+j);
            if(num < min) min = num;
        }
        return min;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        return minCost(height,n,k,0);
    }
};

// Using DP - adding memoization
class Solution {
  private:
    unordered_map<int,int>memo;
    int minCost(vector<int>& height, int n, int k, int i){
        if(i >= n-1){
            if(i == n-1){
                return 0;
            }
            return INT_MAX;
        }
        
        if(!memo[i]){
            int min = INT_MAX;
            for(int j = 1; j <= k;j++){
                int num = INT_MAX;
                if(i+j < n) num = abs(height[i]-height[i+j]) + minCost(height,n,k,i+j);
                if(num < min) min = num;
            }
            memo[i] = min;
        }
        return memo[i];
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        return minCost(height,n,k,0);
    }
};

// Tabulation
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,0);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            int min = INT_MAX;
            for(int j = 1; j <= k;j++){
                int num = INT_MAX;
                if(i+j < n) num = abs(height[i]-height[i+j]) + dp[i+j];
                if(num < min) min = num;
            }
            dp[i] = min;
        }
        return dp[0];
    }
};

int main(){

    return 0;
}