#include <bits/stdc++.h>
using namespace std;
// Game Theory

// Using reccursion
// I want to maximize the score of player one.
// In reccursive call if it's player one's turn it means he will choose max and if not than other player will choose max.
// If i is greater than j, this means there are no elements left in the subarray, so the score contribution is 0, and the function returns 0.
// If it is Player 1's turn (turn=true), then they have two choices: either pick the number at index i or pick the number at index j. Player 1 would want to maximize their score, so the function calculates the score for both choices and returns the maximum of the two.
// If it is Player 2's turn (turn=false), then they would want to minimize Player 1's score, so the function calculates the score for both choices and returns the minimum of the two.
// So if you make the decision tree then you will realize that when the result is positive it means player one's choices create score greater than the negetive (player two's score) which means player one can win
// But if not then it means player 1 will not win

class Solution {
private:
    int maxPOne(vector<int>& nums, int i, int j, bool turn){
        if(i > j) return 0;
        if(turn){
            int choiceOne = nums[i] + maxPOne(nums,i+1,j,!turn);
            int choiceTwo = nums[j] + maxPOne(nums,i, j-1,!turn);
            return max(choiceOne,choiceTwo);
        }
        int choiceOne = -nums[i] + maxPOne(nums,i+1,j,!turn);
        int choiceTwo = -nums[j] + maxPOne(nums,i, j-1,!turn);
        return min(choiceOne,choiceTwo);        
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return maxPOne(nums,0,n-1,true) >= 0;
    }
};

// Applying memoization
class Solution {
private:
    int maxPOne(vector<int>& nums,vector<vector<vector<int>>>&dp, int i, int j, bool turn){
        if(i > j) return 0;
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        if(turn){
            int choiceOne = nums[i] + maxPOne(nums,dp,i+1,j,!turn);
            int choiceTwo = nums[j] + maxPOne(nums,dp,i, j-1,!turn);
            return dp[i][j][turn] = max(choiceOne,choiceTwo);
        }
        int choiceOne = -nums[i] + maxPOne(nums,dp,i+1,j,!turn);
        int choiceTwo = -nums[j] + maxPOne(nums,dp,i, j-1,!turn);
        return dp[i][j][turn] = min(choiceOne,choiceTwo);        
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return maxPOne(nums,dp,0,n-1,true) >= 0;
    }
};

int main(){

    return 0;
}