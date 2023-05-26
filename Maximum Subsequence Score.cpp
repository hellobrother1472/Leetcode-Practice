#include <bits/stdc++.h>
using namespace std;

// Checking every possible subsequence.
// Reccursion
class Solution {
    long long helper(vector<int>& nums1, vector<int>& nums2, int k, int i, long long sum, int mini){
        if(i >= nums1.size()){
            if(k == 0){
                return sum*mini;
            }
            return 0;
        }
        int nMini = min(mini,nums2[i]);
        int take = helper(nums1,nums2,k-1,i+1,sum+nums1[i],nMini);
        int notTake = helper(nums1,nums2,k,i+1,sum,mini);
        return max(take,notTake);
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        return helper(nums1,nums2,k,0,0,INT_MAX);
    }
};

// Reccursion 2
class Solution {
    long long helper(vector<int>& nums1, vector<int>& nums2, int k, int i, long long sum, int mini){
        if(k == 0){
            return sum*mini;
        }
        if(i >= nums1.size()){            
            return 0;
        }
        int nMini = min(mini,nums2[i]);
        int take = helper(nums1,nums2,k-1,i+1,sum+nums1[i],nMini);
        int notTake = helper(nums1,nums2,k,i+1,sum,mini);
        return max(take,notTake);
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums1.size(),0));
        return helper(nums1,nums2,k,0,0,INT_MAX);
    }
};


// Using min heap
// https://www.youtube.com/watch?v=bwWk-oRLuxg
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vec;
        //make pair
        for(int i=0;i<nums1.size();i++)
            vec.push_back({nums2[i],nums1[i]});
        //sort on base of nums2 in descending order
        sort(vec.rbegin(),vec.rend());
        
        long long ans = 0;
        long long curr_sum = 0;
        
        //make k-1 element min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k-1;i++){
            curr_sum += vec[i].second;
            pq.push(vec[i].second);
        }
            
        
        // loop in sorted array from k to array size, taking current element as min and 
        // try to maximize sum of 1st array elements
        for(int i=k-1;i<nums1.size();i++){
            //include ith element to subsequence
            curr_sum+=vec[i].second;
            pq.push(vec[i].second);
            ans = max(ans,curr_sum * vec[i].first);
            //remove min element from priority queue
            curr_sum-=pq.top();
            pq.pop();
        }
        return ans;
    }
};

int main(){

    return 0;
}