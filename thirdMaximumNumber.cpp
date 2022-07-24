#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
        {
            return nums[nums.size() - 1];
        }
        int num = 1;
        for (int i = nums.size()-2; i >=0; i--)
        {
            if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                num++;
                if(num == 3){
                    return nums[i];
                }
            }
        }
        return nums[nums.size()-1];
    }
};

int main()
{

    return 0;
}