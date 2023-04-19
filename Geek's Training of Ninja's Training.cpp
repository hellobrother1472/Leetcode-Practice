#include <bits/stdc++.h>
using namespace std;

// Base case is when day reaches n-1, last is the index of the exercise we do last time, it is used here so that we can avoid that and get answer remaining index as same excersises on consecutive days are not allowed.
// When reached the base case we are finding the maximum value whose index is not equal to last
// Otherwise we are trying all possible cases it is points[day][i] + helper(for day+1) means if we take current index so value will be current index + max of remaining matrix if current acts as last for further.
// At start we put last = 3 because at starting we can take any of all.

// Using DP - curr + max(further)
class Solution {
  private:
    int helper(vector<vector<int>>& points,vector<vector<int>>&dp, int n, int day, int last){
        if(day == n-1){
            int maxi = INT_MIN;
            for(int i = 0; i < 3; i++){
                if(i != last) maxi = max(points[day][i],maxi);
            }
            return maxi;
        }
        int maxi = 0;
        for(int i = 0; i < 3; i++){
            if(i != last){
                if(!dp[day][i]){
                    dp[day][i] = points[day][i] + helper(points,dp,n,day+1,i);
                }
                maxi = max(dp[day][i],maxi);
            }
        }
        return maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(n,0));
        return helper(points,dp,n,0,3);
    }
};

// DP 2
class Solution {
  private:
    int helper(vector<vector<int>>& points,vector<vector<int>>&dp, int n, int day, int last){
        if(day == n-1){
            int maxi = INT_MIN;
            for(int i = 0; i < 3; i++){
                if(i != last) maxi = max(points[day][i],maxi);
            }
            return maxi;
        }
        int maxi = 0;
        if(dp[day][last]) return dp[day][last];
        for(int i = 0; i < 3; i++){
            if(i != last){
                int point = points[day][i] + helper(points,dp,n,day+1,i);
                maxi = max(maxi,point);
            }
        }
        return dp[day][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(n,0));
        return helper(points,dp,n,0,3);
    }
};

// DP 3 - If we want to start from last
class Solution {
  private:
    int helper(vector<vector<int>>& points,vector<vector<int>>&dp, int n, int day, int last){
        if(day == 0){
            int maxi = 0;
            for(int i = 0; i < 3; i++){
                if(i != last) maxi = max(points[day][i],maxi);
            }
            return maxi;
        }
        int maxi = 0;
        if(dp[day][last]) return dp[day][last];
        for(int i = 0; i < 3; i++){
            if(i != last){
                int point = points[day][i] + helper(points,dp,n,day-1,i);
                maxi = max(maxi,point);
            }
        }
        return dp[day][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4,0));
        return helper(points,dp,n,n-1,3);
    }
};


// Tabulation form
// First declare the ans which will take the max values for the day until now and at last we got the max value starting as we are starting from last and reach to the end
// First for (n-1)th day which is the base case I am finding the max value for the respective last value.
// Now for (i)th (starting from n-2 till 0) day if last value is last, then what will be the max for this day and last value, it is calculated and stored in dp, and ans is updated along with it.
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(n,0));
        int ans = INT_MIN;
        for(int last = 0; last < 3; last++){ // For different last value
            int maxi = INT_MIN;
            for(int i = 0; i < 3; i++){  // Iterate and find the max and store it
                if(i != last) maxi = max(points[n-1][i],maxi);
            }
            dp[n-1][last] = maxi;
            ans = max(ans,maxi);
        }
        for(int day = n-2; day >= 0; day--){ // loop for days
            for(int last = 0; last < 3; last++){ // For different last values
                int maxi = INT_MIN;
                for(int i = 0; i < 3; i++){ // Iterate and find the max of remainig and store it.
                    if(i != last) maxi = max(points[day][i] + dp[day+1][i],maxi); // point is current point + point of day+1 if current index is last.
                }
                dp[day][last] = maxi; // storing the max
                ans = max(ans,maxi);
            }            
        }
        return ans;
    }
};

// Tabulation 2
int maximumPoints(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }

  }

  return dp[n - 1][3];
}

// Space optimization
// In above approach the observation is that I only need two rows one for storing the values of day+1 and another for storing the value of current computation or current day, after that just before the day changes just move row 1 which is of current day to row 0 which is of day+1 because for next day it is the day+1 value.
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>memo(2,vector<int>(3,0));
        int ans = INT_MIN;
        for(int last = 0; last < 3; last++){
            int maxi = INT_MIN;
            for(int i = 0; i < 3; i++){
                if(i != last) maxi = max(points[n-1][i],maxi);
            }
            memo[0][last] = maxi;
            ans = max(ans,maxi);
        }
        for(int day = n-2; day >= 0; day--){
            for(int last = 0; last < 3; last++){
                int maxi = INT_MIN;
                for(int i = 0; i < 3; i++){
                    if(i != last) maxi = max(points[day][i] + memo[0][i],maxi);
                }
                memo[1][last] = maxi;
                ans = max(ans,maxi);
            }
            for(int k= 0; k < 2 ; k++){
                for(int l = 0 ;l < 3 ; l++){
                    if(k == 0) memo[k][l] = memo[1][l];
                    else memo[k][l] = 0;
                }
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}