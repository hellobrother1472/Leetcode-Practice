#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Using reccursion and map
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void solve(map<int, int> &m, int row, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL)
        { 
            m.emplace(row, root->val); // Emplace does not allow entry for the same key more than once. 
        }

        solve(m, row + 1, root->left);
        solve(m, row + 1, root->right);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        map<int, int> m;
        solve(m, 0, root);
        return m.rbegin()->second;
    }
};

// Using reccursive level Order
class Solution2
{
public:
    void solve(vector<vector<int>> &ans, int level, TreeNode *root)
    {
        // base case if root is null then no need to go further just return
        if (root == NULL)
        {
            return;
        }

        // if the index of level is not present in the ans array then make a ds vector and add the value to it and add it to the ans
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

        // Then go to left tree and do levelorder(BFS)
        if (root->left)
        {
            solve(ans, level + 1, root->left);
        }
        // Then go to right tree and do levelorder(BFS)
        if (root->right)
        {
            solve(ans, level + 1, root->right);
        }
    }
    int findBottomLeftValue(TreeNode *root)
    {
        vector<vector<int>> ans;
        solve(ans, 0, root);
        return ans[ans.size() - 1][0];
    }
};

// Using queue and the fastest
class Solution3
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        int ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                if (i == 0)
                    ans = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}