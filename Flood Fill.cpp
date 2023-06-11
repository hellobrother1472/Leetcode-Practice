#include <bits/stdc++.h>
using namespace std;

// Doing simple BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int val = image[sr][sc];
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            image[row][col] = color;
            q.pop();
            for(int delRow = -1; delRow <= 1; delRow++){
                for(int delCol = -1; delCol <= 1; delCol++){
                    if(delRow==0 || delCol== 0){
                        int nRow = row + delRow;
                        int nCol = col + delCol; 
                        if(nRow >= 0 && nCol >=0 && nRow < image.size() && nCol < image[0].size() && image[nRow][nCol] != color && image[nRow][nCol] == val){
                            image[nRow][nCol] = color;
                            q.push({nRow, nCol});
                        }
                    }
                    
                }   
            }
        }
        return image;
    }
};

int main(){

    return 0;
}