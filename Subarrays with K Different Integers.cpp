#include <bits/stdc++.h>
using namespace std;

// Brute Force : checking every single subarray
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> basket;
        int left = 0, ans = 0;
        for (int right = 0; right < nums.size(); right++) {

            basket[nums[right]]++;            
            while (basket.size() > k) {
                basket[nums[left]]--;
                if (basket[nums[left]] == 0)
                    basket.erase(nums[left]);
                left++;
            }
            if(basket.size() == k){
                int i = left;
                unordered_map<int, int> dummy = basket;
                while(dummy.size() == k) {
                    dummy[nums[i]]--;
                    if (dummy[nums[i]] == 0)
                        dummy.erase(nums[i]);
                    i++;
                    ans++;
                }
            }    
        }
        
        return ans;
    }
};

int main(){
    

    return 0;
}