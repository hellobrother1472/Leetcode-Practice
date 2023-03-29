#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isMaxHeap(int a[], int n)
    {
        // Your code goes here
        for(int i = 0 ; i < n; i++){
            int parent = a[i];
            int left = 0;
            int right = 0;
            if(2*i+1 < n) left = a[2*i+1];
            if(2*i+2 < n) right = a[2*i+2];
            if((left && parent < left) ||(right && parent < right)) return false;
        }
        return true;
    }
};

int main(){

    return 0;
}