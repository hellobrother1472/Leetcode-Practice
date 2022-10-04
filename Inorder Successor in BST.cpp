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

// Brut force meathod is simple just find the inorder traversal of tree and return the next element of num in inorder.

class Solution
{
public:
    void inorder(TreeNode *root, vector<TreeNode *> &ans)
    {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root);
        inorder(root->right, ans);
    }
    TreeNode *inOrderSuccessor(TreeNode *root, TreeNode *x)
    {
        vector<TreeNode *> ans;
        inorder(root, ans);
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == x && i < ans.size() - 1)
                return ans[i + 1];
        }
        return new TreeNode(-1);
    }
};

class Solution2
{
private:
    /* data */
public:
    TreeNode* inorderSuccesor(TreeNode *root, TreeNode* x)
    {
        TreeNode*curr = root;
        TreeNode*prev = NULL;
       while (curr && curr->val != x->val)
        {
            prev = curr;
            if (x->val > curr->val)
                curr = curr->right;
            else
                curr = curr->left;
        }

        if(curr->right == NULL && curr == prev->right){
            return new TreeNode(-1);
        }
        if(curr->right == NULL && curr == prev->left){
            return prev;
        }
        return root->right;
    }
};

int main()
{

    return 0;
}