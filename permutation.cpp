#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rfunc(vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (ds.size() == arr.size()) // If the size of ds is same as the arr then we got a permutation so return
        {
            ans.push_back(ds);
            return;
        }

        for (int j = 0; j < arr.size(); j++)
        {
            if (count(ds.begin(), ds.end(), arr[j])) // if the items is already present then simply skip.
            {
                continue;
            }
            ds.push_back(arr[j]);
            rfunc(arr, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        rfunc(nums, ans, ds);
        return ans;
    }
};

class Solution
{
public:
    void recursion( int idx, vector<vector<int>>& ans , vector<int>& nums)
    {
        if( idx == nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        
        for( int i =idx;i< nums.size();i++)
        {
            swap( nums[idx], nums[i]);
            recursion( idx+1, ans, nums );
            swap( nums[idx], nums[i]);
        }
         
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recursion( 0, ans, nums);
        return ans ;        
    }
};

// Mark the taken element going further and during backtacking remove the marking
class Solution {
private:
    void helper(vector<int>& nums, int n, vector<vector<int>>&ans,vector<int>&temp){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ;i < n; i++){
            if(nums[i] != -11){
                int val = nums[i];
                temp.push_back(nums[i]);
                nums[i] = -11;
                helper(nums,n,ans,temp);
                nums[i] = val;
                temp.pop_back();
            }            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        helper(nums,n,ans,temp);
        return ans;
    }
};



int main()
{

    return 0;
}