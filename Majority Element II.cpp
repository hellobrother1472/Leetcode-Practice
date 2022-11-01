#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums;
        }
        sort(nums.begin(), nums.end());
        int count = 0;
        int currNum = nums[0];
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == currNum)
            {
                count++;
            }
            else
            {
                count = 1;
                currNum = nums[i];
            }
            if (count > (nums.size() / 3) && (ans.size() == 0 || nums[i] != ans[ans.size() - 1]))
            { // This is to avoid repetition
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

// Using map is also another solution with linear time complexity but O(n) space complexity.

using namespace std;
vector<int> majorityElement(int nums[], int n)
{
    int sz = n;
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
    for (i = 0; i < sz; i++)
    {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
        else if (count1 == 0)
        {
            num1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            num2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1 = count2 = 0;
    for (i = 0; i < sz; i++)
    {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
    }
    if (count1 > sz / 3)
        ans.push_back(num1);
    if (count2 > sz / 3)
        ans.push_back(num2);
    return ans;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 2};
    vector<int> majority;
    majority = majorityElement(arr, 5);
    cout << "The majority element is ";

    for (auto it : majority)
    {
        cout << it << " ";
    }
}

int main()
{

    return 0;
}