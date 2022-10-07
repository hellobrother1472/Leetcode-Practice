#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    int i= -1;
    vector<int>inorderArr;
    
    void inorder(TreeNode*root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        inorderArr.push_back(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        i++;
        return inorderArr[i];
    }
    
    bool hasNext() {
        if(i+1 < inorderArr.size()){
            return true;
        }
        return false;
    }
};

// Using inorderSuccesor concept    
class BSTIterator {
public:
    TreeNode*r;
    TreeNode*curr;
    
    TreeNode * inorderSuccesor(TreeNode *root, TreeNode *x)
    {
        TreeNode *succesor = NULL;

        while (root)
        {
            if (root->val <= x->val)
            {
                root = root->right;
            }
            else
            {
                succesor = root;
                root = root->left;
            }
        }

        return succesor;
    }
    
    BSTIterator(TreeNode* root) {
        r = root;
        curr = root;
        while(curr->left){
            curr = curr->left;
        }
    }
    
    int next() {
        int ans = curr->val;
        curr = inorderSuccesor(r,curr);
        return ans;
    }
    
    bool hasNext() {
        if(curr){
            return true;
        }
        return false;
    }
};

int main(){
    

    return 0;
}