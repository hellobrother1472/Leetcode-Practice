#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Sorting and counting the elements and returning the largest value.
// Pattern of sort and then solve.

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        int count = 1;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                count++;
            else
                count = 1;
            if (count > (nums.size() / 2))
                ans = nums[i];
        }
        return ans;
    }
};

class Solution2
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// Intution is that if the number is present more than n/2 time so if we perform the adding on getting element and subtracting on not that element the element which will survive is our ans.
// Moore's Voting Algorithm

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ele = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if(count == 0){
                ele = nums[i];
            }
            if(nums[i] == ele){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};

int main()
{

    return 0;
}