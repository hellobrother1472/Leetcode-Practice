#include <bits/stdc++.h>
using namespace std;

// First sorting w.r.t. starting index so that time is sorted and then, just taking i and j to correct places and making a new interval if required and pushing into answer

class Solution {
public:
    static bool cmp(vector<int>&v1, vector<int>&v2){
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>>ans;
        int i = 0, n = intervals.size();
        while(i < n){
            int start = intervals[i][0];
            int end = intervals[i][1];

            while(i < n-1 && end >= intervals[i+1][0]){
                end = max(end,intervals[i+1][1]);
                start = min(start,intervals[i+1][0]);
                i++;
            }

            vector<int>helper = {start,end};
            ans.push_back(helper);
            i++;
        }
        return ans;
    }
};

int main(){

    return 0;
}