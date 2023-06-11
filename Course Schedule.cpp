#include <bits/stdc++.h>
using namespace std;

// We have to find that if the all courses can be done or not.
// Their is a dependency of every course on other.
// So it forms a graph and if we found the order in which the courses can be completed then we will compare the size of the answer array with that of given numCourses if it is equal then it means all courses can be completed 
// But if not, means if their is any cycle in graph or all courses can't be completed then the size of answer array will not be equal to numCourses.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>inDegree(n,0);
        vector<vector<int>>adj(n);
        queue<int>q;
        vector<int>ans;
        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]); // Creating adjencency matrix
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
        return ans.size() >= n;
    }
};

int main(){

    return 0;
}