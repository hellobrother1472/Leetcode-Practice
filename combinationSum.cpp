#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rfunc(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {

        // If target becomes zero
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        // If target becomes less than zero or index comes to its end
        if (target < 0 || ind == arr.size())
        {
            return;
        }

        // First we are taking the number on the index and running the function again on the same index.
        ds.push_back(arr[ind]);
        rfunc(ind, target - arr[ind], arr, ans, ds);

        // After that we are not taking the number on the index and running the function on the next index.
        ds.pop_back();
        rfunc(ind + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        rfunc(0, target, candidates, ans, ds);
        return ans;
    }
};

class Solution2
{
public:
    void rfunc(int ind, int target, int sum, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {

        // If sum becomes equal to target
        if (sum == target)
        {
            ans.push_back(ds);
            return;
        }

        // If sum becomes greater than target or index comes to its end
        if (sum > target || ind == arr.size())
        {
            return;
        }

        // First we are taking the number on the index and running the function again on the same index.
        ds.push_back(arr[ind]);
        sum += arr[ind];
        rfunc(ind, target, sum, arr, ans, ds);
        // After that we are not taking the number on the index and running the function on the next index.
        ds.pop_back();
        sum -= arr[ind];
        rfunc(ind + 1, target, sum, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        rfunc(0, target, 0, candidates, ans, ds);
        return ans;
    }
};


// It uses loop in the solution
class Solution3 {
    void combination(vector<int>& candidates, int target, vector<int> currComb, int currSum, int currIndex, vector<vector<int>>& ans){
        if(currSum>target) return; //backtrack
        if(currSum==target){
            ans.push_back(currComb); //store the solution and backtrack
            return;
        }
        
        for(int i=currIndex; i<candidates.size(); i++){ //try all possible options for the next level
            currComb.push_back(candidates[i]); //put 1 option into the combination
            currSum+=candidates[i];
            combination(candidates, target, currComb, currSum, i, ans); //try with this combination, whether it gives a solution or not.
            currComb.pop_back(); //when this option backtrack to here, remove this and go on to the next option.
            currSum-=candidates[i];
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;
        combination(candidates, target, currComb, 0, 0, ans);
        return ans;
    }
};


int main()
{

    return 0;
}