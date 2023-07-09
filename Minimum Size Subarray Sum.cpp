#include <bits/stdc++.h>
using namespace std;

// Normal sliding window just maintain a window, as soon as the size become greater than target, start reducing the window size until window sum becomes less than target and compare size everytime and find answer
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, ans = INT_MAX,j=0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum >= target){
                while(sum >= target && j <= i){
                    ans = min(ans,abs(j-i)+1);
                    sum -= nums[j];
                    j++;
                }
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};

int main(){

    return 0;
}