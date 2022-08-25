#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rfunc(vector<int> &arr, vector<vector<int>> &ans, int i, vector<int> &ds)
    {
        if (i >= arr.size())
        {
            if (count(ans.begin(), ans.end(), ds)) // If the array is already present in ans then simply return
            {
                return;
            }
            else
            {
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(arr[i]);
        rfunc(arr, ans, i + 1, ds);
        ds.pop_back();
        rfunc(arr, ans, i + 1, ds);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        rfunc(nums, ans, 0, ds);
    }
};

class Solution2
{
public:
    void rfunc(vector<int> &arr, vector<vector<int>> &ans, int i, vector<int> &ds)
    {
        // if (i == arr.size())  // This is the mistake
        // {
        //     ans.push_back(ds);
        //     return;
        // }
        ans.push_back(ds);

        for (int j = i; j < arr.size(); j++)
        {
            if (j != i && arr[j] == arr[j - 1])
            {
                continue;
            }
            ds.push_back(arr[j]);
            rfunc(arr, ans, j + 1, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        rfunc(nums, ans, 0, ds);
        return ans;
    }
};

class Solution3
{
public:
    void recur(vector<vector<int>> &ans, vector<int> &arr, vector<int> &helper, int idx)
    {
        ans.push_back(helper);

        for (int i = idx; i < arr.size(); i++)
        {
            if (i != idx && arr[i] == arr[i - 1])
                continue;
            helper.push_back(arr[i]);
            recur(ans, arr, helper, i + 1);
            helper.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &arr)
    {
        vector<vector<int>> ans;
        vector<int> helper;
        sort(arr.begin(), arr.end());
        recur(ans, arr, helper, 0);
        return ans;
    }
};

int main()
{

    return 0;
}