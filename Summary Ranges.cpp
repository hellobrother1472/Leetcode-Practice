#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>ans;
        if(n == 0) return {};
        if(n == 1) return {to_string(nums[0])};
        int start = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i-1] + 1 != nums[i]){
                if(start == nums[i-1]) ans.push_back(to_string(start));
                else{
                    string temp = "";
                    temp += to_string(start);
                    temp += "->";
                    temp += to_string(nums[i-1]);
                    ans.push_back(temp);
                }
                start = nums[i];
            }
        }
        if(start == nums[n-1]){
            ans.push_back(to_string(start));
        }
        else{
            string temp = "";
            temp += to_string(start);
            temp += "->";
            temp += to_string(nums[n-1]);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(){

    return 0;
}