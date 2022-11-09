#include <bits/stdc++.h>

using namespace std;

// O(nlog(n)+n)
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        vector<int> sample = nums;
        int ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[nums.size() - 1] == sample[i])
                ans = i;
        }
        return ans;
    }
};

// O(n) solution
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }
        if (n == 2)
        {
            if (nums[0] > nums[1])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        int ans;
        int start = 0, middle = 1, last = 2;
        if (nums[0] > nums[1])
        {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }
        while (last < n)
        {
            if (nums[middle] > nums[start] && nums[middle] > nums[last])
            {
                ans = middle;
            }
            start++;
            middle++;
            last++;
        }

        return ans;
    }
};

// O(n)
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        int max = INT_MIN;
        int ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                ans = i;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {

        if (nums.size() == 1)
            return 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (i + 1 < nums.size() && nums[i] > nums[i + 1] && nums[i] > nums[i - 1])
                return i;
        }

        if (nums[nums.size() - 1] > nums[nums.size() - 2])
            return nums.size() - 1;
        return 0;
    }
};

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1;

        while (start < end)
        {
            int mid = (start + end) / 2;

            if (mid == 0)
                return nums[0] >= nums[1] ? nums[0] : nums[1];

            if (mid == n - 1)
                return nums[n - 1] >= nums[n - 2] ? nums[n - 1] : nums[n - 2];

            // Cheking whether peak ele is in mid position
            if (nums[mid] >= nums[mid - 1] && nums[mid] >= nums[mid + 1])
                return nums[mid];

            // If left ele is greater then ignore 2nd half of the elements
            if (nums[mid] < nums[mid - 1])
                end = mid - 1;

            // Else ignore first half of the elements
            else
                start = mid + 1;
        }

        return nums[start];
    }
};

int main()
{

    return 0;
}