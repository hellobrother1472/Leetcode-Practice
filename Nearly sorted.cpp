#include <bits/stdc++.h>
using namespace std;

// As according to question each element is at most k away from its target position, so making a min heap of length k and as the heap reaches a length k it means we got the element's correct place.

class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        priority_queue<int ,vector<int>, greater<int> > q;
        vector<int>ans;
        for(int i = 0 ; i < n; i++){
            q.push(arr[i]);
            if(q.size() == k+1){
                ans.push_back(q.top());
                q.pop();
            }
            
        }
        while(!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};

int main(){

    return 0;
}