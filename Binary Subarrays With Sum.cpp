#include <bits/stdc++.h>
using namespace std;

// first by sliding window I search for sum to match goal and after that I run a while loop where I run k which is equal to i, again to find all the subsets possible in that particular window and then I move on

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0, i = 0, j = 0, n = nums.size(), sum = 0;
        while(i < n && j < n){
            sum += nums[j];
            if(sum == goal){
                int dummySum = sum;
                int k = i;
                while(k <= j){
                    if(dummySum == goal) count++;
                    else break;
                    dummySum -= nums[k];
                    k++;
                }
                j++;
            }
            else if(sum < goal) j++;
            else{
                while(i <= j && sum > goal){
                    sum -= nums[i];
                    i++;
                }
                int dummySum = sum;
                int k = i;
                while(k <= j){
                    if(dummySum == goal) count++;
                    else break;
                    dummySum -= nums[k];
                    k++;
                }
                j++;
            }
        }
        return count;
    }
};

// https://www.youtube.com/watch?v=20v8zSo2v18

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0,sum = 0;
        map<int,int>m;
        m[0] = 1;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
            if(m[sum-goal]) count += m[sum-goal];
            m[sum] ++;
            cout << count << " ";
        }
        return count;
    }
};

int main(){

    return 0;
}