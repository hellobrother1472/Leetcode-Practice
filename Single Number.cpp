#include <bits/stdc++.h>
using namespace std;

// Using maps
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        map<int,int>mp;
        for(int i=0 ; i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0 ; i<nums.size();i++){
            if(mp[nums[i]] == 1){
                ans = nums[i];
            }
        }
        return ans;
    }
};

// Using bit manipulation
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int val = nums[0];
        for(int i=1 ; i<nums.size();i++){
            val = val ^ nums[i];
        }
        return val;
    }
};
int main(){
    return 0;
}