#include <bits/stdc++.h>
using namespace std;

// Approach is the find an index from where the last element can be reached and farther the element more benificial.
// Then we got that index so we count ++;
// Then we again find some index on the left of that index such that it can be reached and farther the element more benificial.
// Doing this in while loop and counting we got the answer.

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        int ans = 0, index = n-1, i = n-2;
        while(i >= 0){
            int currIndex = index;
            while(i >= 0){
                if(i + nums[i] >= currIndex) index = i;
                i--;
            }
            i = index-1;
            ans++;
        }
        return ans;
    }
};

// https://www.youtube.com/watch?v=dJ7sWiOoK7g
// We are working on ranges first we see from first number that what could be the highest index we can go and lowest index we can go(prevHigh+1) and we count it one jump.
//Now as we got new range of number we see how farthest we can go and how lowest we can go out of that range, so doing this we got another range and again jump++;
// doing this if at some point we have our highest >= n-1 that means we got the answer and we will reach their.
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, low = 0, high = 0;
        while(high < n-1){
            int currHigh = high;
            for(int i = low ; i <= currHigh; i++){
                high = max(high,i+nums[i]);
            }
            low = currHigh + 1;
            ans++;
        }
        return ans;
    }
};

// Another implementation
class Solution {
public:
    int jump(vector<int>& nums) {
        // The starting range of the first jump is [0, 0]
        int answer = 0, n = int(nums.size());

        int curEnd = 0, curFar = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest reachable index of this jump.
            curFar = max(curFar, i + nums[i]);

            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump.
            if (i == curEnd) {
                answer++;
                curEnd = curFar;
            }
        }
        
        return answer;
    }
};

int main(){

    return 0;
}