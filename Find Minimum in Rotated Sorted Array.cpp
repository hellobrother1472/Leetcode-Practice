#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || nums[0] < nums[n - 1]) // In these cases answers are obvious
            return nums[0];

        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mid == 0 && nums[mid] > nums[mid + 1]) // Condition if mid == 0, we check element in front of it.
                return nums[mid + 1];

            if (mid > 0 && nums[mid] < nums[mid - 1]) // In this case we got the pivot point and minimum
                return nums[mid];

            if (mid > 0 && nums[mid - 1] < nums[mid] && nums[high] > nums[mid]) // if mid>0 then we only have to compare prev and high
                high = mid - 1;
            else if (mid > 0 && nums[mid - 1] < nums[mid] && nums[high] < nums[mid])
                low = mid + 1;
        }
        return 1;
    }
};

int main()
{

    return 0;
}