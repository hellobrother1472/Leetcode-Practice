#include <bits/stdc++.h>
using namespace std;

// Intution is that I am comparing the size of window which contain atmost k zeros. And return max

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int zeroCount = 0;
        int i = 0, j = 0;
        while(j < n && i < n){
            if(nums[j] == 1 || zeroCount < k){
                if(nums[j] == 0) zeroCount++;
                j++;
            }
            else{
                while(zeroCount >= k){
                    if(nums[i] == 0) zeroCount--;
                    i++;
                }
            }   
            if(j-i > count) count = j-i;
        }
        return count;
    }
};

int main(){

    return 0;
}