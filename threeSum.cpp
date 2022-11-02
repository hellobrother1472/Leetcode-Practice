#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low,high;
        for (int i = 0; i < n; i++)
        {
            if(i!=0 && nums[i] == nums[i-1]){
                continue;
            }
            low=i+1;
            high=n-1;
            int target = nums[i]*(-1);
            while(low<high){
                vector<int>v;
                if((nums[low]+nums[high]) < target){
                    low++;
                }
                else if((nums[low]+nums[high]) > target){
                    high--;
                }
                else{
                    v.push_back(nums[i]);
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);
                    ans.push_back(v);
                    while((low+1) && nums[low] == nums[low+1]){
                        low++;
                    }
                    low++;
                    while((high-1) && nums[high] == nums[high-1]){
                        high--;
                    }
                    high--;
                }
            }
        }
        return ans;
    }
};

int main(){
    

    return 0;
}