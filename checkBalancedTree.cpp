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

class Solution
{
public:
    int count(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lt = count(root->left); // left tree
        if (lt == -1)
            return -1;
        int rt = count(root->right); // right tree

        if (rt == -1 || abs(lt - rt) > 1)
            return -1;

        return max(lt, rt) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (count(root) == -1)
        {
            return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}