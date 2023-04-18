#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=EgG3jsGoPvQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=4
// Reccursive solution
class Solution {
  public:
    int min = INT_MAX;
    void helper(vector<int>&height, int n, int i, int energy){
        if(i >= n-1 || energy >= min){
            if(i==n-1 && energy < min){
                min = energy;
            }
            return;
        }
        if(i < n-1) helper(height,n,i+1, energy + abs(height[i] - height[i+1]));
        if(i < n-2) helper(height,n,i+2, energy + abs(height[i] - height[i+2]));

    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        helper(height, n, 0, 0);
        return min;
    }
};

// Reccursion 2
class Solution {
  public:
    int helper(vector<int>&height, int n, int i, int energy){
        if(i >= n-1){
            if(i==n-1) return energy;            
            return INT_MAX;
        }
        int one = INT_MAX, two = INT_MAX;
        if(i < n-1) one = helper(height,n,i+1, energy + abs(height[i] - height[i+1]));
        if(i < n-2) two = helper(height,n,i+2, energy + abs(height[i] - height[i+2]));
        
        return min(one,two);
    }
    int minimumEnergy(vector<int>& height, int n) {
        return helper(height, n, 0, 0);
    }
};

// Recurrsion 3
class Solution {
  public:
    unordered_map<int,int>memo;
    int helper(vector<int>&height, int n, int i){
        if(i >= n-1){
            if(i==n-1){
                return 0;
            }
            return INT_MAX;
        }
        int one = INT_MAX, two = INT_MAX;
        if(i < n-1 ) one = abs(height[i]-height[i+1]) + helper(height,n,i+1);
        if(i < n-2) two = abs(height[i]-height[i+2]) + helper(height,n,i+2);
        return min(one,two);
    }
    int minimumEnergy(vector<int>& height, int n) {
        return helper(height, n, 0);
    }
};

// DP - Applying memoization in reccursion 3

class Solution {
  public:
    unordered_map<int,int>memo;
    int helper(vector<int>&height, int n, int i){
        if(i >= n-1){
            if(i==n-1){
                return 0;
            }
            return INT_MAX;
        }
        if(!memo[i]){
        int one = INT_MAX, two = INT_MAX;
            if(i < n-1 ) one = abs(height[i]-height[i+1]) + helper(height,n,i+1);
            if(i < n-2) two = abs(height[i]-height[i+2]) + helper(height,n,i+2);
            memo[i] = min(one,two);
        }
        return memo[i];
    }
    int minimumEnergy(vector<int>& height, int n) {
        return helper(height, n, 0);
    }
};

// Tabulation (bottom-up)
class Solution {
  public:    
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n,0);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            int one = INT_MAX, two = INT_MAX;
            one = abs(height[i]-height[i+1]) + dp[i+1];
            if(i < n-2) two = abs(height[i]-height[i+2]) + dp[i+2];
            dp[i] = min(one,two);
        }
        return dp[0];
    }
};

// Space optimization
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int prev = 0, secondPrev = 0;
        prev = 0;
        for(int i = n-2; i >= 0; i--){
            int one = INT_MAX, two = INT_MAX;
            one = abs(height[i]-height[i+1]) + prev;
            if(i < n-2) two = abs(height[i]-height[i+2]) + secondPrev;
            secondPrev = prev;
            prev = min(one,two);
        }
        return prev;
    }
};

// Another way DP solutions if above is not understood
// https://takeuforward.org/data-structure/dynamic-programming-frog-jump-dp-3/


int main(){

    return 0;
}