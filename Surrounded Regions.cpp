#include <bits/stdc++.h>
using namespace std;

// so at first we find all the connected 'O' from the boundary 'O' and mark them 'Y' to seperate. After that the we got the zeros which is not connected to boundary elements so we make them 'X' and 'Y' one's are again made '0'

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0 ; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (((i < 1 || i > m-2) || (j < 1 || j > n-2)) && board[i][j] == 'O') {
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
            board[row][col] = 'Y';

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 || j == 0) {
                        int nRow = row + i;
                        int nCol = col + j;

                        if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n && !vis[nRow][nCol] && board[nRow][nCol] == 'O') {
                            q.push({nRow, nCol});
                            vis[nRow][nCol] = 1;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'Y') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};

int main(){

    return 0;
}