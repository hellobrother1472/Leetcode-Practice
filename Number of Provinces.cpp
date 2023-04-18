#include <bits/stdc++.h>
using namespace std;

// Take a node and if not visited do any type of traversal and mark visited array, so in one time all it's all connected elements will be parsed and then increase answer by one. And if another one comes of which visited is not marked it means it is another not coneected one so find out all coneected with it and marked visited and again increase the ans.

class Solution {
private:
    void bfs(vector<vector<int>>isConnected, unordered_map<int,int>&visited, int num){
        int start = num;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int nums = q.front();
            q.pop();
            visited[nums]++;
            for(int i = 0; i < isConnected.size(); i++){
                if(!visited[i] && isConnected[nums][i] == 1){
                    q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        unordered_map<int,int>visited;
        for(int i = 0 ; i < n; i++){
            if(!visited[i]){
                // cout << "i" << i << " : ";
                bfs(isConnected, visited, i);
                ans++;
            }            
        }
        return ans;
    }
};

int main(){

    return 0;
}