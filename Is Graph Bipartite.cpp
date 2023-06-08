#include <bits/stdc++.h>
using namespace std;

// Using BFS
//  It starts by initializing the queue with the start node and assigns it a color of 0. Then, it iteratively processes each node in the queue and assigns the opposite color to its adjacent nodes. If a conflict occurs, i.e., an adjacent node already has the same color, the graph is not bipartite, and the function returns false.
// If the traversal completes without any conflicts, the graph is bipartite, and the function returns true.
// To handle disconnected components in the graph, the code iterates over all nodes and performs the DFS from unvisited nodes.
class Solution {
    bool bfs(vector<vector<int>>& graph,int n, int start,vector<int>&vis,vector<int>&col){
        queue<pair<int,int>>q; // Node,Color
        // Colors are 0 and 1
        q.push({start,0});
        vis[start] = 1;
        col[start] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int color = q.front().second;
            q.pop();
            for(int i = 0; i < graph[node].size(); i++){
                int nextNode = graph[node][i];
                if(!vis[nextNode]){
                    q.push({nextNode, !color});
                    vis[nextNode] = 1;
                    col[nextNode] = !color;
                }
                else if(vis[nextNode] && col[nextNode] == color) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>col(n,0);
        for(int i = 0 ; i < n; i++){
            if(!vis[i]){
                bool val = bfs(graph,n,i,vis,col);
                if(!val) return false;
            }
        }
        return true;
    }
};

// BFS 2
class Solution {
    bool bfs(vector<vector<int>>& graph,int n, int start,vector<int>&col){
        queue<int>q; // Node,Color
        // Colors are 0 and 1
        q.push(start);
        col[start] = 0;
        while(!q.empty()){
            int node = q.front();
            int color = col[node];
            q.pop();
            for(int i = 0; i < graph[node].size(); i++){
                int nextNode = graph[node][i];
                if(col[nextNode] == -1){
                    q.push(nextNode);
                    col[nextNode] = !color;
                }
                else if(col[nextNode] == color) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>col(n,-1);
        for(int i = 0 ; i < n; i++){
            if(col[i] == -1){
                bool val = bfs(graph,n,i,col);
                if(!val) return false;
            }
        }
        return true;
    }
};

// DFS
class Solution {
    bool dfs(vector<vector<int>>& graph,int n, int start,vector<int>&col,int color){
        int node = start;
        col[node] = color;
        for(int i = 0; i < graph[node].size(); i++){
            int nextNode = graph[node][i];
            if(col[nextNode] == -1){
                if(dfs(graph,n,nextNode,col,!color) == false) return false;
            }
            else if(col[nextNode] == color) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>col(n,-1);
        for(int i = 0 ; i < n; i++){
            if(col[i] == -1){
                bool val = dfs(graph,n,i,col,0);
                if(!val) return false;
            }
        }
        return true;
    }
};

int main(){

    return 0;
}