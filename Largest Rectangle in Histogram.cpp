#include <bits/stdc++.h>
using namespace std;

// Intution : When we see the vertical lines we can see that different rectangles can be made by making horizontal line so the length of horizontal line of any particular level (which is given) will be as long as their comes a level which is lower than the current level.

// So we have to find adjecent big elements on right and left.
// After finding that the are we can have is (total big on right + total big on left + 1 (himself)) * height; Using this we can find the maximum area.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        vector<int>right_elements (n);
        vector<int>left_elements (n);
        stack<int>st;

        // Finding the left's next min
        for(int i = 0 ; i < n ; i++){
            if(st.empty() || heights[st.top()] < heights[i]){
                if(st.empty()) left_elements[i] = i;
                else left_elements[i] = i - st.top() - 1;
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) left_elements[i] = i;
            else left_elements[i] = i - st.top() - 1;
            st.push(i);
        }
        
        // clean stack
        while(!st.empty()) st.pop();

        // Finding the right's next min
        for(int i = n-1 ; i >= 0 ; i--){
            if(st.empty() || heights[st.top()] < heights[i]){
                if(st.empty()) right_elements[i] = n - i - 1;
                else right_elements[i] = st.top() - i - 1;
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) right_elements[i] = n - i - 1;
            else right_elements[i] = st.top() - i - 1;
            st.push(i);
        }

        // Calculating answer
        for(int i = 0 ; i < n ; i++){
            int sum = (left_elements[i] + right_elements[i] + 1) * heights[i];
            if(sum > ans) ans = sum;
        }

        return ans;
    }
};

int main(){

    return 0;
}