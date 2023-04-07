#include <bits/stdc++.h>
using namespace std;

// Sort according to start time and then find the valid combinations

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static cp(pair<int,int>a, pair<int,int>b){
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        for(int i = 0 ; i < n; i++){
            pair<int,int>p;
            p.first = start[i];
            p.second = end[i];
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(),cp);
        
        int ans = 0;
        int i = 0, limit = 0;
        while(i < n){
            int limit = v[i].second;
            ans++;
            while( i<n && v[i].first <= limit ) i++;
        }
        return ans;
    }
};

int main(){

    return 0;
}