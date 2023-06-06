#include <bits/stdc++.h>
using namespace std;

// Doing dfs and in pair storing parent and node so if anytime we reaches any already visited node it means it means their is a cycle .

class Solution {
    private:
    bool dfs(int V, vector<int>adj[],int start,vector<int>&vis){
        pair<int,int>p; // {node,parent}
        queue<pair<int,int>>q;
        vis[start] = 1;
        q.push({start,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    q.push({adjNode,node});
                }
                else if(adjNode != parent) return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V+1,0);
       for(int i = 0; i < V; i++ ){
           if(!vis[i]){
               bool val = dfs(V,adj,i,vis);
               if(val) return true;
           }
       }
       return false;
    }
};

int main(){

    return 0;
}