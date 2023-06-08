#include <bits/stdc++.h>
using namespace std;

// Performing topological sorting.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>inDegree(n,0);
        vector<vector<int>>adj(n);
        queue<int>q;
        vector<int>ans;
        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(int i = 0; i < adj[node].size(); i++){
                inDegree[adj[node][i]]--;
                if(inDegree[adj[node][i]] == 0) q.push(adj[node][i]); 
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};

int main(){

    return 0;
}