#include <iostream>
#include <vector>
#include <algorithm>
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

// This is reccursive solution.
class Solution
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

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        solve(ans, 0, root);
        return ans;
    }
};

// Solution using queue
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);      // Push the root to the queue
        while (!q.empty()) // Until the queue is empty traverse
        {
            // make a vector level and push the val to take the value and store it in level and then push the left and right tree node of the present node and then perform same thing one by one.
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main()
{

    return 0;
}