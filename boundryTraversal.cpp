#include <iostream>
#include <vector>
#include <stack>

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
    void leafNodes(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
            return;
        }
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
    }

    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {

        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        TreeNode *curr = root;

        // While loop for adding the left boundary
        while (curr->left != NULL || curr->right != NULL)
        {
            ans.push_back(curr->val);
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        // Getting the leaf nodes
        leafNodes(root, ans);

        // While loop for adding the right boundary here we have to get answer in reverse order so we will use stack
        curr = root->right;
        stack<int> st;
        while (curr->left != NULL || curr->right != NULL)
        {
            st.push(curr->val);
            if (curr->left != NULL)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main()
{

    return 0;
}