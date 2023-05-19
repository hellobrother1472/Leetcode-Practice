#include <bits/stdc++.h>
using namespace std;

// The solution has 4 variables which are start->starting for the scale,end-> ending for the scale,i->starting of cuts,j->ending for cuts
// when we cut we have two parts so the cost is current length (end - start) , and helper for left side as we cut on k its end becomes k-1 and i remains same, and helper for right side whose i becomes k+1 and end remains same. In term of size for left size is from start till cuts[k] and for right start is at cuts[k] and end is same.
// Then we find minimum of them and return. 

// Reccursive
class Solution {
private:
    int helper(int start, int end, vector<int>& cuts, int i,int j) {
        if (i > j || start >= end) {
            return 0;
        }
        int mini = INT_MAX;
        for (int k = i; k <=j; k++) {
            int sol = end - start + helper(start, cuts[k], cuts, i,k-1) + helper(cuts[k], end, cuts, k+1,j);
            mini = min(mini, sol);
        }
        return mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        return helper(0, n, cuts, 0,cuts.size()-1);
    }
};

// Reccursive 2 - Replaces size = end - start to cuts[j+1]-cuts[i-1] (Try on copy)

class Solution {
private:
    int helper(vector<int>& cuts, int i,int j) {
        if (i > j) {
            return 0;
        }
        int mini = INT_MAX;
        for (int k = i; k <=j; k++) {
            int sol = cuts[j+1]-cuts[i-1] + helper(cuts, i,k-1) + helper(cuts, k+1,j);
            mini = min(mini, sol);
        }
        return mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        for(int i = 0 ; i < cuts.size(); i++) cout << cuts[i] << " ";
        return helper(cuts, 1,cuts.size()-2);
    }
};

// Memoized Solution
class Solution {
private:
    int helper(vector<vector<int>>&dp,vector<int>& cuts, int i,int j) {
        if (i > j) return 0;
        if(dp[i][j]) return dp[i][j];
        int mini = INT_MAX;
        for (int k = i; k <=j; k++) {
            int sol = cuts[j+1]-cuts[i-1] + helper(dp,cuts, i,k-1) + helper(dp,cuts, k+1,j);
            mini = min(mini, sol);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),0));
        return helper(dp,cuts, 1,cuts.size()-2);
    }
};

// Tabularization
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),0));
        for(int i = cuts.size()-2; i > 0; i--){
            for(int j = i; j < cuts.size()-1; j++){
                if(i <= j){
                    int mini = INT_MAX;
                    for (int k = i; k <=j; k++) {
                        int sol = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                        mini = min(mini, sol);
                    }
                    dp[i][j] = mini;
                }
            }
        }
        return dp[1][cuts.size()-2];
    }
};

int main(){

    return 0;
}