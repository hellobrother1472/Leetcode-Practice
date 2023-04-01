#include <bits/stdc++.h>
using namespace std;

// idea is to subtract every number in array with x so that we can have respective differece and from that diffrence we have to find smallest k elements, which means they are closest
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // make max heap
        priority_queue<pair<int,int>> pq;  // automatically sort on pair.first

        for(int i = 0 ; i < arr.size(); i++){
            pair<int,int>p;
            p.first = abs(arr[i] - x);
            p.second = arr[i];
            pq.push(p);
            if(pq.size() > k) pq.pop();
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// Using two pointer
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int l = 0;
        int r = arr.size()-1;
        while(r-l+1>k){
            if(abs(arr[l]-x)<=abs(arr[r]-x)) r--;
            else l++;
        }
        for(int i = l;i<=r;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

int main(){

    return 0;
}