#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans( n , vector<int> (n)); // Defining the size of the vector.
        for(int row = 0; row< n;row++){
            for(int col = 0; col< n;col++){
                int newCol = abs((n-1) - row); // just dry run the sol on paper you will get this formula.
                ans[col][newCol] = matrix[row][col];
            }
        }
        matrix = ans;
    }
};

// This solution does'nt take extra space. In it we are doing first transpose and then we are reversing. This intution is also comes from solving on paper.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // here we are doing transpose.
        for(int row = 0; row< n;row++){
            for(int col = 0; col< row;col++){
                swap(matrix[row][col],matrix[col][row]);
            }
        }
        // Here we are reversing rows
        for(int row = 0; row< n;row++){
            reverse(matrix[row].begin(),matrix[row].end());
        }
    }
};

int main(){
    

    return 0;
}