#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

// I perform the rotation using deque.
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++)
        {
            dq.push_back(nums[i]);
        }
        for (int i = 0; i < k; i++)
        {
            int ele = dq.back();
            dq.pop_back();
            dq.push_front(ele);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        nums = ans;
    }
};

// Reversal algorithm
// Step 1: Reverse the last k elements of the array
// Step 2: Reverse the first n-k elements of the array.
// Step 3: Reverse the whole array.

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        return;
    }
};

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < nums.size(); i++)
        {
            ans[(i + k) % n] = nums[i];
        }
        nums = ans;
    }
};

int main()
{

    return 0;
}