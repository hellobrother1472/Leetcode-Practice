#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(vector<int>& arr1, vector<int>& arr2,map<pair<int,int>,int>&dp, int prev,int i){
        if(i == arr1.size()) return 0;
        if(dp.find({i,prev}) != dp.end()) return dp[{i,prev}];
        int ans = INT_MAX/2;
        int upperBound = upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin(); // Finding upperbound
        // Not Replace
        if(arr1[i] > prev) ans = min(ans,helper(arr1,arr2,dp,arr1[i],i+1));
        // Replace
        if(upperBound < arr2.size()) ans = min(ans,helper(arr1,arr2,dp,arr2[upperBound],i+1)+1);
        return dp[{i,prev}] = ans;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        map<pair<int,int>,int>dp;
        sort(arr2.begin(),arr2.end());
        int ans = helper(arr1,arr2,dp,INT_MIN,0);
        return (ans == INT_MAX/2) ? -1 : ans;
    }
};

int main(){

    return 0;
}