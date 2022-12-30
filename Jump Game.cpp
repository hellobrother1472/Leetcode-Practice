#include <bits/stdc++.h>
using namespace std;

// In this approach I am using reccursion for checking every single possibility at any instance
class Solution
{
public:
    bool ans = false;
    void solve(vector<int> nums, int i, int n)
    {
        if (i + nums[i] >= n - 1 || ans == true)
        {
            ans = true;
            return;
        }
        if (nums[i] == 0)
            return;
        for (int j = 1; j <= nums[i]; j++) // Iterating the range 1 to nums[i] and checking for every num
        {
            solve(nums, i + j, n);
        }
    }
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (nums[0] >= n - 1)
            return true;
        solve(nums, 0, n);
        return ans;
    }
};

// Here I am using the approach in which I am starting from last and checking that if i can reach j from it's position.
// If yes it means j can be reached so j = i and i--, now I am checking if now j can be reached or not. 
// If no then check for i--;
// So after repeating this process at last if the given array is correct then j == 0 other wise it is false. 
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (nums[0] >= n - 1)
            return true;
        int i = n - 2, j = n - 1;
        while (i >= 0 && j >= 0)
        {
            if (i + nums[i] >= j)
            {
                j = i;
                i--;
            }
            else
            {
                i--;
            }
        }
        return j == 0;
    }
};

int main()
{

    return 0;
}