#include <bits/stdc++.h>
using namespace std;

// Same as fruit into basket problem just an extra condition of basket.size() == k

class Solution{
  public:
    int longestKSubstr(string nums, int k) {
        unordered_map<int, int> basket;
        int left = 0, maxPicked = -1;
        for (int right = 0; right < nums.size(); ++right) {
            basket[nums[right]]++;            
            while (basket.size() > k) {
                basket[nums[left]]--;
                if (basket[nums[left]] == 0)
                    basket.erase(nums[left]);
                left++;
            }            
            if(basket.size() == k)maxPicked = max(maxPicked, right - left + 1); // Here extra condition
        }
        
        return maxPicked;
    }
};

int main(){
    
    return 0;
}