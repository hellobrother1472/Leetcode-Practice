#include <bits/stdc++.h>
using namespace std;

// As we have two options one is to take the element at particular index or to not take the element at a particular index and move forward. Using this the reccursion is created.

class Solution
{
public:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        // Exclude
        solve(nums, output, index + 1, ans);

        // Include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index + 1, ans);
    }
    
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void helper(vector<int>nums,int i){
        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        helper(nums,i+1);
        temp.pop_back();
        helper(nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums,0);
        return ans;
    }
};

int main(){

    return 0;
}