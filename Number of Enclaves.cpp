#include <bits/stdc++.h>
using namespace std;

// The question boils down to how many not connected 1 from the boundary ones.

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0 ; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (((i < 1 || i > m-2) || (j < 1 || j > n-2)) && grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            grid[row][col] = 2;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 || j == 0) {
                        int nRow = row + i;
                        int nCol = col + j;

                        if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                            q.push({nRow, nCol});
                            vis[nRow][nCol] = 1;
                        }
                    }
                }
            }
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};

int main(){

    return 0;
}