#include <bits/stdc++.h>
using namespace std;

// Traversing through reccursion and as we know that recurssion will go to the deep and complete before going on the right node. Here also we are maintaining the visited array (which in our case is visited map).

class Solution
{
private:
    void dfs(int start, unordered_map<int, int> &visited, vector<int> adj[], vector<int> &ans)
    {
        visited[start]++;
        ans.push_back(start);
        for (auto i : adj[start])
        {
            if (!visited[i])
                dfs(i, visited, adj, ans);
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        unordered_map<int, int> visited;
        int start = 0;
        dfs(start, visited, adj, ans);
        return ans;
    }
};

int main()
{

    return 0;
}