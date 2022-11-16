#include <iostream>
#include <vector>

using namespace std;

// The algo is made by analusis of problem with diffrent test cases and edge cases. The intution is to move the start and end such that it fits in the pattern of searching.
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[start] == target)
            {
                return start;
            }
            if (nums[end] == target)
            {
                return end;
            }
            if (target > nums[start] && target < nums[end])
            {
                if (nums[mid] < target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else if (target > nums[start] && target > nums[end])
            {
                if (target > nums[mid] && nums[mid] > nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else if (target < nums[start] && target < nums[end])
            {
                if (target < nums[mid] && nums[mid] < nums[end])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                return -1;
            }
        }

        return -1;
    }
};

// Short form of above logic.
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;

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
        return -1;
    }
};

int main()
{

    return 0;
}