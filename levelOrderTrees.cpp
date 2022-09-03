#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{

    return 0;
}