#include <iostream>
#include <vector>
#include <stack>

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

class Solution2
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);

            if (!st.empty())
                curr->right = st.top();

            curr->left = NULL;
        }
    }
};

class Solution3
{
public:
    TreeNode*prev = NULL;
    void flatten(TreeNode *root)
    {
        if(root==NULL){
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};


int main()
{

    return 0;
}