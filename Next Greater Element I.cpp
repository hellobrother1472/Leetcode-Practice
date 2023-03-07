#include <bits/stdc++.h>
using namespace std;

// starting from last if the stack is empty map the value with -1 means their is no greater element available.
// If the curr number > st.top() it means then pop out the element in stack until we got the element greater than the current number, if their is no number greater then map it with -1.
// if the curr number < st.top() means map the number with the st.top() and push it to the stack.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        stack<int>st;
        for(int i = nums2.size()-1; i>=0 ; i--){
            int num = nums2[i];
            if(st.empty() || st.top() < num){
                while(!st.empty() && st.top() < num ){
                    st.pop();
                }
                if(st.empty()) mp[num] = -1;
                else mp[num] = st.top();
                st.push(num);
            }
            else{
                mp[num] = st.top();
                st.push(num);
            }
        }
        for(int i = 0 ; i < nums1.size() ; i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};

int main(){
    

    return 0;
}