#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force meathod
// The meathod is correct but the time limits exceeds
class Solution1
{
public:
    void rfunc(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {

        // If target becomes zero
        if (target == 0)
        {
            if (count(ans.begin(), ans.end(), ds))
            { // Checking to avoid repetition
                return;
            }
            else
            {
                ans.push_back(ds);
                return;
            }
            // ans.push_back(ds);
            // return;
        }

        // If target becomes less than zero or index comes to its end
        if (target < 0 || ind == arr.size())
        {
            return;
        }

        // First we are taking the number on the index and running the function again on the same index.
        ds.push_back(arr[ind]);
        rfunc(ind + 1, target - arr[ind], arr, ans, ds);

        // After that we are not taking the number on the index and running the function on the next index.
        ds.pop_back();
        rfunc(ind + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // Sorting the array
        vector<vector<int>> ans;
        vector<int> ds;
        rfunc(0, target, candidates, ans, ds);
        return ans;
    }
};

class Solution2
{
public:
    void rfunc(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        if (target < 0 || ind == arr.size())
        {
            return;
        }

        // Looping through every element
        for (int i = ind; i < arr.size(); i++)
        {
            if(target < 0){ // If the target is crossed then it is no need to check further
                break;
            }
            if (i > ind && arr[i] == arr[i-1] ) // If their is repetition then continue, we don't want this
            {
                continue;
            }
            else{
                // after crossing all the ifs we add the value to ds and run the reccursive function and then pop it during backtracking.
                ds.push_back(arr[i]);
                rfunc(i+1, target - arr[i], arr, ans, ds);
                ds.pop_back();
            }
           
         
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        rfunc(0, target, candidates, ans, ds);
        return ans;
    }
};

int main()
{

    return 0;
}