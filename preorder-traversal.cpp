#include <iostream>
#include <stack>
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


// First Approach (Using reccursion)

class Solution
{
public:
    void helper(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};


// Second Approach (Iterative using manual stack)

class Solution2
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s;
        if(root == nullptr){
            return ans;
        }
        s.push(root);
        while (!s.empty())
        {
            TreeNode *curr = s.top();
            ans.push_back(curr->val);
            s.pop();

            if(curr->right != nullptr){
                s.push(curr->right);
            }
            if(curr->left != nullptr){
                s.push(curr->left);
            }
        }
        
    }
};

int main()
{

    return 0;
}