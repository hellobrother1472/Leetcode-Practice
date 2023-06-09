#include <bits/stdc++.h>
using namespace std;

// After completion just add the elements into the stack.
class Solution
{
private:
    void dfs(int V, vector<int> adj[], vector<int> &vis, stack<int> &st, int start)
    {
        vis[start] = 1;
        for (auto node : adj[start])
        {
            if (!vis[node])
            {
                dfs(V, adj, vis, st, node);
            }
        }
        st.push(start);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(V, adj, vis, st, i);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// Kahn's algorithm : https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=22

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    vector<int>inDegree(V,0);
	    queue<int> q;
	    for(int i = 0 ; i < V; i++){
	        for(auto node:adj[i]) inDegree[node]++;
	    }
        
	    for(int i = 0 ; i < V; i++){
	        if(inDegree[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto val:adj[node]){
	            inDegree[val] --;
	            if(inDegree[val] == 0) q.push(val);
	        }
	    }
	    return ans;
	    
	}
};

int main()
{

    return 0;
}