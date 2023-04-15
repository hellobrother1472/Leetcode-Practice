#include <bits/stdc++.h>
using namespace std;

// I first sort according to starting but then this testcase comes [[1,100],[11,22],[1,11],[2,12]], in this testcase my answer is 3 but the real answer is 2, then I realize that they are asking for minimum number of replacement, 3 is correct but not minimum.
// So if I sort the array w.r.t. it's ending then I will get the largest at end which help me to avoid removing, and if their is any removing then it is of big range element which give minimum answers.
// taking i and j and moving j until thier is the overlapping and counting it, as they can be removed. 
// count starts from -1 because one case is of itself so we don't want it to include itself in count. 

class Solution {
public:
    static bool cmp(vector<int>&v1, vector<int>&v2){
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int ans = 0, n = intervals.size(), i = 0, j = 0;
        while(i < n){
            int count = -1;
            while(j < n && intervals[i][1] > intervals[j][0]){
                j++;
                count++;
            }
            if(count > -1) ans += count;
            i = j;
        }
        return ans;
    }
};

int main(){

    return 0;
}