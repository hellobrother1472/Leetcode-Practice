#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int>ans;
    void solve(int start,int end,int height,vector<vector<int>>matrix){
        for (int i = start; i <= end; i++)
        {
            ans.push_back(matrix[start][i]);
        }
        for (int i = start+1; i <= height; i++)
        {
            ans.push_back(matrix[i][end]);
        }
        for (int i = end-1; i >= start; i--)
        {
            ans.push_back(matrix[height][i]);
        }
        for (int i = height-1; i >= start+1; i--)
        {
            ans.push_back(matrix[i][start]);
        }
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int start = 0;
        int end = matrix[0].size()-1;
        int height = matrix.size()-1;
        return ans;
    }
};

int main(){   

    return 0;
}