#include <bits/stdc++.h>
using namespace std;

// just taking two pointers and trying to find where the newInterval fits in.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        vector<int>newInsert;
        int n = intervals.size();

        int i = 0, j = 0, start = newInterval[0], end = newInterval[1];

        // Finding position for i where our start belong
        while(i < n && intervals[i][1]<start) i++; // while intervalEnd > start just i++;

        // but what if i reach n means our start does'nt belong anywhere but at the last, so we have to create newInterval and push it
        if(i == n){ // Condition to check insert new at last
            newInsert = {start,end};
            intervals.push_back(newInsert);
            return intervals;
        }

        // Finding position for j where our end belong
        while(j < n && intervals[j][0]<=end) j++; // while intervalStart >= end j++
        if(j==0) j = 0;
        else j--;
        
        // if i and j are still zero and intervalsStart > end means we need to insert it before this element
        if(i == j && i == 0 && end < intervals[j][0]){ // Condition to check insert new at first position
            newInsert = {start,end};
            intervals.insert(intervals.begin(),newInsert);
            return intervals;
        }
        // if j<i means that current i should come before, and means current i belongs to 
        else if(i > j){ // Condition to check insert new entry in middle
            newInsert = {start,end};
            intervals.insert(intervals.begin()+i,newInsert);
            return intervals;
        }
        newInsert = {min(start,intervals[i][0]),max(end,intervals[j][1])};
        for(int k = 0; k < n; k++){
            if(k == i) ans.push_back(newInsert);
            if(k>=i && k <=j) continue;

            ans.push_back(intervals[k]);
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        vector<int>newInsert;
        int n = intervals.size();

        int i = 0, j = 0, start = newInterval[0], end = newInterval[1];

        // Finding position for i where our start belong
        while(i < n && intervals[i][1]<start) i++; // while intervalEnd > start just i++;

        // but what if i reach n means our start does'nt belong anywhere but at the last, so we have to create newInterval and push it
        if(i == n){ // Condition to check insert new at last
            newInsert = {start,end};
            intervals.push_back(newInsert);
            return intervals;
        }

        // Finding position for j where our end belong
        while(j < n && intervals[j][0]<=end) j++; // while intervalStart >= end j++
        if(j==0) j = 0;
        else j--;
        
        // if i and j are still zero and intervalsStart > end means we need to insert it before this element or if j<i means that current i should come before, and means current i belongs here.
        if(i == j && i == 0 && end < intervals[j][0] || j < i){ // Condition to check insert new at first position or in middle
            newInsert = {start,end};
            intervals.insert(intervals.begin()+i,newInsert);
            return intervals;
        }
        newInsert = {min(start,intervals[i][0]),max(end,intervals[j][1])};
        for(int k = 0; k < n; k++){
            if(k == i) ans.push_back(newInsert);
            if(k>=i && k <=j) continue;

            ans.push_back(intervals[k]);
        }
        return ans;
    }
};

int main(){

    return 0;
}