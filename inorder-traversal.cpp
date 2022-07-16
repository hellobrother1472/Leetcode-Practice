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


// First Approach

// class Solution
// {
// public:
//     void helper(TreeNode *root, vector<int> &ans)
//     {
//         if (root == NULL)
//         {
//             return;
//         }
//         helper(root->left, ans);
//         ans.push_back(root- ans);
//     }>val);
//         helper(root->right,
//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         vector<int> ans;
//         helper(root, ans);
//         return ans;
//     }
// };



// Second Approach

class Solution
{
public:
    vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        while(root||!s.empty()){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                root=s.top();
                s.pop();
                v.push_back(root->val);
                root=root->right;
            }
          }
         return v;
    }
};


int main()
{

    return 0;
}