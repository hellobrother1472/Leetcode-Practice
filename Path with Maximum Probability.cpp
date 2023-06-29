#include <bits/stdc++.h>
using namespace std;

// Applying similar algo as of shortest path just here I am looking for largest probability.
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>adj(n); // adjNode,weight
        priority_queue<pair<double,int>>maxHeap; // totalProb and curr
        vector<double>prob(n,INT_MIN);
        prob[start] = 1;

        // fill adj list
        for(int i = 0; i < edges.size(); i++){
            int node1 = edges[i][0], node2 = edges[i][1];
            double probability = succProb[i];
            adj[node1].push_back({node2,probability});
            adj[node2].push_back({node1,probability});
        }

        maxHeap.push({1,start});
        while(!maxHeap.empty()){
            double currProb = maxHeap.top().first;
            int currNode = maxHeap.top().second;
            maxHeap.pop();
            for(auto node : adj[currNode]){
                int adjNode = node.first;
                double adjProb = node.second;
                double newProb = currProb * adjProb;
                if(newProb > prob[adjNode]){
                    prob[adjNode] = newProb;
                    maxHeap.push({newProb,adjNode});
                }
            }
        }
        return (prob[end] == INT_MIN) ? 0 : prob[end];
    }
};

int main(){

    return 0;
}