#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

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
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL || root->left == NULL && root->right == NULL)
            return true;
        vector<int> ans;
        inorder(root, ans);
        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i - 1] >= ans[i])
                return false;
        }
        return true;
    }
};

// Here in this example we are maintaining the range for every node.
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (!recValid(root, LONG_MIN, LONG_MAX))
            return false;
        return true;
    }
    // takes pointer to root, the value of its parent and whether its a left or right child
    bool recValid(TreeNode *root, long min, long max)
    {
        // base case of if it is a leaf
        if (!root)
            return true;
        // returns false if it outside allotted range
        if (root->val >= max || root->val <= min)
            return false;
        // returns false if children break a rule, and also passes min or max and sets the other to the root val
        if (!recValid(root->left, min, root->val))
            return false;
        if (!recValid(root->right, root->val, max))
            return false;
        // if it recurses back without error it assumes true
        return true;
    }
};

int main()
{

    return 0;
}