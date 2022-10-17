#include <bits/stdc++.h>

using namespace std;

// An intution similar to sliding window algorithm. This is O(n) solution.
// The algo is that, for every value added, if it makes sum <=0 then I stop adding and store the particular number. If it does'nt make the sum <=0 I simply add it to sum (because their is no harm in carrying the positive sum subarray) and store the value in vector. At last I have all the possible values I sort them and get the greatest of them.
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((sum + nums[i]) > 0)
            {                
                sum = sum + nums[i];
                ans.push_back(sum);
            }
            else
            {
                ans.push_back(nums[i]);
                sum = 0;
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
    }
};

// Same approach as above without using vector.
// This is Kadane's Algorithm. (Approach is similar)
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum=0;
        int maxsum=INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum+=nums[i];  // Adding it first
            maxsum=max(maxsum,sum); // Checking it with sum.
            // If the above addition made the value negetive we make sum zero.
            if(sum<0)
                sum=0;
        }
        return maxsum;
    }
};

int main()
{

    return 0;
}