#include <bits/stdc++.h>
using namespace std;

// To find the longest subarray first I am using a sliding window type.
// According to question 1 zero is allowed so stack is maintained for that. If stack is empty it means no zero else if we found someone in stack update the ans variable and change the previous zero pointer to previous zero + 1 as now we have remove previous zero so now we only have one zero.
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        int j = 0,count = 0,ans = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) count++;
            else if(nums[i] == 0){
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int a = st.top();
                    st.pop();
                    st.push(i);
                    if(count > ans) ans = count;
                    count = i - a - 1;
                }
            }
        }
        if(count > ans) ans = count;
        if(st.empty()) return n-1;
        return ans;
    }
};

// Without using stack
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Number of zero's in the window.
        int zeroCount = 0;
        int longestWindow = 0;
        // Left end of the window.
        int start = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            zeroCount += (nums[i] == 0);
                          
            // Shrink the window until the zero counts come under the limit.
            while (zeroCount > 1) {
                zeroCount -= (nums[start] == 0);
                start++;
            }
              
            longestWindow = max(longestWindow, i - start);
        }

        return longestWindow;
    }
};

int main(){

    return 0;
}