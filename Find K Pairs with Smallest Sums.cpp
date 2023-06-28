#include <bits/stdc++.h>
using namespace std;

// Using priority queue. Trying every single pair.
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                int sum = nums1[i] + nums2[j];
                pq.push({sum,{nums1[i],nums2[j]}});
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }

        vector<vector<int>>ans;

        while(!pq.empty()){
            auto top = pq.top();
            ans.push_back({top.second.first,top.second.second});
            pq.pop();
        }
        return ans;
    }
};

// Optimized approach taking benifit of information that array is ascending.
// The first element is always the first index of first array and of second array. After that possibility is first and second or second and first of respective arrays.
// We are first putting all elements of first with first of second ans in while loop I am poping and pushing in the ans vector and pushing the next possible value which is the first's value and the element in second array at index ind + 1.
// https://www.youtube.com/watch?v=iY6-u0yt-Is
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; // sum, firstElement and index of second element.
        for(int i = 0; i < nums1.size() && i < k; i++){
            int sum = nums1[i] + nums2[0];
            pq.push({sum,{nums1[i],0}});
        }
        vector<vector<int>>ans;
        while(k>0 && !pq.empty()){
            auto top = pq.top();
            int first = top.second.first;
            int ind = top.second.second;
            pq.pop();
            ans.push_back({first,nums2[ind]});
            k--;
            if(ind == nums2.size()-1) continue;
            int sum = first + nums2[ind+1];
            pq.push({sum,{first,ind+1}});
        }
        return ans;
    }
};

int main(){

    return 0;
}