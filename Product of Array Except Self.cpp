#include <bits/stdc++.h>
using namespace std;

// Approach is to first find the product of all and also nonzeroproduct means if zero occur then skip it because it make whole product zero. nonzeroProduct and zerocount is necessary because if during the changing of the nums array in second for loop if nums[i] == 0, then it will show error and so keeping the nonzeroProduct but if their are more than one zeros then the answer should be zero in all cases.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int nonZeroProduct = 1;
        int zeroCount = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != 0) nonZeroProduct *= nums[i];
            else zeroCount++;

            product *= nums[i];
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                if(zeroCount <=1){
                    nums[i] = nonZeroProduct;
                }
                else{
                    nums[i] = product;
                }
            }
            else nums[i] = product/nums[i];
        }
        return nums;
    }
};

int main(){

    return 0;
}