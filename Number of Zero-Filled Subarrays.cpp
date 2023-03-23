#include <bits/stdc++.h>
using namespace std;

// The approach is the count the group of zeros and seperately find out total subarrays they are forming and adding them
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0){
                while(i<nums.size() && nums[i] == 0){
                    count++;
                    i++;
                }
                ans += (count*(count+1))/2;
                count = 0;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}