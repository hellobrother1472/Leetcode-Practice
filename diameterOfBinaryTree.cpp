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
    int len = 0;
    int count(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = count(root->left);
        int rh = count(root->right);

        if (lh + rh > len)
        {
            len = lh + rh;
        }

        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {

        count(root);
        return len;
    }
};

int main()
{

    return 0;
}