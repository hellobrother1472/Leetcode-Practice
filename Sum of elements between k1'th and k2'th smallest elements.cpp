#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long k1, long long k2)
    {
        // Your code goes here
        priority_queue<long long> maxHeap;
        
        for(long long i = 0 ; i < N; i++){
            maxHeap.push(A[i]);
            if(maxHeap.size()>=k2) maxHeap.pop();
        }
        long long ans = 0;
        while(maxHeap.size() != k1){
            ans += maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};

int main(){

    return 0;
}