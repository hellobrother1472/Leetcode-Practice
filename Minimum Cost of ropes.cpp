#include <bits/stdc++.h>
using namespace std;

// As we want minimum cost so we have to add minimum 2 elements in the array first in every iteration.
// For that min heap is used first top two elements is added and then the addition is added to answer and again added pushed to heap, for further calculation

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // making a minHeap
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for(long long i = 0 ; i < n; i++){
            minHeap.push(arr[i]);
        }
        
        long long ans = 0;
        while(!minHeap.empty()){
            long long a = minHeap.top();
            minHeap.pop();
            long long b = 0;
            if(!minHeap.empty()) {
                b = minHeap.top();
                minHeap.pop();
            }
            else{
                return ans; 
            }
            ans += a+b;
            minHeap.push(a+b);
        }
        return ans;
    }
};

int main(){

    return 0;
}