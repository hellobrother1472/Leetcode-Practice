#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(int i = 0; i < n; i++) adj[i][i] = 0;
        for(int i = 0;i < edges.size(); i++){
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
            adj[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        int minCity = n+1;
        int cityNo = -1;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(adj[i][k] == 1e9 || adj[k][j] == 1e9) continue;
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            int passed = 0;
            for(int j = 0; j < n; j++){
                if(adj[i][j] <= distanceThreshold) passed++;
            }
            if(passed <= minCity){
                minCity = passed;
                cityNo = i;
            }
        }
        return cityNo;
    }
};

int main(){

    return 0;
}