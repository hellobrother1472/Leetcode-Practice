#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if (nums.size() == 1 || k == 0)
        {
            return false;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j <= i + k; j++)
            {
                if (j < nums.size())
                {
                    if (nums[i] == nums[j])
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}