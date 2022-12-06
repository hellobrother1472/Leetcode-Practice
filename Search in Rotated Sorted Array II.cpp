#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[low] == target)
                return true;

            if (nums[high] == target)
                return true;

            if (nums[mid] >= nums[low])
            {
                if(nums[low] == nums[high]){
                    low++;
                    high--;
                }
                else if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(nums[low] == nums[high]){
                    low++;
                    high--;
                }
                else if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return true;
            if(nums[low] == nums[high]){
                if(nums[low] == target){
                    return true;
                }
                low++;
                high--;  
                continue;              
            }
            if (nums[mid] >= nums[low])
            {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

int main(){
    

    return 0;
}