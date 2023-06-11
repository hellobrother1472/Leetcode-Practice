#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dis(n,1e8);
	    dis[S] = 0;
	    for(int i = 0; i < n+1; i++){
	        for(int j = 0; j < edges.size(); j++){
	            if(dis[edges[j][0]] != 1e8){
	                if(dis[edges[j][0]] + edges[j][2] < dis[edges[j][1]]){
	                    if(i == n) return {-1}; // In case of negetive cycle.
	                    dis[edges[j][1]] = dis[edges[j][0]] + edges[j][2];
	                }
	            }
	        }
	    }
	    return dis;
    }
};

int main(){

    return 0;
}