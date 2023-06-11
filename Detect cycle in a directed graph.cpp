#include <bits/stdc++.h>
using namespace std;

// dfs
class Solution {
    private:
        bool dfs(int n,vector<int> adj[], vector<int>&pathVis, vector<int>&vis,int start){
            vis[start] = 1;
            pathVis[start] = 1;
            for(auto it:adj[start]){
                // If node is not previously visited
                if(!vis[it]){
                    if(dfs(n,adj,pathVis,vis,it)) return true;
                }
                // If it is previously visited but it is also visited on the same path
                else if(pathVis[it]) return true;
            }
            pathVis[start] = 0;
            return false;
        }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(V,adj,pathVis,vis,i)) return true;
            }
        }
        return false;
    }
};

// BFS (Topological sort using kahn's algorithm), perform topological sort and if their is any cycle in the graph then we don't get all the nodes in answer array means size of answer array become less than n.
class Solution {
   
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>ans;
	    vector<int>inDegree(V,0);
	    queue<int> q;
	    for(int i = 0 ; i < V; i++){
	        for(auto node:adj[i]){
	            inDegree[node]++;
	        }
	    }
	    for(int i = 0 ; i < V; i++){
	        if(inDegree[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto val:adj[node]){
	            inDegree[val] --;
	            if(inDegree[val] == 0) q.push(val);
	        }
	    }
	    return ans.size() < V;
    }
};
int main(){

    return 0;
}