#include <bits/stdc++.h>
using namespace std;

// Create a window and do accordingly.
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n,-1);
        if(2*k+1 > n) return ans;
        int i = 0, j = 2*k, ptr = k, end = n-k-1, total = 2*k+1; 
        long long sum = 0;
        for(int l = 0; l <= j; l++){
            sum += nums[l];
        }
        while(j < n && ptr <= end){
            long long avg = sum/total;
            ans[ptr] = avg;
            sum -= nums[i];
            i++;
            j++;
            ptr++;
            if(j < n) sum += nums[j];
        }
        return ans;
    }
};

int main(){

    return 0;
}