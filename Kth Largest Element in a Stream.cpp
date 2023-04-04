#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int> > minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0 ; i < nums.size(); i++){
            minHeap.push(nums[i]);
            if(minHeap.size() > k) minHeap.pop();
        }
    }    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};

int main(){

    return 0;
}