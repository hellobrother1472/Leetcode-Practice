#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public: 
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;

        if (nums.size() == 0)
        {
            return ans;
        }
        if (nums.size() == 1)
        {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int start = nums[0], end;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((i + 1) < nums.size() && abs(abs(nums[i + 1]) - abs(nums[i])) == 1)
            {
                continue;
            }
            else
            {
                end = nums[i];
                if (end - start >= 1)
                {
                    ans.push_back(to_string(start) + "->" + to_string(end));
                }
                else
                {
                    ans.push_back(to_string(end));
                }

                if (i + 1 < nums.size())
                {
                    start = nums[i + 1];
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