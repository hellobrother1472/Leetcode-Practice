#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int start = 0, end = nums.size() - 1;
        if (nums.size() == 0)
        {
            return ans;
        }
        // Finding the element
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                start = mid;
                break;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        // if found the we are setting pointer to the start and the end of the occurences and then pushing it in vector.
        if (start < nums.size() && nums[start] == target)
        {
            end = start;
            while (start >= 0 && nums[start] == target)
            {
                start--;
            }
            ans[0] = start + 1;
            while (end < nums.size() && nums[end] == target)
            {
                end++;
            }
            ans[1] = end - 1;
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int start = 0, end = nums.size() - 1;
        if (nums.size() == 0)
        {
            return ans;
        }
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                int temp = mid;

                while (mid > 0 && nums[mid - 1] == target)
                {
                    mid--;
                }
                ans[0] = mid;
                while (temp < nums.size()-1 && nums[temp + 1] == target)
                {
                    temp++;
                }
                ans[1] = temp;
                break;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}