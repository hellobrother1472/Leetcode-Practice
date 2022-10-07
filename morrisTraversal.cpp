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

// Find the root's left right most element and connect it with root. After doing that go to left.
// If you found out that you have already pointed the pointer then remove it and print curr val.

class Solution {
public:
    vector<int> morrisTraversalInorder(TreeNode* root) {
        TreeNode*curr = root;
        vector<int>inorder;
        while(curr!=NULL){
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode*temp= curr->left;
                while(temp->right && temp->right != curr){
                    temp = temp->right;
                }

                if(temp->right == NULL){
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    temp->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};

class Solution {
public:
    vector<int> morrisTraversalPreorder(TreeNode* root) {
        TreeNode*curr = root;
        vector<int>preorder;
        while(curr!=NULL){
            if(curr->left == NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode*temp= curr->left;
                while(temp->right && temp->right != curr){
                    temp = temp->right;
                }

                if(temp->right == NULL){
                    temp->right = curr->right;
                    curr = curr->left;
                    preorder.push_back(curr->val);
                }
                else{
                    temp->right = NULL;
                    preorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};

int main()
{

    return 0;
}