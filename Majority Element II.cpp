#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums;
        }
        sort(nums.begin(), nums.end());
        int count = 0;
        int currNum = nums[0];
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == currNum)
            {
                count++;
            }
            else
            {
                count = 1;
                currNum = nums[i];
            }
            if (count > (nums.size() / 3) && (ans.size() == 0 || nums[i] != ans[ans.size() - 1]))
            { // This is to avoid repetition
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}