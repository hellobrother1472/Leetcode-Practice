#include <bits/stdc++.h>
using namespace std;

// Normal sorting can also be used.

// Find unique elements
// Make a minHeap out of them.
// Make a map to store their respective ranks
// Then assign it to elements

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<int,vector<int>,greater<int> > minHeap;
        unordered_map<int,int> frequency;
        for(int i = 0 ; i < N; i++){
            frequency[arr[i]] ++;
        }
        for(auto i = frequency.begin() ; i != frequency.end(); i++){
            minHeap.push(i->first);
        }
        unordered_map<int,int> m;
        int rank = 1;
        while(!minHeap.empty()){
            m[minHeap.top()] = rank;
            minHeap.pop();
            rank++;
        }
        
        vector<int>ans;
        for(int i = 0 ; i < N; i++){
            ans.push_back(m[arr[i]]);
        }
        return ans;

    }

};

int main(){

    return 0;
}