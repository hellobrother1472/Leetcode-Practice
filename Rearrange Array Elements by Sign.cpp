#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> positive;
        vector<int> negetive;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                negetive.push_back(nums[i]);
            }
            else
            {
                positive.push_back(nums[i]);
            }
        }
        int j = 0;
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                nums[i] = positive[j];
                j++;
            }
            else
            {
                nums[i] = negetive[k];
                k++;
            }
        }
        return nums;
    }
};

// Same concept without using only one array.
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int j = 0, k = 1;
        vector<int> v1(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                v1[j] = nums[i];
                j = j + 2;
            }
            else
            {
                v1[k] = nums[i];
                k = k + 2;
            }
        }
        return v1;
    }
};

int main()
{

    return 0;
}