#include <bits/stdc++.h>
using namespace std;

// The brute force approach which comes in mind is that just remove the cell given in cells array and check by bfs.
// The optimized appraoch is doing the same thing but using binary search.

class Solution {
private:
    bool helper(int row, int col, vector<vector<int>>& cells,int mid){
        vector<vector<int>>grid(row,vector<int>(col,0));
        for(int i = 0; i < mid; ++i) grid[cells[i][0]-1][cells[i][1]-1] = 1;
        queue<pair<int,int>>q;
        for(int i = 0; i < col; ++i){
            if(grid[0][i] == 0){
                q.push({0,i});
                grid[0][i] = 1;
            }
        }
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(r == row-1) return true;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr == row || nc < 0 || nc == col || grid[nr][nc] == 1) continue;
                grid[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(),ans = 0;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(helper(row,col,cells,mid)){
                ans = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}