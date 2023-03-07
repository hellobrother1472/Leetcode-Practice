#include <bits/stdc++.h>
using namespace std;

// The intution is that first I will find the next greatest element normally. But with a change that I am flagging the value which not becomes -1 due to absence of greater element, then become -1 because their is the element present which is -1 greater that the element (for eg -1 > -2).

// Now as question demands the answer for the circular array, so now we have to focus on the answer array from step one and check for the elements with -1 (absense of next greater on right) and find the farthest greatest element from them on left (because that is the next greatest element circularly) (for eg: 5,1,2,3,4 here 5 is the next greater element of 4 which is farthest greatest on left)

// Thier is the observation that when we complete the process of finding the next greatest element the stack we left with will have the values which contains basically the farthest greatest on left. When we filled the stack we had stored the element in increasing order and the number marked with -1 (due to absence) means their is no greater element on the right keeping this in try to do it on copy.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size());
        map<int,int>flag;
        stack<int>st;
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            int num = nums[i];
            if(st.empty() || num >= st.top()){
                while(!st.empty() && num >= st.top()) st.pop();
                if(st.empty()) ans[i] = -1;
                else {
                    ans[i] = st.top();
                    if(ans[i] == -1) flag[i]++;
                }
                st.push(num);
            }
            else{
                ans[i] = st.top();
                if(ans[i] == -1) flag[i]++;
                st.push(num);
            }
        }
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            if(!flag[i] && ans[i] == -1){
                if(st.empty()) return ans;

                if(st.top() > nums[i]) ans[i] = st.top();
                else{
                    while(!st.empty() && st.top() <= nums[i]) st.pop();
                    if(st.empty()) ans[i] = -1;
                    else ans[i] = st.top();
                }
            }
        }
        return ans;
    }
};

// The only difference between a circular and non-circular array is that while searching for the next greater element in a non-circular array we don’t consider the elements left to the concerned element.
// This can be easily done by inserting the elements of the array A at the end of A, thus making its size double. But we actually don’t require any extra space. We can just traverse the array twice. We actually run a loop 2*N times, where N is the size of the given array.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size());
        stack<int>st;
        for(int i = (2*nums.size())-1 ; i >= 0 ; i--){
            int num = nums[i% (nums.size())];
            if(st.empty() || num >= st.top()){
                while(!st.empty() && num >= st.top()) st.pop();
                if(st.empty()) ans[i% (nums.size())] = -1;
                else ans[i% (nums.size())] = st.top();
                st.push(num);
            }
            else{
                ans[i% (nums.size())] = st.top();
                st.push(num);
            }
        }
       
        return ans;
    }
};

int main(){

    return 0;
}