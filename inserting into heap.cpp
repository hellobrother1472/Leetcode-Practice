#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // This function basically builds max heap
    void convertMinToMaxHeap(vector<int> &arr, int n){
        int heapSize = 0;
        vector<int>maxHeap(n);
        
        for (int i = 0; i < n; i++){
            heapSize++;
            int j = heapSize - 1;
            maxHeap[j] = arr[i];
            int parent = (j-1)/2;
            while(parent >= 0 && maxHeap[parent] < maxHeap[j]){
                cout <<maxHeap[parent] << " " << maxHeap[j] << endl;
                swap(maxHeap[parent], maxHeap[j]);
                j = parent;
                parent = (j-1)/2;
            }
        }
        
        for(int i = 0; i < heapSize; i++){
            arr[i] = maxHeap[i];
        }
    }
};


int main(){
    

    return 0;
}