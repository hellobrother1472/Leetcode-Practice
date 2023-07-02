#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> vis;

    bool helper(vector<int>& nums, int i, int n, int k, int curr_sum, int target) {
        // Base case
        if (k == 1)
            return true;
        if (i == n)
            return false;

        // We found one subset with sum == target, find other k - 1 subsets with sum == target
        if (curr_sum == target)
            return helper(nums, 0, n, k - 1, 0, target);

        for (int j = i; j < n; j++) {
            // If the current element is not taken and curr_sum + nums[j] is <= target, then take it and mark it visited
            if (!vis[j] && curr_sum + nums[j] <= target) {
                vis[j] = true;
                curr_sum += nums[j];

                if (helper(nums, j + 1, n, k, curr_sum, target))
                    return true;

                // Backtrack
                vis[j] = false;
                curr_sum -= nums[j];
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        // Find the sum of the nums array
        for (auto x : nums)
            sum += x;

        // If the sum is odd, it cannot be divided into equal subsets
        if (sum % k)
            return false;

        // Calculate the target sum for each subset
        sum /= k;

        // Initialize the visited array
        vis.assign(n, false);

        return helper(nums, 0, n, k, 0, sum);
    }
};


int main(){

    return 0;
}