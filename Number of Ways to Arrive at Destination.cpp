#include <bits/stdc++.h>
using namespace std;

// To count number of shortest way just include the ways in pq in which the distance in distance array is equal to sum of previous distance and new edge weight.
// It give TLE.
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<int> dist(n, 1e9);
        pq.push({0, 0}); // dist , node
        int count = 0;
        dist[0] = 0;
        
        while (!pq.empty()) {
            int currdist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            if (currNode == n - 1) {
                count++;
            }
            for (auto& neighbor : adj[currNode]) {
                int nextNode = neighbor.first;
                int travelTime = neighbor.second;
                
                if (currdist + travelTime <= dist[nextNode]) {
                    dist[nextNode] = currdist + travelTime;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        
        return count;
    }
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        int mod = (int)(1e9 + 7);

        vector<int> dist(n, LLONG_MAX), ways(n,0);
        pq.push({0, 0}); // dist , node
        int count = 0;
        dist[0] = 0;
        ways[0] = 1;
        while (!pq.empty()) {
            int currdist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            if (currNode == n - 1) {
                count++;
            }
            for (auto& neighbor : adj[currNode]) {
                int nextNode = neighbor.first;
                int travelTime = neighbor.second;
                
                if (currdist + travelTime < dist[nextNode]) {
                    dist[nextNode] = currdist + travelTime;
                    pq.push({dist[nextNode], nextNode});
                    ways[nextNode] = ways[currNode];
                }
                else if(currdist + travelTime == dist[nextNode]){
                    ways[nextNode] = (ways[nextNode] + ways[currNode]) % mod;
                }
            }
        }
        
        return ways[n-1] % mod;
    }
};

// https://www.youtube.com/watch?v=_-0mx0SmYxA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=42
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;
        vector<vector<pair<ll,ll>>> adj(n);
        for(ll i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; 
        ll mod = (ll)(1e9 + 7);

        vector<ll> dist(n, LLONG_MAX), ways(n,0);
        pq.push({0, 0}); // dist , node
        ll count = 0;
        dist[0] = 0;
        ways[0] = 1;
        while (!pq.empty()) {
            ll currdist = pq.top().first;
            ll currNode = pq.top().second;
            pq.pop();
            
            if (currNode == n - 1) {
                count++;
            }
            for (auto& neighbor : adj[currNode]) {
                ll nextNode = neighbor.first;
                ll travelTime = neighbor.second;
                
                if (currdist + travelTime < dist[nextNode]) {
                    dist[nextNode] = currdist + travelTime;
                    pq.push({dist[nextNode], nextNode});
                    ways[nextNode] = ways[currNode];
                }
                else if(currdist + travelTime == dist[nextNode]){
                    ways[nextNode] = (ways[nextNode] + ways[currNode]) % mod;
                }
            }
        }
        
        return ways[n-1] % mod;
    }
};



int main(){

    return 0;
}