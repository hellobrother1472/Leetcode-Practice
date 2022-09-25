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

class Solution1
{
public:
    void calcPreorder(TreeNode *root, vector<int> &preorder)
    {
        if (root == NULL)
        {
            return;
        }
        preorder.push_back(root->val);
        calcPreorder(root->left, preorder);
        calcPreorder(root->right, preorder);
    }

    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        vector<int> preorder;
        calcPreorder(root, preorder);
        root->left = NULL;
        root->right = NULL;
        TreeNode *curr = root;
        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *node = new TreeNode(preorder[i]);
            curr->right = node;
            curr = curr->right;
        }
    }
};

int main()
{

    return 0;
}