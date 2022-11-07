#include <iostream>
#include <vector>

using namespace std;

// Find the floor and plus one you get the answer.
class Solution{
    public:
    int searchInsertK(vector<int>arr, int n, int k)
    {
        int ans = -1;
        int start = 0, end = n-1;
        while(start <= end){
            int mid = start + (end -start)/2;
            if(arr[mid] == k){
                return mid;
            } 
            else if(arr[mid] > k){
                end = mid-1;
            }
            else{
                start = mid+1;
                ans = mid;
            }
        }
        return ans+1;
    }
};

int main(){
    

    return 0;
}