#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // Meathod 1
        //    vector<int> ans;

        //    for (int i = 0; i < ans.size(); i++)
        //    {
        //     for (int j = i; j < ans.size(); j++)
        //     {
        //         if(nums[i] + nums[j] == target){
        //             ans.push_back(nums[i]);
        //             ans.push_back(nums[j]);
        //         }
        //         else{
        //             continue;
        //         }
        //     }

        //    }

        //    return ans;

        // Meathod 2 (Two Pointers Meathod)
        vector<int> ans;

    }
};

void display(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    vector<int> a = {2, 7, 11, 15};
    class Solution b;
    display(b.twoSum(a, 9));
    return 0;
}