#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// I perform the rotation using deque.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i = 0 ;i<nums.size();i++){
            dq.push_back(nums[i]);
        }
        for(int i = 0 ;i<k;i++){
            int ele = dq.back();
            dq.pop_back();
            dq.push_front(ele);
        }
        for(int i = 0 ;i<nums.size();i++){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        nums = ans;
    }
};

int main(){
    

    return 0;
}