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

// In this question we have given a target and we have to return the path to the path. For that the logic is that we first take a vector and add every element in it during the tarverse, and after that during the backtracking we check if we get the path or not. If we get then return true else pop that element out

class Solution
{
public:
    bool rsolve(TreeNode *root, vector<int> &ans, int target)
    {
        if (root == NULL)
        {
            return false;
        }
        ans.push_back(root->val);
        bool lt = rsolve(root->left, ans, target);
        bool rt = rsolve(root->right, ans, target);
        if (rt || lt || root->val == target) // If we get the element or someone from left or right is true (means it gets the element)
        {
            return true;
        }
        else
        {
            ans.pop_back();
        }
        return false;
    }
    vector<int> solve(TreeNode *A, int B)
    {
        vector<int> ans;
        rsolve(A, ans, B);
        return ans;
    }
};

int main()
{
    return 0;
}