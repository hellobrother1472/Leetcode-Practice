#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < nums.size() - 1)
            {
                if (nums[i] == nums[i + 1])
                {
                    i++;
                    continue;
                }
                else
                {
                    ans = nums[i];
                    return ans;
                }
            }
            else
            {
                ans = nums[i];
                return ans;
            }
        }
        return ans;
    }
};

// Using the same approach as of solution 1
class Solution2
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums[i] != nums[i - 1])
                return nums[i - 1];
        }
        return nums[nums.size() - 1];
    }
};

int main()
{

    return 0;
}