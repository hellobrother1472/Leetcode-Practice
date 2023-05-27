#include <bits/stdc++.h>
using namespace std;

// Reccursive DP solution. https://www.youtube.com/watch?v=zKi4LzjK27k
class Solution {
private:
    double helper(int n, int k, int maxPts,int score,unordered_map<double,double>&dp){
        if(score >= k){
            if(score <= n) return 1;
            else return 0;
        }
        if(dp[score]) return dp[score];
        double prob = 0;
        for(int i = 1; i <= maxPts ; i++){
            prob += helper(n,k,maxPts,score+i,dp);
        }
        prob = (double)prob/maxPts;
        return dp[score] = prob;
    }
public:
    double new21Game(int n, int k, int maxPts) {
        unordered_map<double,double>dp;
        return helper(n,k,maxPts,0,dp);
    }
};

// Sliding window solution
class Solution {
public:
    double new21Game(int n, int k, int maxPts)
    {
        vector<double> dp(n+1,0);
        double window_sum = 0;
        
        if(k == 0 ||  n >= k + maxPts) return 1.0;
        
        for(int i = k; i<=n; i++)
        {
            dp[i] = 1.0;
            window_sum++;
        }

        for(int i = k-1; i>= 0; i--)
        {
            dp[i] = (double) window_sum/maxPts;
            double del = 0;
            if(i + maxPts <= n) del = dp[i + maxPts];
            window_sum += dp[i] - del;
        }
        

        return dp[0];
    }
};

// Some changes only.
class Solution {
public:
    double new21Game(int n, int k, int maxPts)
    {
        unordered_map<double,double> dp;
        double window_sum = 0;
        
        if(k == 0 ||  n >= k + maxPts)
        {
            return 1.0;
        }

        for(int i = k; i<=max(n,maxPts); i++)
        {
            if(i <= n){
                dp[i] = 1.0;
                window_sum++;
            }            
        }

        for(int i = k-1; i>= 0; i--)
        {
            dp[i] = (double) window_sum/maxPts;
            double del = 0;
            if(i + maxPts <= n)
            {
                del = dp[i + maxPts];
            }
            window_sum += dp[i] - del;
        }
        

        return dp[0];
    }
};

int main(){

    return 0;
}