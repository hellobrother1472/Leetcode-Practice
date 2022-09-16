#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Logic is that we have to find the last element of the row/level so that we can get the right view (first for left).

class Solution
{
public:
    void solve(int level, vector<vector<int>> &ans, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (ans.size() <= level || ans.size() == 0)
        {
            vector<int> ds;
            ds.push_back(root->val);
            ans.push_back(ds);
        }
        else
        {
            // If level matches the already exist level ds then add to it the val
            ans[level].push_back(root->val);
        }
        solve(level + 1, ans, root->left);
        solve(level + 1, ans, root->right);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<vector<int>> ds;
        vector<int> ans;
        solve(0, ds, root);
        for (int i = 0; i < ds.size(); i++)
        {
            ans.push_back(ds[i][ds[i].size() - 1]);
        }

        return ans;
    }
};

class Solution
{
public:
    // In this we are getting the right first
    void solve(TreeNode *root, vector<int> &ans, int level)
    {
        if (!root)
            return;
        if (level == ans.size())
            ans.push_back(root->val);
        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

// Using map
class Solution
{
public:
    void solve(int level, map<int,int>&m, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        m[level] = root->val;
        solve(level + 1, m, root->left);
        solve(level + 1, m, root->right);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        map<int,int>m;
        vector<int> ans;
        solve(0, m, root);
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