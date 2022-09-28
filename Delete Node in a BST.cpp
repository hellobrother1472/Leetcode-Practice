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
    TreeNode *findRightLast(TreeNode *root)
    {
        if (root->right == NULL)
        {
            return root;
        }
        return findRightLast(root->right);
    }

    TreeNode *helper(TreeNode*root){
        if(root->right == NULL){
            return root->left;
        }
        if(root->left == NULL){
            return root->right;
        }
        TreeNode*rightchild = root->right;
        TreeNode*lastRight = findRightLast(root->left);
        lastRight->right = rightchild;
        return root->left;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            return helper(root);
        }
        TreeNode*dummy = root;
        while(root != NULL){
            if(root->val>key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};

int main()
{

    return 0;
}