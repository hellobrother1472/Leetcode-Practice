#include <bits/stdc++.h>
using namespace std;

// Consider if we have cost of all as one, then we will try to make all of them equal to the middle element of sorted nums means median. But as now as all weights are not equal to 1, then now let consider the cost as it's frequency and now let's find out the median elements and then make everyone equal to that.
// https://www.youtube.com/watch?v=8ERS_4tSx2U
class Solution {
private:
    long long calculateCost(vector<int>& nums, vector<int>& cost, int n, int val){
        long long ans = 0;
        for(int i = 0 ; i < n; i++){
            ans += (long long )abs(nums[i]-val) * cost[i];
        } 
        return ans;
    }
    
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> newNums;
        long long totalItems = 0;
        for(int i = 0; i < n; i++){
            totalItems += cost[i]; 
            newNums.push_back({nums[i],cost[i]});
        }
        sort(newNums.begin(),newNums.end());
        long long medianIndex = (totalItems+1)/2;
        long long miniCost = LLONG_MAX;
        int i = 0,median = 0;
        while(i < n){
            medianIndex -= newNums[i].second;
            if(medianIndex <= 0) {
                median = newNums[i].first;
                break;
            }
            i++;
        }
        return calculateCost(nums,cost,n,median);
    }
};

// https://www.youtube.com/watch?v=Pa8h6gV9UT8

class Solution {
public:
    long minCost(vector<int>& nums, vector<int>& cost) {
        const int ELEMENT_COUNT = 1000002;
        vector<long long> costOfNos(ELEMENT_COUNT, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            costOfNos[nums[i]] += cost[i];
        }
        
        vector<long long> prefSum(ELEMENT_COUNT, 0);
        vector<long long> suffSum(ELEMENT_COUNT, 0);
        long long ans = LLONG_MAX;
        long long sum = 0;
        
        for (int i = 1; i < ELEMENT_COUNT; i++) {
            prefSum[i] = prefSum[i - 1] + sum;
            sum += costOfNos[i];
        }
        
        sum = 0;
        
        for (int i = ELEMENT_COUNT - 2; i >= 0; i--) {
            suffSum[i] = suffSum[i + 1] + sum;
            sum += costOfNos[i];
            ans = min(ans, suffSum[i] + prefSum[i]);
        }
        
        return ans;
    }
};


int main(){

    return 0;
}