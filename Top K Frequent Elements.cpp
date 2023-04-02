#include <bits/stdc++.h>
using namespace std;

// Using heap 
// First I am storing the frequency in map, then using pair ds I am putting the frequency and number in pair, frequency is made pair.first as heap sort on basis of pair.first.
// That just adding to answer vector the elements on the top of heap (element with max frequency) and then poping.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int,int> mp;
        for(int i= 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto i = mp.begin(); i != mp.end(); i++){
            pair<int,int>p;
            p.first = i->second;
            p.second = i->first;
            minHeap.push(p);
            if(minHeap.size() > k) minHeap.pop();
        }

        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};

int main(){

    return 0;
}