#include <bits/stdc++.h>
using namespace std;

// Normal as tree's breadth first search we are using queue and when we get to a node we store all the connected elements in the queue.
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,int> visited;
        vector<int>ans;
        queue<int>q;
        int start = 0;
        q.push(start);
        visited[start]++;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto i : adj[top]){
                if(!visited[i]){
                    visited[i]++;
                    q.push(i);
                }
            }
            ans.push_back(top);
        }
        return ans;
    }
};

int main(){

    return 0;
}