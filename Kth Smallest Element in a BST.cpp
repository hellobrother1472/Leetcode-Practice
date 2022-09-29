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

// Inorder of any given binary search tree is always sorted.

class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &helper)
    {
        if (root == NULL)
            return;
        preorder(root->left, helper);
        helper.push_back(root->val);
        preorder(root->right, helper);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> helper;
        preorder(root, helper);
        return helper[k - 1];
    }
};

class Solution
{
public:
    int ans;
    int helper(TreeNode*root,int k,int count){
        if(root == NULL){
            return;
        }
        
        helper(root->left,k,count);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }        
        helper(root->right,k,count);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        helper(root,k,0);
        return ans;
    }
};

int main()
{

    return 0;
}