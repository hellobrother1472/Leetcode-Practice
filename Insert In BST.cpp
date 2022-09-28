#include <iostream>
#include <vector>

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
    void solve(TreeNode *root, int val)
    {
        if (root == NULL)
            return;
        if (root->val <= val)
        {
            solve(root->right, val);
            if (root->right == NULL)
                root->right = new TreeNode(val);
        }
        else
        {
            solve(root->left, val);
            if (root->left == NULL)
                root->left = new TreeNode(val);
        }
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return new TreeNode(val);
        }
        solve(root, val);
        return root;
    }
};

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);

        TreeNode *curr = root;

        while (true)
        {
            if (curr->val <= val)
            {
                if (curr->right == NULL)
                {
                    curr->right = new TreeNode(val);
                    break;
                }
                curr = curr->right;
            }
            else
            {
                if (curr->left == NULL)
                {
                    curr->left = new TreeNode(val);
                    break;
                }
                curr = curr->left;
            }
        }

        return root;
    }
};

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);
        if (val > root->val)
            root->right = insertIntoBST(root->right, val); // Continue searching in the right subtree
        else
            root->left = insertIntoBST(root->left, val); // Continue searching in the left subtree
        return root;
    }
};

int main()
{

    return 0;
}