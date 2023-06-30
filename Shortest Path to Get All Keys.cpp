#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int numRows = grid.size();  // Number of rows in the grid
        int numCols = grid[0].size();  // Number of columns in the grid
        int numKeys = 0;  // Total number of keys in the grid
        
        // Directions for movement: down, up, right, left
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        queue<pair<pair<int, int>, int>> q;  // Queue to perform BFS
        map<pair<pair<int, int>, int>, int> visited;  // Map to store visited positions and their bitmask
        
        // Find the starting position and count the total number of keys
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] == '@') {
                    // Add the starting position to the queue with bitmask 0 (no keys collected yet)
                    q.push({{i, j}, 0});
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    // Increment the key count if a lowercase letter (key) is found
                    numKeys++;
                }
            }
        }
        
        int targetMask = (1 << numKeys) - 1;  // Target bitmask with all keys collected
        
        int minSteps = 0;  // Minimum number of steps required to collect all keys
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                auto current = q.front();
                q.pop();
                
                int x = current.first.first;  // Current row position
                int y = current.first.second;  // Current column position
                int currentMask = current.second;  // Current bitmask of collected keys
                
                // If all keys have been collected, return the current minimum number of steps
                if (currentMask == targetMask) {
                    return minSteps;
                }
                
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];  // New row position
                    int ny = y + dy[d];  // New column position
                    
                    // Check if the new position is within the grid boundaries and not a wall
                    if (nx >= 0 && nx < numRows && ny >= 0 && ny < numCols && grid[nx][ny] != '#') {
                        int newMask = currentMask;  // New bitmask of collected keys
                        
                        // Check the type of the cell
                        if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
                            // If the cell contains a key, update the bitmask by setting the corresponding bit to 1
                            newMask |= (1 << (grid[nx][ny] - 'a'));
                        } else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') {
                            // If the cell contains a lock, check if the corresponding key is present in the bitmask
                            // If not, skip to the next iteration
                            int keyIndex = grid[nx][ny] - 'A';
                            if ((currentMask & (1 << keyIndex)) == 0) {
                                continue;
                            }
                        }
                        
                        // Check if the new position and bitmask have not been visited before
                        if (visited.find({{nx, ny}, newMask}) == visited.end()) {
                            visited[{{nx, ny}, newMask}] = newMask;
                            q.push({{nx, ny}, newMask});
                        }
                    }
                }
            }
            
            minSteps++;  // Increment the minimum number of steps
        }
        
        // If it's not possible to collect all keys, return -1
        return -1;
    }
};


int main(){

    return 0;
}