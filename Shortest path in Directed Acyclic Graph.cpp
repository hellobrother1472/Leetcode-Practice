#include <bits/stdc++.h>
using namespace std;

// Do a toposort and relax the nodes which are in the stack. Relaxing means if distance of current node + edge weight < current distance in array then reduce it to new.
class Solution {
  private:
    void topoSort(vector<vector<pair<int,int>>>&adj,vector<int>&vis,int start,stack<int>&st){ // Using dfs topo
        vis[start] = 1;
        for (auto node : adj[start])
        {
            if (!vis[node.first]) topoSort(adj,vis,node.first,st);
        }
        st.push(start);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>>adj(N);
        stack<int>st;
        vector<int>vis(N,0);
        vector<int>dis(N,1e9);
        dis[0] = 0;
        for(int i = 0; i < edges.size(); i++){ // adj matrix
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topoSort(adj,vis,i,st);
            }
        }
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it : adj[node]){
                if(dis[node] + it.second < dis[it.first]) dis[it.first] = dis[node] + it.second;
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