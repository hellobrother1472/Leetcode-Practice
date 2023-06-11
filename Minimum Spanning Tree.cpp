#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // dis, curr
        vector<int>vis(V,0);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            if(vis[currNode]){
                continue;
            }
            vis[currNode] = 1;
            sum += dis;
            for(auto it : adj[currNode]){
                int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
            }
            
        }
        return sum;
    }
};

int main(){

    return 0;
}