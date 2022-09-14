#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

// Reccursive top view using level order traversals
class Solution
{
public:
    void solve(int row, int col, map<int, map<int, vector<int>>> &m, Node *root)
    {
        if (root == NULL)
            return;

        if (m[col][row].size() == 0)
        {
            m[col][row].push_back(root->val);
        }

        solve(row + 1, col - 1, m, root->left);
        solve(row + 1, col + 1, m, root->right);
    }

    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int, map<int, vector<int>>> m;
        solve(0, 0, m, root);
        // After getting everything from the solve function we just put it in ans using iteration.We want the first value of the first row for the top view
        for (auto i = m.begin(); i != m.end(); i++)
        {
            ans.push_back(i->second.begin()->second[0]);
        }

        return ans;
    }
};

// Iterative top view using level order traversals
class Solution2
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<pair<Node *, int>> q;
        map<int, int> m;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *curr = it.first;
            int line = it.second;
            if (!m[line])
                m[line] = curr->val;
            if (curr->left != NULL)
                q.push({curr->left, line - 1});
            if (curr->right != NULL)
                q.push({curr->right, line + 1});
        }
        for (auto i = m.begin(); i != m.end(); i++)
        {
            ans.push_back(i->second);
        }
        return ans;
    }
};

int main()
{

    return 0;
}