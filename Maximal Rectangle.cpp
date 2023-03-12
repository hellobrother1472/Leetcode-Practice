#include <bits/stdc++.h>
using namespace std;

// It uses function which is used to find out largest rectangle in histogram.
// The concept is we will take rows and cosider them to be given histogram array and find the max areas
// For more :- https://www.youtube.com/watch?v=St0Jf_VmG_g&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=9

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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int>heights(matrix[0].size(), 0);
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(int(matrix[i][j]) == 49 ) heights[j] += 1;
                else heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            if(area > ans) ans = area;
        }
        return ans;
    }
};

int main(){

    return 0;
}