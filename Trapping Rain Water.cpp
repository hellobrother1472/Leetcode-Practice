#include <bits/stdc++.h>
using namespace std;

// Wrong solution but somewhat correct
// Trying to find the pattern using next greater element
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>ne;
        int index = 0;
        while(index < height.size() && height[index] == 0) index++;
        for(int i = index; i<height.size() ;i++) {
            ne.push_back(height[i]);
        }
        height = ne;
        int n = height.size();
        vector<int>helper(n);
        stack<int>st;
        int ans = 0;
        int count = 0;
        bool flag = false;
        // Filling the helper
        for(int i = n-1 ; i >= 0; i--){
            if(st.empty() || height[st.top()] >= height[i]){
                if(st.empty()) {
                    helper[i] = -1;
                    st.push(i);
                    continue;
                }
                helper[i] = st.top() - i ;
                st.push(i);
                continue;
            }
            while(!st.empty() && height[st.top()] < height[i]){
                st.pop();
            }
            if(st.empty()) {
                helper[i] = -1;
                st.push(i);
                continue;
            }
            helper[i] = st.top() - i ;
            st.push(i);
        }
        if(helper.size() > 0 && helper[0] == -1){
            for(int i = 0 ; i < n; i++){
                if(st.empty() || height[st.top()] >= height[i]){
                    if(st.empty()) {
                        helper[i] = -1;
                        st.push(i);
                        continue;
                    }
                    helper[i] = i - st.top() - 1;
                    st.push(i);
                    continue;
                }
                while(!st.empty() && height[st.top()] < height[i]){
                    st.pop();
                }
                if(st.empty()) {
                    helper[i] = -1;
                    st.push(i);
                    continue;
                }
                helper[i] = i-st.top() - 1 ;
                st.push(i);
            }
            int i = n-1;
            while(i >= 0){
                count = helper[i];
                int val = -1;;
                if(count > 0) val = height[i];
                while(count > 0){
                    i--;
                    ans += height[i] - val;
                    count--;
                }
                i--;
            }
            return ans * -1;
        }
        int i = 0;
        while(i < n){
            if(helper[i] <= 0) {
                flag = true;
                i++;
                continue;
            }
            count = helper[i];
            int val = -1;;
            if(count > 0) val = height[i];
            while(count > 0){
                i++;
                if(val - height[i] > 0) ans += val - height[i];
                else if(val-height[i] < 0 && flag) ans += height[i] - val;
                count--;
            }
        }
        return ans;
    }
};

// value of water above any block is depending on the max value on the left and max value on the right. So first we found those.
// After that we can observe from the diagram the amount of water above a block is min(leftMax[i], rightMax[i]) - height[i]

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftMax(n);
        vector<int>rightMax(n);
        int ans = 0;
        int lMax = INT_MIN, rMax = INT_MIN;
        for(int i = 0; i < n;i++){
            if(height[i] >= lMax) lMax = height[i];
            leftMax[i] = lMax;
        }
        for(int i = n-1; i >= 0 ;i--){
            if(height[i] >= rMax) rMax = height[i];
            rightMax[i] = rMax;
        }
        int i = 0;
        while(i < n){
            ans += min(leftMax[i], rightMax[i]) - height[i];
            i++;
        }
        return ans;
    }
};

int main(){
    

    return 0;
}