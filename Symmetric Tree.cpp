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

// The idea is to check if we place mirror then it will be same for that we are checking left for right and right for left

class Solution
{
public:
    bool check(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL || q == NULL || p->val != q->val)
        {
            return false;
        }

        if (!check(p->left, q->right))
        {
            return false;
        }
        if (!check(p->right, q->left))
        {
            return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        return check(root->left, root->right);
    }
};

class Solution2
{
public:
    bool solve(TreeNode *l, TreeNode *r)
    {
        if (!l && !r)
            return true;
        else if (l && r && l->val == r->val)
        {
            return solve(l->left, r->right) && solve(l->right, r->left);
        }
        else
            return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        return solve(root->left, root->right);
    }
};

bool solve(TreeNode *root, vector<int>&ans, int target){
    if(root == NULL){
        return false;
    }
    ans.push_back(root->val);
    bool lt = solve(root->left,ans,target);
    bool rt = solve(root->right,ans,target);
    if(rt||lt||root->val == target){
        return true;
    }
    else{
        ans.pop_back();
    }
    return false;
}
int main()
{

    return 0;
}