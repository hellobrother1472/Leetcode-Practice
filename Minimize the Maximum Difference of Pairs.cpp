#include <bits/stdc++.h>
using namespace std;

// DP solution
class Solution
{
public:
    int solve(int i, vector<int> &nums, int p, vector<vector<int>> &dp)
    {
        if (p == 0) return 0;
        if (i >= nums.size() - 1) return 1e9;
        if (dp[i][p] != -1) return dp[i][p];
        return dp[i][p] = min(solve(i + 1, nums, p, dp), max(abs(nums[i] - nums[i + 1]), solve(i + 2, nums, p - 1, dp)));
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(), vector<int>(p + 1, -1));
        return solve(0, nums, p, dp);
    }
};

// Binary search + Greedy Solution
// First sort the array
// consider finding all pairs with diff <= (0 to maxDiff). So we can do it linearly but itto will give tle
// So we will perform this using binary search with left = 0, right = maxDiff;
// If total pairs exists >= p which means we have to try for less value to right = mid;
// if total pairs exist < p which means left = mid-1;

class Solution {
public:
    // Find the number of valid pairs by greedy approach
    int countValidPairs(vector<int>& nums, int threshold) {
        int index = 0, count = 0;
        while (index < nums.size() - 1) {
            // If a valid pair is found, skip both numbers.
            if (nums[index + 1] - nums[index] <= threshold) {
                count++;
                index++;
            }
            index++;
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If there are enough pairs, look for a smaller threshold.
            // Otherwise, look for a larger threshold.
            if (countValidPairs(nums, mid) >= p)  right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main()
{

    return 0;
}