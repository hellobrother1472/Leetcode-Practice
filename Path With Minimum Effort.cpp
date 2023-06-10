#include <bits/stdc++.h>
using namespace std;

// We performs the dijkstra's
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>>dis(m,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; // pq, prevDifference and pair indexes.
        pq.push({0,{0,0}});
        dis[0][0] = 0;
        int ans;
        while(!pq.empty()){
            int prevDiff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int curr = heights[row][col];
            pq.pop();

            if(row == m-1 && col == n-1){
                ans = prevDiff;
                break;
            }

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 || j == 0) {
                        int nRow = row + i;
                        int nCol = col + j;                        
                        if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n) {
                            int val = heights[nRow][nCol];
                            int diff = abs(curr-val);
                            if(max(diff,prevDiff) < dis[nRow][nCol]){ // Most important. Checking ki abhi takk ka jo path ka max distance hai kya vo dis[nRow][nCol] se chota hai as we want minimum of the maximum difference.
                                int newDiff = max(diff,prevDiff);
                                pq.push({newDiff,{nRow, nCol}});
                                dis[nRow][nCol] = newDiff;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}