#include <bits/stdc++.h>
using namespace std;

// Do the algorithm same as dijkstras, just instead of keeping node at pair.second, start storing the path using, and whenever we got the end node in the updation if statement it means it is new path with distance less than that of previous then store it to the ans. 
// If after all the for loop if still distance of last node is infinity then return vector with -1;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        priority_queue< pair<int,vector<int>>,vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;
        vector<int>ans;
        vector<vector<vector<int>>>adj(n+1);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]}); // Add this line for undirected graph
        }
        // pq.push()
        vector<int>dis(n+1, 1e9);
        dis[1] = 0;
        pq.push({0,{1}});
        while(!pq.empty()){
            vector<int> path = pq.top().second;
            int node = path.back();
            int dist = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                if(dist + edgeWeight < dis[adjNode]){
                    path.push_back(adjNode);
                    dis[adjNode] = dist + edgeWeight;
                    pq.push({dis[adjNode],path});
                    if(adjNode == n) ans = path;
                    path.pop_back();
                }
            }
        }
        if(dis[n] == 1e9) return {-1};
        return ans;
    }
};

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        vector<int> ans = {1}; // Initialize answer vector with the starting vertex 1
        vector<vector<vector<int>>> adj(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]}); // Add this line for undirected graph
        }

        vector<int> dis(n + 1, 1e9);
        dis[1] = 0;
        pq.push({0, {1}});
        while (!pq.empty()) {
            vector<int> path = pq.top().second;
            int node = path.back();
            int dist = pq.top().first;
            pq.pop();
            if (node == n) // Check if the current node is the destination vertex n
                return path; // Return the path if it reaches the destination
            if (dist > dis[node]) // Skip the current iteration if the distance is already greater
                continue;
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if (dist + edgeWeight < dis[adjNode]) {
                    dis[adjNode] = dist + edgeWeight;
                    vector<int> newPath = path; // Create a new copy of the path vector
                    newPath.push_back(adjNode); // Add the adjacent node to the new path
                    pq.push({dis[adjNode], newPath});
                }
            }
        }

        return {-1}; // If no path is found, return {-1}
    }
};

// Using parent node array. Remembering the parent;
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Create an adjacency list of pairs of the form node1 -> {node2, edge weight}
        // where the edge weight is the weight of the edge from node1 to node2.
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // Create a priority queue for storing the nodes along with distances 
        // in the form of a pair { dist, node }.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        // Create a dist array for storing the updated distances and a parent array
        //for storing the nodes from where the current nodes represented by indices of
        // the parent array came from.
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[1] = 0;

        // Push the source node to the queue.
        pq.push({0, 1});
        while (!pq.empty())
        {
            // Topmost element of the priority queue is with minimum distance value.
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            // Iterate through the adjacent nodes of the current popped node.
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // Check if the previously stored distance value is 
                // greater than the current computed value or not, 
                // if yes then update the distance value.
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});

                    // Update the parent of the adjNode to the recent 
                    // node where it came from.
                    parent[adjNode] = node;
                }
            }
        }

        // If distance to a node could not be found, return an array containing -1.
        if (dist[n] == 1e9)
            return {-1};

        // Store the final path in the ‘path’ array.
        vector<int> path;
        int node = n;

        // Iterate backwards from destination to source through the parent array.
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        // Since the path stored is in a reverse order, we reverse the array
        // to get the final answer and then return the array.
        reverse(path.begin(), path.end());
        return path;
    }
};


int main(){

    return 0;
}