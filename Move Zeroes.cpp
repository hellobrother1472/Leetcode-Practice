#include <iostream>
#include <vector>

using namespace std;

// Logic is to add non zeros first and then zeros
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                ans.push_back(nums[i]);
            }
            else
            {
                count++;
            }
        }

        for (int i = 0; i < count; i++)
        {
            ans.push_back(0);
        }
        nums = ans;
    }
};

// Second Approach
// Start traversing from the first occurrence index of Zero
// Tak 2 variables (i,j), i will be at the first occurrence of zero and j is at i+1
//  If element at j index is not zero then swap elements at i,j and increment i,j
// If the element at j index is zero then only increment j.

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[j] == 0 && nums[i] != 0)
            {
                swap(nums[i], nums[j]);
            }
            if (nums[j] != 0)
            {
                j++;
            }
        }
    }
};

int main()
{

    return 0;
}