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
    bool solve(TreeNode *ans, TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return false;
        }
        bool lt = solve(ans, root->left, p, q);
        bool rt = solve(ans, root->right, p, q);
        if (lt && rt)
        {

            ans = root;
        }
        if (root->val == p->val || root->val == q->val)
        {
            cout << "Here";
            ans = root;
            cout << ans->val;
            return true;
        }
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = NULL;

        cout << solve(ans, root, p, q);
        return ans;
    }
};

int main()
{

    return 0;
}