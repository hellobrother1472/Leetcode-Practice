#include <bits/stdc++.h>
using namespace std;

// Simply do the bfs and the level at which any of the node occurs it is it's shortest distance.
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>>adj(N);
        vector<int>vis(N,0);
        vector<int>dis(N,1e9);
        dis[src] = 0;
        for(int i = 0; i < M; i++){ // adj matrix
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int level = q.front().second;
            q.pop();
            dis[node] = level;
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it,level+1});
                    vis[it] = 1;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (dis[i] == 1e9) dis[i] = -1;
        }
        return dis;
    }
};

int main(){

    return 0;
}