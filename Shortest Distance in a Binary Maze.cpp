#include <bits/stdc++.h>
using namespace std;

// Normal BFS
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        if(grid[source.first][source.second] == 0) return -1;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        q.push({source,0});
        vis[source.first][source.second] = 1;
        int reqRow = destination.first;
        int reqCol = destination.second;
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int level = q.front().second;
            q.pop();
            if(row == reqRow && col == reqCol) return level;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 || j == 0) {
                        int nRow = row + i;
                        int nCol = col + j;

                        if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                            q.push({{nRow, nCol},level+1});
                            vis[nRow][nCol] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main(){

    return 0;
}