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
    int count;
    void countN(TreeNode*root){
        if(root == NULL){
            return;
        }
        count++;
        if(root->left){
            count++;
        }
        if(root->right){
            count++;
        }
        if(root->left && root->left->left){
            countN(root->left->left);
        }
        if(root->left && root->left->right){
            countN(root->left->right);
        }
        if(root->right && root->right->left){
            countN(root->right->left);
        }
        if(root->right && root->right->right){
            countN(root->right->right);
        }
    }

    int countNodes(TreeNode *root)
    {
        countN(root);
        return count;
    }
};

class Solution
{
public:
    int countLeftHeight(TreeNode*root){
        int h = 0;
        while (root)
        {
            h++;
            root = root->left;
        }
        return h;
    }

    int countRightHeight(TreeNode*root){
        int h = 0;
        while (root)
        {
            h++;
            root = root->right;
        }
        return h;
    }

    int countNodes(TreeNode *root)
    {
        if(root == NULL){
            return 0;
        }
        int lh = countLeftHeight(root->left);
        int rh = countRightHeight(root->right);

        if(lh == rh)return (2<<lh)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{

    return 0;
}