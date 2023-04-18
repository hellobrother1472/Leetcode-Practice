#include <bits/stdc++.h>
using namespace std;

// Just performing bfs on the first peice of land on which we are not visited and after that we are marking visited as we perform the bfs. So as many times we have to perform dfs that number of islands are thier.

class Solution {
private:
    void bfs(int row, int col,vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int delRow = -1; delRow <= 1; delRow++){
                for(int delCol = -1; delCol <= 1; delCol++){
                    if((delRow==-1&& delCol==-1) || (delRow==-1&& delCol==1) || (delRow==1&& delCol==-1) || (delRow==1&& delCol==1)){
                        continue;
                    }
                    int nRow = row + delRow;
                    int nCol = col + delCol; 
                    if(nRow >= 0 && nCol >=0 && nRow < grid.size() && nCol < grid[0].size() && !vis[nRow][nCol] && grid[nRow][nCol] == '1'){
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }   
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m,0)); // For keep track of vis areas
        
        for(int row = 0 ; row < n; row++){
            for(int col = 0 ; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                } 
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}