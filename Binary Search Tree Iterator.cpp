#include <iostream>
#include <vector>
#include <stack>

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

class BSTIterator {
public:
    TreeNode*r;
    // TreeNode*curr;
    stack<TreeNode*>st;
    
    // On every next it will return ans and ready stack for next next() function.
    int inorderTraverse(TreeNode *root)
    {
        TreeNode* temp = st.top();
        int ans = temp->val;
        st.pop();
        if(temp->right != NULL){
            temp = temp->right;
            while (temp)
            {
                st.push(temp);
                temp = temp->left;
            }
            
        }
        return ans;
    }
    
    BSTIterator(TreeNode* root) {
        r = root;
        TreeNode*curr = root;
        // Making the stack ready by making first element of inorder at st.top()
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        return inorderTraverse(r);
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main(){
    

    return 0;
}