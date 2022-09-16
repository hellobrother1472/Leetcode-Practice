#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int val;
};

// The logic is to get the last element of every column

// This is the reccursive way of doing it. For doing it with reccursion we need to include the concept of row to it also
class Solution
{
public:
    void solve(int row, int col, map<int, map<int, vector<int>>> &m, Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        m[col][row].push_back(root->val);
        solve(row + 1, col - 1, m, root->left);
        solve(row + 1, col + 1, m, root->right);
    }

    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        map<int, map<int, vector<int>>> m;
        solve(0, 0, m, root);
        for (auto i = m.begin(); i != m.end(); i++)
        {
            auto j = i->second.rbegin()->second;
            ans.push_back(j[j.size() - 1]);
        }

        return ans;
    }
};

// This is the iterative version here we are allowing to change the map value multiple time so that at last we can have the last value
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