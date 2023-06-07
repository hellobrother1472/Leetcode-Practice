#include <bits/stdc++.h>
using namespace std;

// First approach is to apply dfs to every zero, and as soon as it got 1 return the level for that one.
// In dfs function we put the start in queue with it's level as zero, then we put it's 4 directional neibours then if any of the neibour is 1 then we will return it's level which is the distance of that one.


// Second approach is to see it in reverse fashion, in which we start from all the ones and then if we got zero then the level they are at becomes their distancd from 1.

class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0 ; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int level = q.front().second;
            q.pop();

            ans[row][col] = level;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 || j == 0) {
                        int nRow = row + i;
                        int nCol = col + j;

                        if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n && !vis[nRow][nCol]) {
                            q.push({{nRow, nCol}, level + 1});
                            vis[nRow][nCol] = 1;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

// way 2
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0)
            return grid;
        int cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }
};

int main(){

    return 0;
}