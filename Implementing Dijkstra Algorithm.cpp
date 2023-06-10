#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S}); // Distance , node
        vector<int>dis(V,1e9);
        dis[S] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int adjNode = it[0];
                int weight = it[1];
                if(dis[node] + weight < dis[adjNode]){
                    dis[adjNode] = dis[node] + weight;
                    pq.push({dis[adjNode] , adjNode});
                }
            }
            
        }
        return dis;
    }
};

int main(){

    return 0;
}