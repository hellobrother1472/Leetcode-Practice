#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *ans;
    void helper(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->val == p->val || root->val == q->val)
        {
            ans = root;
            return;
        }
        if ((p->val > root->val && q->val < root->val) || (q->val > root->val && p->val < root->val))
        {
            ans = root;
            return;
        }
        if (p->val < root->val && q->val < root->val)
        {
            helper(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val)
        {
            helper(root->right, p, q);
        }
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        helper(root, p, q);
        return ans;
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return;
        while (root)
        {
            if (root->val == p->val || root->val == q->val)
            {
                return root;
            }
            if ((p->val > root->val && q->val < root->val) || (q->val > root->val && p->val < root->val))
            {
                return root;
            }
            if (p->val < root->val && q->val < root->val)
            {
                root = root->left;
            }
            if (p->val > root->val && q->val > root->val)
            {
                root = root->right;
            }
        }
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return;
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        // If we can figure out nothing then return root means one is on left and other is on right
        return root;
    }
};

int main()
{

    return 0;
}