#include <bits/stdc++.h>
using namespace std;

// Firstly I am filling the queue with the initial no. of rotten oranges with their indexes which is stored in pairs.
// Then I am running a while loop that number of times and check up,down,right and left for any other good oranges if their is one we add it to stack and add to next count because at 1 instant we only want first lot to complete first ie.. count after the completion of first lot the count = nextCount and nextCount = 0.
// After that if their is any good orange left then it is impossible to do futher steps so return 0

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0, count = 0, nextCount = 0;
        pair<int,int>p;
        queue<pair<int,int>>q;

        // fill the queue
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    count++;
                    p.first = i;
                    p.second = j;
                    q.push(p);
                }
            }
        }

        while(!q.empty()){
            while(!q.empty() && count > 0){
                int i = q.front().first , j = q.front().second;
                // Up
                if(i > 0 && grid[i-1][j] == 1){ 
                    nextCount++;
                    p.first = i-1;
                    p.second = j;
                    q.push(p);
                    grid[i-1][j] = 2;
                }
                // Left
                if(j > 0 && grid[i][j-1] == 1){
                    nextCount++;
                    p.first = i;
                    p.second = j-1;
                    q.push(p);
                    grid[i][j-1] = 2;
                }
                // Down
                if(i < grid.size()-1 && grid[i+1][j] == 1){
                    nextCount++;
                    p.first = i+1;
                    p.second = j;
                    q.push(p);
                    grid[i+1][j] = 2;
                }
                // Right
                if(j < grid[0].size()-1 && grid[i][j+1] == 1){
                    nextCount++;
                    p.first = i;
                    p.second = j+1;
                    q.push(p);
                    grid[i][j+1] = 2;
                }
                q.pop();
                count--;
            }
            time++;
            count = nextCount;
            nextCount = 0;
        }

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return (time == 0) ? 0 : time-1;
    }
};

int main(){

    return 0;
}