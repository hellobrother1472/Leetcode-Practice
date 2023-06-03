#include <bits/stdc++.h>
using namespace std;

// If we draw the graph at paper or tree, we see that, we need the max of every level or max of every branch of headID node. We are taking max because let say A is taking 3 sec and B is taking 5 sec and they both are at same level, even if A completed in 3 sec, but B still have 2 sec remaining so total information transfer time will be max of both A and B which is 5.
// We perform DFS for this
// If want more explaination :- https://www.youtube.com/watch?v=zdBYi0p4L5Q
class Solution {
private:
    int dfs(int n, unordered_map<int,vector<int>>&mp, vector<int>& informTime,vector<int>&vis, int start){
        vis[start]++;
        int time = 0;
        for(int i = 0; i<mp[start].size(); i++){
            if(!vis[mp[start][i]]) time = max(dfs(n,mp,informTime,vis,mp[start][i]),time);
        }
        return informTime[start] + time;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>mp;
        for(int i = 0; i < manager.size(); i++){
            if(manager[i] != -1) mp[manager[i]].push_back(i);
        }
        vector<int>vis(n,0);
        return dfs(n,mp,informTime,vis,headID);
    }
};

// If we consider the point of view that if we store time taken to reach information to each node with that node in queue then it can be done through BFS also.
// With unordered map
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>mp;
        for(int i = 0; i < manager.size(); i++){
            if(manager[i] != -1) mp[manager[i]].push_back(i);
        }
        vector<int>vis(n,0);
        queue<pair<int,int>>q; // Node,time
        int ansTime = 0;
        q.push({headID,0});
        vis[headID] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int time = q.front().second;
            ansTime = max(time,ansTime);
            q.pop();
            for(int i = 0; i<mp[node].size(); i++){
                if(!vis[mp[node][i]]){
                    q.push({mp[node][i],(time+informTime[node])});
                    vis[mp[node][i]] = 1;
                }
            }
        }
        return ansTime;
    }
};

// Using vector
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>mp(n);
        for(int i = 0; i < manager.size(); i++){
            if(manager[i] != -1) mp[manager[i]].push_back(i);
        }
        vector<int>vis(n,0);
        queue<pair<int,int>>q; // Node,time
        int ansTime = 0;
        q.push({headID,0});
        vis[headID] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int time = q.front().second;
            ansTime = max(time,ansTime);
            q.pop();
            for(int i = 0; i<mp[node].size(); i++){
                if(!vis[mp[node][i]]){
                    q.push({mp[node][i],(time+informTime[node])});
                    vis[mp[node][i]] = 1;
                }
            }
        }
        return ansTime;
    }
};

int main(){

    return 0;
}