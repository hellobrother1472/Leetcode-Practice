#include <iostream>
#include <vector>
#include <map>

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
    TreeNode *helper(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &m)
    {
        if (postStart > postEnd || inStart > inEnd)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRoot = m[root->val];
        int inLeftSize = inRoot - inStart; // Getting the number of elements left in the left of root.
        root->left = helper(postorder, postStart, postStart + inLeftSize - 1, inorder, inStart, inRoot - 1, m);
        root->right = helper(postorder, postStart + inLeftSize, postEnd - 1, inorder, inRoot + 1, inEnd, m);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
        {
            return NULL;
        }

        map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }

        TreeNode *root = helper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, m);
        return root;
    }
};

int main()
{

    return 0;
}