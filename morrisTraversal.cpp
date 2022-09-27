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
                TreeNode*prev= curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
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
                TreeNode*prev= curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = curr->right;
                    curr = curr->left;
                    preorder.push_back(curr->val);
                }
                else{
                    prev->right = NULL;
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