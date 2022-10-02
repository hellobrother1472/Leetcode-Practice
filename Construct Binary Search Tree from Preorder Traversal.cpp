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
    TreeNode* helper(vector<int> preorder, int &i,int min, int max)
    {
        if (i == preorder.size() || preorder[i]<min || preorder[i]>max )
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[i]);
        i++;
        root->left = helper(preorder, i,min,root->val );
        root->right= helper(preorder, i,root->val,max );
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)    
    {
        TreeNode *root;
        int i = 0;
        if (preorder.size() == 1)
        {
            return new TreeNode(preorder[0]);
        }
        
        return helper(preorder,i,INT_MIN,INT_MAX);
    }
};

// Same solution
class Solution
{
public:
    TreeNode* helper(vector<int> preorder, int &i, int max)
    {
        if (i == preorder.size() || preorder[i]>max)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[i++]);        
        root->left = helper(preorder, i,root->val );
        root->right= helper(preorder, i,max );
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)    
    {
        TreeNode *root;
        int i = 0;
        if (preorder.size() == 1)
        {
            return new TreeNode(preorder[0]);
        }
        
        return helper(preorder,i,INT_MAX);
    }
};
int main()
{

    return 0;
}