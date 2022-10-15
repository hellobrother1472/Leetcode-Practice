#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// First solution is by using any sorting algorithm
// Second solution is by using counting sorting. Which is counting the elements and putting then in array afterwards.

// Solved using dutch national flag algorithm.(Solved in one go with constant auxilary space)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while (mid <= high)
        {
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;                
            }
            else if(nums[mid]== 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};

int main(){
    

    return 0;
}