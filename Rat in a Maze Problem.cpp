#include <bits/stdc++.h>
using namespace std;

// The logic is same as of Word search problem.
// Step 1: Start from first index.

// Step 2: Start Backtracking in all four directions until we find the 1's .

// Step 3: At the end, If we found our result then add to ans .

// Changing the value of ans itself and then resetting it after the work is done.
// Basically starting from (0,0) I am searching for adjecent 1 so because of that I am checking in up,down,left and right direction and continuing the reccursion in all direction and checking the all possible solution. When I got to the (n-1,n-1) I am storing the value in ans and returning.
class Solution{
    public:
    void helper(vector<string>&ans, string &ds, int i, int j, vector<vector<int>>&m,int n)
    {
        if (m[i][j] != 1)
            return ;
        if (i == n-1 && j == n-1){
            ans.push_back(ds);
            return;
        }
        m[i][j] = 0;
        if (i > 0){
            ds.push_back('U');
            helper(ans,ds,i-1,j,m,n);
            ds.pop_back();
        }
        if (i < n - 1){
            ds.push_back('D');
            helper(ans,ds,i+1,j,m,n);
            ds.pop_back();
        }
        if (j > 0){
            ds.push_back('L');
            helper(ans,ds,i,j-1,m,n);
            ds.pop_back();
        }
        if (j < n - 1){
            ds.push_back('R');
            helper(ans,ds,i,j+1,m,n);
            ds.pop_back();
        }

        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        string ds = "";
        helper(ans,ds,0,0,m,n);
        return ans;
    }
};

int main(){

    return 0;
}