#include <bits/stdc++.h>

using namespace std;

// Algo is to take one constant and apply two sum on the rest.
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low, high;
        for (int i = 0; i < n - 2; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            low = i + 1;
            high = n - 1;
            int target = 0 - nums[i];
            while (low < high)
            {

                if ((nums[low] + nums[high]) < target)
                {
                    low++;
                }
                else if ((nums[low] + nums[high]) > target)
                {
                    high--;
                }
                else
                {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);
                    ans.push_back(v);
                    while (low < high && nums[low] == nums[low + 1])
                    {
                        low++;
                    }
                    while (low < high && nums[high] == nums[high - 1])
                    {
                        high--;
                    }
                    low++;
                    high--;
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}