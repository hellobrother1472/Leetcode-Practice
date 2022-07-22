#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size() / 2;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < nums.size()-1)
            {

                if (nums[i] == nums[i + 1])
                {
                    count++;
                }
                else
                {
                    count++;
                    if(count > n){
                        return nums[i];
                    }
                    count = 0;
                }
            }
        }
        return nums[nums.size()-1];
    }
};

class Solution2
{
public:
     int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

int main()
{

    return 0;
}