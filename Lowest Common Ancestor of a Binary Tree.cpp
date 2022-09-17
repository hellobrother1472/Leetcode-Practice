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

// The logic behind this solution is that when you find the any of the required root return true. If both lt and rt is true then root is ans. If one tree gives true and another gives false and also root value matches the value of require one the the root is ans. If both sides gives false return false.
class Solution
{
public:
    TreeNode *ans;
    bool solve(TreeNode *root, int p, int q)
    {
        if (root == NULL)
        {
            return false;
        }
        bool lt = solve(root->left, p, q);
        bool rt = solve(root->right, p, q);
        if (root->val == p || root->val == q)
        {
            if (lt || rt)
            {
                ans = root;
            }
            return true;
        }
        if (lt && rt)
        {
            ans = root;
            return true;
        }
        if (!lt && !rt)
        {
            return false;
        }

        return true;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        solve(root, p->val, q->val);
        return ans;
    }
};

// Logic is simple, return the node itself rather than true. If we are getting the node from both sides then return that node. And similar type of concept.
class Solution2
{
public:
    
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root==NULL){
            return NULL;
        }
        if (root->val == p->val || root->val == q->val)
        {
            return root;
        }
        TreeNode*lt = lowestCommonAncestor(root->left,p,q);
        TreeNode*rt = lowestCommonAncestor(root->right,p,q);
        
        if(lt&&rt){
            return root;
        }
        if(root->val != p->val || root->val != q->val){
            if(lt){
                return lt;
            }
            if(rt){
                return rt;
            }
        }
        if(!lt&&!rt){
            return NULL;
        }
        return root;
    }
};

// Short version of above
class Solution3
{
public:
    
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root==NULL || root->val == p->val || root->val == q->val){
            return root;
        }
       
        TreeNode*lt = lowestCommonAncestor(root->left,p,q);
        TreeNode*rt = lowestCommonAncestor(root->right,p,q);
        if(!lt){
            return rt;
        }
        if(!rt){
            return lt;
        }
        return root;
    }
};
int main()
{

    return 0;
}