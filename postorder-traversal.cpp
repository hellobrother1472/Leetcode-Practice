#include <iostream>
#include <vector>
#include <stack>

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

// First Approach (Reccursion)

class Solution
{
public:
    void helper(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
        {
            return;
        }
        helper(root->left, v);
        helper(root->right, v);
        v.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

// Second Approach (Iterative Approach)

class Solution
{
public:
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        vector<int> vec;
        s1.push(root);
        while (!s1.empty())
        {
            root = s1.top();
            s1.pop();
            if (root->left != NULL)
            {
                s1.push(root->left);
            }
            if (root->right != NULL)
            {
                s1.push(root->right);
            }
            s2.push(root);
        }
        while (!s2.empty())
        {
            vec.push_back(s2.top()->val);
            s2.pop();
        }
        return vec;
    }
};

int main()
{

    return 0;
}