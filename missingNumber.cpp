#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Brut force approach is to use maps

// Using sorting and iterating
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans;
        if (nums[0] != 0)
        {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 < nums.size())
            {
                if (nums[i] + 1 == nums[i + 1])
                {
                    continue;
                }
                else
                {
                    ans = nums[i] + 1;
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        return ((n * (n + 1)) / 2) - accumulate(nums.begin(), nums.end(), 0);
    }
};

int main()
{

    return 0;
}