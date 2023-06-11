#include <bits/stdc++.h>
using namespace std;

// First I am marking the terminal nodes.
// after that I am running dfs which will mark more safe nodes.
// IN dfs function vis of start is marked 
class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>&safe,vector<int>&vis, int start, int n){
        vis[start] = 1;
        for(int i = 0; i < graph[start].size(); i++){
            int node = graph[start][i];
            // If not visited
            if(!vis[node]){
                // If any of the below subgraph return false then return false.
                if(!dfs(graph,safe,vis,node,n)) return false;
            }
            // If it is already visited then check safe array if it is safe or not, if not mean it is again false.
            else if (!safe[node]) return false;
        }
        safe[start] = 1; // If all the barrier crossed then mark start as safe
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n = graph.size();
        vector<int>safe(n,0);
        vector<int>vis(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                bool val = dfs(graph,safe,vis,i,n);
            }
        }
        for(int i = 0; i < n; i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};

// Using previous cycle detection way
class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[],
 int pathVis[], 
        int check[]) {
		vis[node] = 1;
		pathVis[node] = 1;
		check[node] = 0;
		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
			if (dfsCheck(it, adj, vis, pathVis, check) == true) {
					check[node] = 0;
					return true;
				}

			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				check[node] = 0;
				return true;
			}
		}
		check[node] = 1;
		pathVis[node] = 0;
		return false;
	}
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};
		int check[V] = {0};
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfsCheck(i, adj, vis, pathVis, check);
			}
		}
		for (int i = 0; i < V; i++) {
			if (check[i] == 1) safeNodes.push_back(i);
		}
		return safeNodes;
	}
};


int main(){

    return 0;
}